from setuptools import find_packages
from setuptools import setup

setup(
    name='ouster_sensor_msgs',
    version='0.12.2',
    packages=find_packages(
        include=('ouster_sensor_msgs', 'ouster_sensor_msgs.*')),
)
