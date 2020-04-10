#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np


# Create a null vector of size 10

# In[2]:


A=np.zeros(10)
print(A)


# Create a null vector of size 10 but the fifth value which is 1

# In[3]:


B=np.zeros(10,dtype=int)
B[4]=1
print(B)


# Create a vector with values ranging from 10 to 49

# In[4]:


C=np.arange(10,50)
print(C)


# Create a 3x3 matrix with values ranging from 0 to 8

# In[5]:


D=np.arange(0,9).reshape(3,3)
print(D)


# Create a 10x10 array with random values and find the minimum and maximum values

# In[6]:


E=np.random.random((10,10))
F=E.max()
G=E.min()
print(E)
print(F)
print(G)


# Create a 2d array with 1 on the border and 0 inside

# In[7]:


H=np.ones((4,4))
H[1:-1,1:-1]=0
print(H)


# Multiply a 5x3 matrix by a 3x2 matrix (real matrix product) 

# In[8]:


I=np.arange(15).reshape(5,3)
J=np.arange(6).reshape(3,2)
K=I.dot(J)
print(I)
print(J)
print(K)

