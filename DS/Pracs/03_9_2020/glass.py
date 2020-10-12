#!/usr/bin/env python
# coding: utf-8

# In[43]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# In[60]:


data = pd.read_csv("glass.csv")


# In[61]:


data.columns


# In[62]:


print(len(data.columns))


# In[63]:


data.head


# In[64]:


data.head(5)


# In[65]:


data.describe()


# In[66]:


data.Type.unique()


# In[67]:


data.groupby('Type').groups


# In[68]:


grouped = data.groupby('Type')
for col,group in grouped:
    print(col)
    print(group)


# In[69]:


for group in grouped:
    print(group[0])
    print(group[1].agg([np.sum, np.mean, np.std]),end = '\n\n\n')


# In[70]:



data.sort_values(['Type', 'Ca', 'Mg', 'Na'],ascending=[True, False, False, False]).head()


# In[73]:


data = data[['Ca', 'Mg', 'Na', 'Si', 'K', 'Al', 'RI', 'Ba', 'Fe', 'Type']]
data.head()


# In[74]:


data.describe()


# In[83]:


grouped = data.groupby('Type')
for group in grouped:
    print(group)
    print(group[1].agg([np.sum, np.mean, np.std]),end = '\n\n\n')


# In[ ]:




