
# coding: utf-8

# In[62]:


import tensorflow as tf
import numpy as np
from pandas.io.parsers import read_csv
import json
import csv
import pandas as pd
from operator import eq

model = tf.global_variables_initializer()
data = pd.read_csv('ForTest.csv',sep=',')

df2 = data[["AccelerometerX", "AccelerometerY", "AccelerometerZ","GyroscopeX", "GyroscopeY", "GyroscopeZ","Label","SegmentID"]]
df3 = data[["AccelerometerX", "AccelerometerY", "AccelerometerZ","GyroscopeX", "GyroscopeY", "GyroscopeZ"]]
#print(df2)
xy2 = np.array(df2[0:]["AccelerometerX"],dtype=np.float32)
xy3 = np.array(df2[0:]["AccelerometerY"],dtype=np.float32)
xy4 = np.array(df2[0:]["AccelerometerZ"],dtype=np.float32)
xy5 = np.array(df2[0:]["GyroscopeX"],dtype=np.float32)
xy6 = np.array(df2[0:]["GyroscopeY"],dtype=np.float32)
xy7 = np.array(df2[0:]["GyroscopeZ"],dtype=np.float32)

print(np.percentile(xy3[0:100],25))


# In[63]:


j=0
k=0
total=0
total2=0
total3=0
total4=0
total5=0
total6=0

f = open('TestingSet.csv', 'w', encoding='utf-8', newline='')
csv_writer = csv.writer(f)
csv_writer.writerow(['','AccelerometerX25','AccelerometerY25','AccelerometerZ25','GyroscopeX25','GyroscopeY25','GyroscopeZ25','AccelerometerX50','AccelerometerY50','AccelerometerZ50','GyroscopeX50','GyroscopeY50','GyroscopeZ50','AccelerometerX75','AccelerometerY75','AccelerometerZ75','GyroscopeX75','GyroscopeY75','GyroscopeZ75','Label1','Label2','Label3','Label4'])

for d in df2["SegmentID"] :
    dd =(df2["Label"][j].split('.')[0])
    if eq(dd,"1"):
        dd1=1
        dd2=0
        dd3=0
        dd4=0
    elif eq(dd,"2") :
        dd1=0
        dd2=1
        dd3=0
        dd4=0
    elif eq(dd,"3") :
        dd1=0
        dd2=0
        dd3=1
        dd4=0
    elif eq(dd,"4") :
        dd1=0
        dd2=0
        dd3=0
        dd4=1
        
    if d == 2 :
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        
        j+=1
        if j%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
    elif d==3 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==4 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==5 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==6 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==7 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==8 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
    elif d==9 :
        if df2["SegmentID"][j-1]!=d :
            print("=================================================")
            start = j
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
            
        total +=df2["AccelerometerX"][j]
        total2+=df2["AccelerometerY"][j]
        total3+=df2["AccelerometerZ"][j]
        total4+=df2["GyroscopeX"][j]
        total5+=df2["GyroscopeY"][j]
        total6+=df2["GyroscopeZ"][j]
        j+=1
        if (j-start)%100 ==0 :
            csv_writer.writerow([k,np.percentile(xy2[j-100:j],25),np.percentile(xy3[j-100:j],25),np.percentile(xy4[j-100:j],25),np.percentile(xy5[j-100:j],25),np.percentile(xy6[j-100:j],25),np.percentile(xy7[j-100:j],25),total/100,total2/100,total3/100,total4/100, total5/100, total6/100,np.percentile(xy2[j-100:j],75),np.percentile(xy3[j-100:j],75),np.percentile(xy4[j-100:j],75),np.percentile(xy5[j-100:j],75),np.percentile(xy6[j-100:j],75),np.percentile(xy7[j-100:j],75),dd1,dd2,dd3,dd4])
            k+=1
            print(total/100, total2/100, total3/100, total4/100, total5/100, total6/100)
            total =0
            total2 =0
            total3 =0
            total4 =0
            total5 =0
            total6 =0
f.close()
        
print(j)

