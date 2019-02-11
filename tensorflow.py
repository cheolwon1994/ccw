
# coding: utf-8

# In[31]:


import tensorflow as tf
import numpy as np
from pandas.io.parsers import read_csv
import json
import csv
 
with open('test.sdcl', encoding="utf-8") as data_file:    
    data2 = json.load(data_file)

model = tf.global_variables_initializer()
data = read_csv('Yechan_1.updown 2019-02-01 14_29_35.csv',sep=',')



# In[6]:


for d4 in data2['DetectedSegments']:
    print(d4)


# In[29]:


for d in data2['DetectedSegments']:
    a= d['SegmentWindow']['StartSample']
    b = d['SegmentWindow']['EndSample']
    print("<" + str(a)+", "+ str(b)+">")

    for d5 in d['LabelData']:
        c = d5['value']
        e = d5['name']
        if 'Label' == str(e) :
            print(c)
    
#     print(d['SegmentWindow'])
#     print(d['SegmentWindow']['StartSample'])
#     print(d['SegmentWindow']['EndSample'])
    print()

    
    


# In[56]:


f = open('output.csv', 'w', encoding='utf-8', newline='')
csv_writer = csv.writer(f) 
csv_writer.writerow(['','AccelerometerX','AccelerometerY','AccelerometerZ','GyroscopeX','GyroscopeY','GyroscopeZ','Label','SegmentID','Subject'])
j=0
for d in data2['DetectedSegments']:
    a= d['SegmentWindow']['StartSample']
    b = d['SegmentWindow']['EndSample']
#    print("<" + str(a)+", "+ str(b)+">")
    for d5 in d['LabelData']:
        c = d5['value']
        e = d5['name']
        if 'Label' == str(e) :
            g = c
    for i in range(0,14000) :
        if data.sequence[i]>b :
            break
        elif a<=data.sequence[i] :
            csv_writer.writerow([j,data.AccelerometerX[i],data.AccelerometerY[i],data.AccelerometerZ[i],data.GyroscopeX[i],data.GyroscopeY[i],data.GyroscopeZ[i],g,5,'CW'])
#            print(data.AccelerometerX[i],data.AccelerometerY[i],data.AccelerometerZ[i],data.GyroscopeX[i],data.GyroscopeY[i],data.GyroscopeZ[i])
            j+=1
#    print("==============================================================")
f.close()

    

