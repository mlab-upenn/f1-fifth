# f1-fifth

This repository is the software stack for F1/5th off-road robot, Cinnamon! 
Please check src folder to see all the modules I have.
We are using Ubuntu 22.04, ROS2 Humble, and Jetpack 6.0.
We tested on NVIDIA Jetson Orin Nano and Orin AGX.
We recommend flasing Jetson on SSD. Choose NVMe on SDK manager when flashing. (I forgot which step it was but it was on the bottom right on the screen.)

## **Cloning the Repo**

We recommend cloning the repo using the following command:
```bash
git clone --recurse-submodules --remote-submodules git@github.com:mlab-upenn/f1-fifth.git
```
This will ensure that all submodules are correctly cloned and updated to their correct branches

![F1-5th with labels](https://github.com/mlab-upenn/f1-fifth/raw/main/photo/1-5thCinnamonWithLabels.png)

xLAB has other scales of robots :)
![Comparison with other scales](https://github.com/mlab-upenn/f1-fifth/raw/main/photo/ComparisonWithOtherScales.png)

## Hardware overview of the robot
This is the diagram of the robot.
![F1-5th Diagram](https://github.com/mlab-upenn/f1-fifth/raw/main/photo/F1-5th.drawio.png)

6S battery gives power to Jetson, FixPosition, and Traxxas Receiver. We used three identical PDBs. 
![6s-PDB](https://github.com/mlab-upenn/f1-fifth/blob/main/photo/6sPDB.png)

6S battery and two 4S batteries can be placed in a stable matter like below.
![Battery Placements](https://github.com/mlab-upenn/f1-fifth/blob/main/photo/BatteryPlacements.png)

The BoM is [here](https://docs.google.com/spreadsheets/d/1ajliq0A3Z0W4ZdKVudvWRUUsmSORCK2iUVKaWFWbc3s/edit?usp=sharing)
.

The CAD files:  [the top plate](https://drive.google.com/drive/folders/16NSuNKn_89DZu-zBL3QmMm5ykGkUhXoV?usp=sharing) and [the wheel encoders](https://drive.google.com/drive/folders/1Jislswc6YMStNIIRbKHPtOXVm0wOJhdI?usp=drive_link)
We used ¼ inch acrylic to make the base board for all the electronics.
All the screws are M3 except Jetson (M2.5).

The video on how to decompose the x-maxx to see the servo is [here](https://youtu.be/FIq1WbCifV4?si=iypisyhZg_OIiDQC).

The video recorded by us on how to assemble the 1/5th robot is [here](https://youtu.be/yxoCi2LpZxY?si=fp9S-ktkKtcuClRA).

The video recorded by us on how to connect all the cables is [here](https://youtu.be/HyVbdDyzW7Q?si=Wg5cYTExitgQ4nUt).

For Jetson Orin nano and Jetson Orin AGX, you need to use M2.5 screws.
To use Jetson Orin nano, use M2.5 of length 6mm from the top and M2.5 of length 8mm from the bottom to fix Jetson together with the stand offs. The longer screws needs to be used as the base plate is thick (5 or 6mm).


## Cloning the repository
When cloning this repository, make sure you also clone the submodules. You can do this by running:

```bash
git submodule update --init --recursive --remote
```

This will ensure you have all the submodules cloned and updated to the configured branches.

## How to get sensors working on Cinnamon

### OUSTER (!DEPRECATED!)
We are using OUSTER OS1 LiDAR with 128 rays.
Connect the LiDAR and its medium converter. Give 24V to the converter.
Go to http://os-122411000631.local/ (http://os-[serial number of your OUSTER].local/) to open the sensor's configuration page.
Use [the official ROS2 package](https://github.com/ouster-lidar/ouster-ros/tree/ros2?tab=readme-ov-file) as we have it in src as well.
When you run the launch file, you need to put the ip address of the sensor, which can be obtained from os-122411000631.local 

### Fixposition
We recommend to have ethernet connection between Jetson and Fixposition instead of Wi-Fi. You should also mount modem (we used NRadio as in BoM spreadsheet) and connect it to Jetson so that Jetson and Fixposition has a stable Internet.

#### First time setup
- access point - keep it on
1. connect fixposition and NRadio via ethernet
2. From the laptop, connect to fixposition's wifi using access point fp-(numbers)
3. On laptop, open the fixposition page 10.0.2.1. Then from the configuration of network, choose DHCP-client. When turning this on, make this to the default.
4. connect the ethernet between the lap and dress was assigned to the fixposition.
6. Check 192.168.66.105 (fp's address assigned by NRadio) is accessible
7. If accessible, disconnect from the fixposition's Access Point fp-(numbers)
8. we can turn off wifi on laptop to make sure ethernet is used
9. If you want to have remote access to Jetson using NoMachine, the password to connect to NRadio WiFi is “12345678”.

#### Once you have the above setup
Once you did the above setup, you don’t have to repeat the same thing next time you power on the fixposition. You can connect the ethernet between the laptop and the modem (NRadio) and between fixposition and the modem. Fixposition should automatically become DHCP-client by default by doing the step 3 of the first-time setup. Sometimes the ip address of the fixposition assigned by the modem can change. If so, you can check the new ip address by going to the modem’s ip address (192.168.66.1).

#### If you have wireless internet connection for Fixposition (Not Recommended)
Although we recommend using modem and ethernet cable connection to have stable Internet as mentioned above, we explain how to have Wi-Fi on Fixposition just in case.

With Ethernet cable, connect to 10.0.2.1
With Wifi, connect to 10.0.1.1
On Fixposition's configration page, connect to the same Wi-Fi that Jetson is connected to.

If you can’t connect, you should try unplugging the ethernet cable on fix position and plugging it again. You can also try removing the ethernet connection setting and make a new default one.

#### ROS2 driver for Fixposition
Clone to these repos. Make sure to update the ip address of fixposition in tcp.yaml. Then, colcon build the package.
https://github.com/fixposition/fixposition_driver
https://github.com/fixposition/fixposition_gnss_tf

#### GNSS RTK subscription on fixpoition
We used [this service](https://pointonenav.com/) on our robot.
On Fixposition, fill out the RTK subscription account's information.

### Realsense
#### REALSENSE SDK INSTALL ON JETSON AGX ORIN JETPACK 6.0
```bash
sudo apt install git cmake build-essential libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev 
sudo apt install libglfw3-dev libgl1-mesa-dev libglu1-mesa-dev
git clone https://github.com/IntelRealSense/librealsense.git
cd librealsense
git checkout development
./scripts/patch-realsense-ubuntu-L4T.sh
sudo apt-get install git libssl-dev libusb-1.0-0-dev pkg-config libgtk-3-dev -y v4l-utils
./scripts/setup_udev_rules.sh
mkdir build && cd build
cmake .. -DBUILD_PYTHON_BINDINGS:bool=true -DBUILD_EXAMPLES=true -DCMAKE_BUILD_TYPE=release -DFORCE_RSUSB_BACKEND=false -DBUILD_WITH_CUDA=true
sudo make uninstall && sudo make clean && sudo make -j4 && sudo make install
cd .. && sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
realsense-viewer
```
#### Install Realsense ros2 wrapper on ros2 humble:
```sudo apt install ros-humble-realsense2-*```

### GoPro
#### GoPro Webcam cli tool
```bash
sudo apt-get install v4l-utils
sudo apt install ffmpeg v4l2loopback-dkms curl vlc
git submodule update --init --recursive
cd src/gopro_as_webcam_on_linux
sudo ./install.sh
sudo gopro webcam
```

To run the GoPro as a standard webcam (i.e with zoom/opencv) you can run `ffmpeg -nostdin -threads 1 -i 'udp://@0.0.0.0:8554?overrun_nonfatal=1&fifo_size=50000000' -f:v mpegts -fflags nobuffer -vf format=yuv420p -f v4l2 /dev/video42`

### Battery Voltage Indicator
We recommend the voltage indicator on 6S battery.
Black cables come to the left and red cable come to the right.
If it does not say 6 cs, try it again. You should try to insert all the pins at the same time.

![Voltage Indicator](https://github.com/mlab-upenn/f1-fifth/blob/main/photo/6SVoltageIndicator.jpg)

### Emergency Switch
![Emergency-Switch](https://github.com/mlab-upenn/f1-fifth/blob/main/photo/EmergencySwitch.jpg)

On VESC, Choose ADC2 Low. Connect the sensor onto the VESC as indicated by the labels.

![VESC-EmergencySwitch](https://github.com/mlab-upenn/f1-fifth/blob/main/photo/VESC-EmergencySwitch.png)

1. Press ON on the remote controllers to let the car run. The emergency sensor should have red lights on.
2. When you want to immediately stop the car, press OFF on the controllers.

There are two remote controllers, so two people at the experiments can hold them.
You can turn on/off by pressing a small button on the emergency sensor too. 

## Run the experiment
### Jetson
- Connect the ethernet between the modem and jetson
- Connect the joystick to Jetson via bluetooth
- In the workspace directory, run `ros2 launch f1tenth_stack bringup_launch_hokuyo.py`. You should be able to control the robot with the joystick. Although our robot does not have hokuyo lidar, you can still run this python script.

### Fixposition
#### If you have wired connection to the internet (Recommended)
1. Make sure to change the ip address of fixposition in tcp.yaml file.
2. In the workspace directory (ros2_ws for example), run `colcon build --packages-up-to fixposition_driver_ros2`
3. Run `ros2 launch fixposition_driver_ros2 tcp.launch`

Of course, if the ip address has not changed and you did colcon build of fixposition previously, you only have to do the step 3.

#### If you have constant stable connection to Wi-Fi from Fixposition (Not Recommended)
1. Connect to 10.0.2.1 in the browser to see the fixposition.
2. Make sure the GNSS is connected to active NTRIP subscription - you should see two light green circles on top right for GNSS 1 and GNSS 2.
3. Make sure the wifi for the fixposition is connected to the same wifi of Jetson. Don’t use Chinese or Japanese characters for the name of the wifi. Fixposition can’t connect to the wifi with those names.
4. `ros2 laKeyboardunch fixposition_driver_ros2 tcp.launch`

### NoMachine
If you want to have remote control of Jetson, install NoMachine on the machine you want to control from. 
1. On Jetson, type “ifconfig” to find its own IP address. You can also find it on NRadio's config page (192.168.66.1).
2. Open NoMachine on the remote computer. Make sure the remote computer is also connected to the same network (NRadio) via WiFi.

### Items you should take to experiments
- Display Port Dongle
- Keyboard
- Mouse
- Converter from HDMI to DP
- Two blue Sony controllers in case one of them becomes laggy
- Tape so that you can keep some cables inside
- Color cones
- Insect repellent
- (Tool to turn the screw of the wheel)
