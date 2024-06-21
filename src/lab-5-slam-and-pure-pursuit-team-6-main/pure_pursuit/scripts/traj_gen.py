import numpy as np
from scipy.interpolate import splprep, splev
import matplotlib.pyplot as plt

def rotate_left(lst, i=1):
    return np.hstack((lst[i:],lst[:i]))

# 示例数据：一系列三维点
h_s = 8
m_s = 6
l_s = 4
x = np.array([10.6, 11.1, 9.5, 7.5, 6.2, 8.2, 7.5, 5.8,  4.4,  6.0,  7.5, 8.3])
y = np.array([ 4.0,  6.3, 8.0, 9.0, 7.3, 5.7, 3.5, 1.2, -1.6, -2.7, -1.0, 0.4])
z = np.array([ m_s,  l_s, m_s, l_s, l_s, m_s, m_s, m_s,  l_s,  l_s,  m_s, h_s])

# # 曲线拟合
# x = rotate_left(x)
# y = rotate_left(y)
# z = rotate_left(z)
# # 曲线拟合
# x = rotate_left(x)
# y = rotate_left(y)
# z = rotate_left(z)
# 确保曲线闭合
if not (x[0], y[0], z[0]) == (x[-1], y[-1], z[-1]):
    x_ = np.append(x, x[0])
    y_ = np.append(y, y[0])
    z_ = np.append(z, z[0])
curve = [x_,y_,z_]
tck, _ = splprep(curve, s=3)
print(tck)

# 插值到一定数目的点，这里以200为例
new_points = np.array(splev(np.linspace(0, 1, 100), tck))

# 绘制原始点
plt.figure()
plt.scatter(x, y, c=z, cmap='viridis', marker='o')  # 使用散点图表示原始点

# 绘制拟合后的二维曲线，使用线条颜色表示z值
# 因为scatter不支持连续线条，我们使用plot绘制二维曲线，并用scatter绘制颜色代表z值的点
plt.plot(new_points[0], new_points[1], 'k-', alpha=0.5)  # 绘制二维曲线
points = plt.scatter(new_points[0], new_points[1], c=new_points[2], cmap='viridis', s=10)  # 点的颜色表示z值
plt.colorbar(points, label='Z value')  # 添加颜色条

plt.xlabel('X')
plt.ylabel('Y')
plt.title('2D Curve with Z Value Represented by Color')
plt.show()

new_points = new_points.T
points_length = new_points.shape[0]
yaws = np.zeros((points_length, 1))
for i in range(points_length + 1):
    curr_point = new_points[i % points_length, 0:2]
    prev_point = new_points[(i - 1) % points_length, 0:2]
    yaws[i % points_length] = np.arctan2(curr_point[1] - prev_point[1], curr_point[0] - prev_point[0])
new_points = np.hstack((new_points, yaws))
print(new_points.shape)

csvfile = '/home/lucien/ESE6150/traj_map.csv'
np.savetxt(csvfile, new_points, delimiter=",")

