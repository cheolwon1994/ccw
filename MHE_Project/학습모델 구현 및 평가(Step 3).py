
# coding: utf-8

# In[158]:

#학습시킬 csv파일          : aaaaaaaaa.csv
#학습모델을 test할 csv파일 : bbbbbbbbb.csv

import tensorflow as tf
import numpy as np
from pandas.io.parsers import read_csv
import json
import csv
from sklearn.utils import shuffle

data2=read_csv('bbbbbbbbb.csv',sep=',')
data3=read_csv('aaaaaaaaa.csv',sep=',')
data3_shuffle = shuffle(data3)


# In[165]:


xy2 = np.array(data2,dtype=np.float32)
x_data2 = (xy2[:,1:19])
y_data2 = (xy2[:,19:])


# In[189]:


xy = np.array(data3_shuffle,dtype=np.float32)
#x_data : x,y,z,자이로x,자이로y,자이로z 각각의 Q1, Q2, Q3
#y_data : Label1~4값
x_data = (xy[:,1:19])
y_data = (xy[:,19:])

X=tf.placeholder('float',[None,18])
Y=tf.placeholder('float',[None,4])

#Label : 0~3
nb_labels = 4
W = tf.Variable(tf.zeros([18,nb_labels]), name="weight")
b = tf.Variable(tf.random_normal([nb_labels]), name="bias")

scores = tf.matmul(X, W)+b
hypothesis = tf.nn.softmax(scores)
cost = tf.reduce_mean(-tf.reduce_sum(Y*tf.log(hypothesis),reduction_indices=1))

optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.00000001).minimize(cost)

#예측을 위한 연산
prediction = tf.argmax(hypothesis, 1)
prediction_corrected = tf.equal(prediction, tf.argmax(Y,1))
accuracy = tf.reduce_mean(tf.cast(prediction_corrected, tf.float32))

#학습시키는 과정
init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    for step in range(10001):
        sess.run(optimizer, feed_dict={X:x_data, Y:y_data})
        if step % 1000 == 0:
            loss, acc = sess.run([cost, accuracy], feed_dict={X: x_data,Y: y_data})
            print(f'STEP = {step:05}, Loss = {loss:.3f}, 정확도 = {acc:.3%}')

# prediction 0,1,2,3 순서대로 32개씩
    all,pred = sess.run([hypothesis,accuracy], feed_dict={X: x_data2, Y: y_data2})
    print(f'예측 결과 = {all}\n ONE-HOT 인코딩 결과 =\n {sess.run(tf.argmax(all, 1))}\n 정확도 = {pred*100}%\n')

    print(f'W값 = {sess.run(W)} \nb값 = {sess.run(b)}')

