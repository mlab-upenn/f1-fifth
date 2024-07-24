import matplotlib.pyplot as plt    
import numpy as np
import pandas as pd



def compute_boundary(x, y, offset):

    dx = np.diff(x, prepend=x[0])
    dy = np.diff(y, prepend=y[0])
    length = np.sqrt(dx**2 + dy**2)
    dx /= length
    dy /= length
    offset_x = -dy * offset
    offset_y = dx * offset
    return x + offset_x, y + offset_y

track_name = "l_shape_centerline_fifth.csv"
racetrack_data = pd.read_csv(track_name, delimiter=',')
racetrack_data.columns = ['x_m', 'y_m', 'left_dist_m', 'right_dist_m']
print(racetrack_data.head(10))
left_x, left_y = compute_boundary(racetrack_data['x_m'], racetrack_data['y_m'], racetrack_data['left_dist_m'])
right_x, right_y = compute_boundary(racetrack_data['x_m'], racetrack_data['y_m'], -racetrack_data['right_dist_m'])



# Plotting the racetrack centerline and boundaries
plt.style.use('dark_background')
plt.figure(figsize=(12, 8))
plt.plot(racetrack_data['x_m'], racetrack_data['y_m'], label='Track Centerline', color='blue')
plt.plot(left_x, left_y, label='Left Boundary', color='red')
plt.plot(right_x, right_y, label='Right Boundary', color='red')
plt.xlabel('X Coordinate (m)')
plt.ylabel('Y Coordinate (m)')
plt.title('Racetrack ' + track_name)
plt.grid(True)
plt.legend()
plt.axis('equal')
plt.show()