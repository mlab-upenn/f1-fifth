from setuptools import find_packages
from setuptools import setup

setup(
    name='vesc_msgs',
    version='1.2.0',
    packages=find_packages(
        include=('vesc_msgs', 'vesc_msgs.*')),
)
