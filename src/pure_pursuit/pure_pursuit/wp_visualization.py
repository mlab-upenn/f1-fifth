import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import pandas as pd


waypoints = pd.read_csv('wp.csv', delimiter=',')
waypoints.columns = ['x', 'y', 'z', 'v']
print(waypoints.head(10))

x_coords = waypoints['x'].astype(float)
y_coords = waypoints['y'].astype(float)
z_coords = waypoints['z'].astype(float)
velocity = waypoints['v'].astype(float)
norm = plt.Normalize(velocity.min(), velocity.max())
cmap = plt.get_cmap('viridis')

# 2D plot:
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
sc = plt.scatter(x_coords, y_coords, c=velocity, cmap=cmap, norm=norm, marker='o')
plt.title('2D Waypoints Visualization')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.colorbar(sc, label='Velocity')
plt.grid(True)

# 3D plot:
ax = plt.subplot(1, 2, 2, projection='3d')
sc = ax.scatter(x_coords, y_coords, z_coords, c=velocity, cmap=cmap, norm=norm, marker='o')
ax.set_title('3D Waypoints Visualization')
ax.set_xlabel('X Coordinate')
ax.set_ylabel('Y Coordinate')
ax.set_zlabel('Z Coordinate')
plt.colorbar(sc, label='Velocity')
plt.tight_layout()
plt.show()
plt.savefig('waypoints.png')
