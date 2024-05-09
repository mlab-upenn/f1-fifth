from setuptools import find_packages
from setuptools import setup

setup(
    name='fixposition_driver_ros2',
    version='5.0.0',
    packages=find_packages(
        include=('fixposition_driver_ros2', 'fixposition_driver_ros2.*')),
)
