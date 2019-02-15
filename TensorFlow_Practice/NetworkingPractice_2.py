
# coding: utf-8

# In[1]:


import tensorflow as tf
import numpy as np
from tqdm import tqdm_notebook
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


# In[2]:


tf.set_random_seed(777)


# In[3]:


x_data = [[0,0],[0,1],[1,0],[1,1]]
y_data = [[0],[0],[0],[1]]

x_data = np.array(x_data, dtype = np.float32)
y_data = np.array(y_data, dtype = np.float32)


# In[4]:


X = tf.placeholder(tf.float32,[None,2], name = 'x-input')
Y = tf.placeholder(tf.float32,[None,1], name = 'y-input')

W = tf.Variable(tf.random_normal([2,1]),name = 'weight')
b= tf.Variable(tf.random_normal([1]),name='bias')

hypothesis = tf.sigmoid(tf.matmul(X,W)+b)


# In[5]:


W_history = []
cost_history=[]
b_history=[]

cost = -tf.reduce_mean(Y*tf.log(hypothesis)+(1-Y)*tf.log(1-hypothesis))
train = tf.train.GradientDescentOptimizer(learning_rate=0.01).minimize(cost)


# In[6]:


predicted = tf.cast(hypothesis > 0.5, dtype = tf.float32)
accuracy = tf.reduce_mean(tf.cast(tf.equal(predicted,Y),dtype=tf.float32))


# In[10]:


#launch graph
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    
    for step in tqdm_notebook(range(10001)):
        sess.run(train, feed_dict = {X :x_data, Y: y_data})
        
        W_history.append(sess.run(W))
        b_history.append(sess.run(b))
        cost_history.append(sess.run(cost, feed_dict = {X: x_data, Y: y_data}))
        
    #Accuracy report
    h,c,a = sess.run([hypothesis, predicted, accuracy], feed_dict = {X: x_data, Y: y_data})
    print("\nHypothesis: ",h,"\nCorrect: ",c,"\nAccuracy: ",a)


# In[11]:


#show the cost function
plt.figure(figsize=[12,6])
plt.plot(cost_history)
plt.grid()
plt.show()

