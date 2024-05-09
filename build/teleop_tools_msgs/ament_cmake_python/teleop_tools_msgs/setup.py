from setuptools import find_packages
from setuptools import setup

setup(
    name='teleop_tools_msgs',
    version='1.2.1',
    packages=find_packages(
        include=('teleop_tools_msgs', 'teleop_tools_msgs.*')),
)
