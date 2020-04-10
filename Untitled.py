#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as ad
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt


# In[9]:


import seaborn as sns
data = sns.load_dataset("iris")
data.head()


# In[11]:


plt.rcParams['font.sans-serif']=['SimHei']
plt.rcParams['axes.unicode_minus']=False


# In[12]:


data['sepal_size']=data['sepal_length']*data['sepal_width']
data['petal_size']=data['petal_length']*data['petal_width']
plt.scatter(data['sepal_size'],data['petal_size'])
plt.xlabel('sepal_size')
plt.ylabel('petal_size')
plt.title('Size relationship between sepal and petal (scatter diagram)')
plt.show()


# In[31]:


color_data=['blue','green','red']
species=['versicolor','virginica','setosa']


# In[38]:


for i in range(0,3):
    plt.scatter(data['sepal_size'][data['species']==species[i]],data['petal_size'][data['species']==species[i]],
               color=color_data[i],label=species[i])
plt.legend(loc='best')
plt.xlabel('sepal_size')
plt.xlabel('petal_size')
plt.title('The size relationship between sepals and petals of iris of different species')
plt.show()


# In[17]:


data['species'].value_counts()


# Distribution of sepals and petal sizes of different Iris species (box diagram)

# In[83]:


plt.boxplot(data['sepal_size'],patch_artist=True,showmeans=True,
        showfliers=True,boxprops={'color':'black','facecolor':'blue'},flierprops={'marker':'o','markerfacecolor':'red','markersize':5},
        meanprops={'marker':'D','markerfacecolor':'indianred','markersize':4},medianprops={'linestyle':'--','color':'orange'})
plt.show()

