import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('Graph_list - Graph_list 1.csv')

longitudes = df['source_long'].values
latitudes = df['source_lat'].values
source_name = df['source_name'].values
list1 = []
list2 = []
for i in range(len(longitudes)):
    
    if longitudes[i][6] == '″':
        degrees = int(longitudes[i][0])
        minutes = int(longitudes[i][2:4])
        seconds = int(longitudes[i][5])
        longitude_value = degrees + minutes / 60 + seconds / 3600
        list1.append(longitude_value)
    else:
        degrees = int(longitudes[i][0])
        minutes = int(longitudes[i][2:4])
        seconds = int(longitudes[i][5:7])
        longitude_value = degrees + minutes / 60 + seconds / 3600
        list1.append(longitude_value)
    
for i in range(len(latitudes)):
    
    degrees = int(latitudes[i][0:2])
    minutes = int(latitudes[i][3:5])
    seconds = int(latitudes[i][6:8])
    latitudes_value = degrees + minutes / 60 + seconds / 3600
    list2.append(latitudes_value)

plt.plot(list1, list2)

# 添加标签
for i in range(len(list1)):
    plt.text(list1[i], list2[i], source_name[i], fontsize=8, ha='center', va='center')

# 设置坐标轴标签
plt.xlabel('longitudes')
plt.ylabel('latitudes')

# 显示图形
plt.show()
