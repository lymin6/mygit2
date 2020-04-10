#!/usr/bin/env python
# coding: utf-8

# In[27]:


import pandas as pd


# In[28]:


import numpy as np


# In[29]:


data = {'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
        'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
        'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
        'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']}

labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']


# Create df with labels as index

# In[30]:


df=pd.DataFrame(data,index=labels)


# Show df basic information and its data

# In[31]:


print(df)


# Select only the 'animal' and 'age' columns

# In[32]:


print(df.loc[:,['animal','age']])


# Select the row with missing value

# In[33]:


print(df.isnull().T.any())


# Sort DF in descending age and ascending visits order

# In[34]:


print(df.sort_values(by=['age','visits'],ascending=[False,True]))


# In the 'animal' column, replace 'snake' with 'Python'

# In[35]:


df['animal']=df['animal'].replace('snake','Python')
print(df)

