#!/usr/bin/env python3
import csv
import numpy as np
from scipy.interpolate import splprep, splev
import os
import csv

# Define the file path and name
filename = "/home/lee/work/f1/sim_ws/src/lab-5-slam-and-pure-pursuit-team-6/pure_pursuit/waypoints/waypoints.csv"
# directory = os.path.dirname(filename)

# if not os.path.exists(directory):
#     os.makedirs(directory)


# Define key points (x, y)
corner_points = np.array([
    [0.806, -0.859],   # Corner 1
    [8.34, -5.12],   # Corner 2
    [22.36, 13.65],    # Corner 3
    [14.74, 19.09]    # Corner 4
])

## Number of waypoints desired along each edge
num_points_per_edge = 25

# Function to linearly interpolate between two points
def interpolate_line(point_a, point_b, num_points):
    return np.linspace(point_a, point_b, num_points)

# Prepare list to hold all waypoints
waypoints = []

# Generate waypoints for each edge of the rectangle
for i in range(len(corner_points)):
    start_point = corner_points[i]
    end_point = corner_points[(i + 1) % len(corner_points)]  # Wrap around to the first point
    # Interpolate between the two points
    for point in interpolate_line(start_point, end_point, num_points_per_edge):
        print(point)
        waypoints.append(point)

# Remove duplicate of the last point which is same as the first
waypoints = waypoints[:-1]

# Save to CSV
with open(filename, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["x", "y"])  # Column headers
    for waypoint in waypoints:
        writer.writerow(waypoint)