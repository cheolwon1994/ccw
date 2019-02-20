
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
from sklearn.metrics import confusion_matrix
from scipy import ndimage
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


data2=read_csv('aaaaaaaaa.csv',sep=',')         #test set1
data4=read_csv('bbbbbbbbb.csv',sep=',')         #test set2
data5=read_csv('ccccccccc.csv',sep=',')         #test set3
data6=read_csv('aaaaaaaaa.csv',sep=',')         #test set4
data7=read_csv('aaaaaaaaa.csv',sep=',')         #test set5

data3=read_csv('eeeeeeeee.csv',sep=',')         #training set
data3_shuffle = shuffle(data3)


# In[165]:


xy2 = np.array(data2,dtype=np.float32)
x_data2 = (xy2[:,1:7])
y_data2 = (xy2[:,7:])


k=0
y_data3 = np.arange(y_data2.shape[0])
for i in y_data2 :
    if i[0]==1 :
        y_data3[k]=1
        k+=1
    elif i[1]==1:
        y_data3[k]=2
        k+=1
    elif i[2]==1 :
        y_data3[k]=3
        k+=1
    else  :
        y_data3[k]=4
        k+=1
        

xy4 = np.array(data4,dtype=np.float32)
x_data4 = (xy4[:,1:7])
y_data4 = (xy4[:,7:])

k=0
y_data4_1 = np.arange(y_data4.shape[0])
for i in y_data4 :
    if i[0]==1 :
        y_data4_1[k]=1
        k+=1
    elif i[1]==1:
        y_data4_1[k]=2
        k+=1
    elif i[2]==1 :
        y_data4_1[k]=3
        k+=1
    else  :
        y_data4_1[k]=4
        k+=1
        
        
xy5 = np.array(data5,dtype=np.float32)
x_data5 = (xy5[:,1:7])
y_data5 = (xy5[:,7:])

k=0
y_data5_1 = np.arange(y_data5.shape[0])
for i in y_data5 :
    if i[0]==1 :
        y_data5_1[k]=1
        k+=1
    elif i[1]==1:
        y_data5_1[k]=2
        k+=1
    elif i[2]==1 :
        y_data5_1[k]=3
        k+=1
    else  :
        y_data5_1[k]=4
        k+=1
        

xy6 = np.array(data6,dtype=np.float32)
x_data6 = (xy6[:,1:7])
y_data6 = (xy6[:,7:])

k=0
y_data6_1 = np.arange(y_data6.shape[0])
for i in y_data6 :
    if i[0]==1 :
        y_data6_1[k]=1
        k+=1
    elif i[1]==1:
        y_data6_1[k]=2
        k+=1
    elif i[2]==1 :
        y_data6_1[k]=3
        k+=1
    else  :
        y_data6_1[k]=4
        k+=1
        
        
xy7 = np.array(data7,dtype=np.float32)
x_data7 = (xy7[:,1:7])
y_data7 = (xy7[:,7:])

k=0
y_data7_1 = np.arange(y_data7.shape[0])
for i in y_data7 :
    if i[0]==1 :
        y_data7_1[k]=1
        k+=1
    elif i[1]==1:
        y_data7_1[k]=2
        k+=1
    elif i[2]==1 :
        y_data7_1[k]=3
        k+=1
    else  :
        y_data7_1[k]=4
        k+=1


# In[189]:


xy = np.array(data3_shuffle,dtype=np.float32)
#x_data : 자이로X25,자이로Y25,자이로Z25, 자이로Z50,자이로X75,자이로Z75
#y_data : Label1~4값
x_data = (xy[:,1:7])
y_data = (xy[:,7:])

X=tf.placeholder('float',[None,6])
Y=tf.placeholder('float',[None,4])

#Label : 0~3
nb_labels = 4
W = tf.Variable(tf.zeros([6,nb_labels]), name="weight")
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
    dd = sess.run(tf.argmax(all,1))
    
    all4,pred4 = sess.run([hypothesis,accuracy], feed_dict={X: x_data4, Y: y_data4})
    dd4 = sess.run(tf.argmax(all4,1))
    
    all5,pred5 = sess.run([hypothesis,accuracy], feed_dict={X: x_data5, Y: y_data5})
    dd5 = sess.run(tf.argmax(all5,1))
    
    all6,pred6 = sess.run([hypothesis,accuracy], feed_dict={X: x_data6, Y: y_data6})
    dd6 = sess.run(tf.argmax(all6,1))
    
    all7,pred7 = sess.run([hypothesis,accuracy], feed_dict={X: x_data7, Y: y_data7})
    dd7 = sess.run(tf.argmax(all7,1))
    
    #test를 넣었을 때, 학습모델의 예측결과와 정확도
    #print(f'예측 결과 = {all}\n')
    #print(f'ONE-HOT 인코딩 결과 =\n {dd}\n')
    print(f'aa 정확도 = {pred*100}%\n')
    print(f'bb 정확도 = {pred4*100}%\n')
    print(f'cc 정확도 = {pred5*100}%\n')
    print(f'dd 정확도 = {pred6*100}%\n')
    print(f'ee 정확도 = {pred7*100}%\n')
    #가중치 및 bias 출력
    #print(f'W값 = {sess.run(W)}\nb값 = {sess.run(b)}\n')
    #confusion_matrix 출력
    print(f'aa = \n{confusion_matrix(y_data3,dd)}')
    print(f'bb = \n{confusion_matrix(y_data4_1,dd4)}')
    print(f'cc = \n{confusion_matrix(y_data5_1,dd5)}')
    print(f'dd = \n{confusion_matrix(y_data6_1,dd6)}')
    print(f'ee = \n{confusion_matrix(y_data7_1,dd7)}')
        

