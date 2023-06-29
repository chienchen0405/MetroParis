import pandas as pd
import folium
from folium.plugins import MousePosition

df = pd.read_csv('metroparis - test.csv')


cur_Geo_Point = df['cur_Geo Point'].values
cur_name = df['cur_name'].values
numeric_list = [[float(coord) for coord in item.split(',')] for item in cur_Geo_Point]

    
line_one = numeric_list[:24]
line_two = numeric_list[25:72]
line_three = numeric_list[73:]

cur_name_one = cur_name[:24]
cur_name_two = cur_name[25:72]
cur_name_three = cur_name[73:]

# 创建地图对象
map = folium.Map(location=[48.866111, 2.276667], zoom_start=14)

# 绘制地铁线路
line_coordinates = [
    {
     'coordinates':line_one,
     'color': 'red',
     'comments':cur_name_one
     },
    {
     'coordinates':line_two,
     'color': 'blue',
     'comments':cur_name_two
     },
    {
     'coordinates':line_three,
     'color': 'green',
     'comments':cur_name_three
     },
  
    ]



# 绘制线路并添加注释
for line in line_coordinates:
    coordinates = line['coordinates']
    comments = line['comments']
    color = line['color']
    
    for i in range(len(coordinates)):
        coordinate = coordinates[i]
        comment = comments[i]
        
        folium.Marker(location=coordinate, icon=folium.Icon(color=color)).add_child(folium.Tooltip(comment)).add_to(map)
    
    folium.PolyLine(locations=coordinates, color=color, weight=3).add_to(map)

# 添加鼠标位置插件
MousePosition().add_to(map)

# 在浏览器中显示地图
map.save('map.html')





