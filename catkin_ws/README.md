# WTR ROS+CoppeliaSim学习资料

# 1.文件结构

```bahs
├── catkin_ws		# 工作空间
│   └── src
│       ├── keyboard	# 键盘读入控制包
│       │   ├── CMakeLists.txt
│       │   ├── package.xml
│       │   └── src
│       │       └── keyboard_steeringwheel.py
│       └── vrep_pkg	# ROS与Vrep通信控制包
│           ├── CMakeLists.txt
│           ├── include
│           │   └── steeringwheel.h
│           ├── launch
│           │   ├── omniwheel.launch
│           │   └── steerwheel.launch
│           ├── package.xml
│           └── src
│               ├── FourWheelControl.cpp
│               ├── fwc.h
│               ├── omniwheel.cpp
│               ├── steeringwheel.cpp
│               └── steeringwheel_ros.cpp
├── README.md		# 说明文档
└── scenes			# Vrep场景文件
    ├── RaceSceneWithOmniwheel.ttt
    └── RaceSceneWithSteerwheel.ttt

```



# 2.使用方法

## 2.0 下载安装CoppeliaSim

[官方网站](https://www.coppeliarobotics.com/downloads)

![image-20200604105158268](README.assets/image-20200604105158268.png)

下载中间的EDU版本

解压后进入目录，搜索`libsimExtROSInterface.so`

> 通常在 `/CoppeliaSim_Edu_V4_0_0_Ubuntu16_04/compiledRosPlugins`

将这个文件拷贝到 `/CoppeliaSim_Edu_V4_0_0_Ubuntu16_04`的跟目录。

随后在根目录`./coppeliaSim.sh`即可启动`CoppeliaSim`。

注意！！！！如果要使用ROS，一定要在启动`roscore`之后再启动`coppeliaSim`。

## 2.1 载入仿真场景

![image-20200604110641566](README.assets/image-20200604110641566.png)

选择scenes文件夹中的场景即可打开。

![image-20200604110738400](README.assets/image-20200604110738400.png)

点击上方即可启动仿真。

## 2.2 ROS使用

编译ros包

```bash
cd catkin_ws
catkin_make
source devel/setup.bash
```

启动通讯节点

```bash
rosrun vrep_pkg steerwheel
```

启动键盘控制节点

```
roscd keyboard/src 
sudo chmod +x keyboard_steeringwheel.py
rosrun keyboard keyboard_steeringwheel.py
```

启动xbox控制节点

```
rosrun joy joy_node
rosrun keyboard xbox
```

# 3. 任务

## 3.1 控制小车运动

自己完成一个发布者向topic:`/cmd_vel`发布速度信息，控制小车运动。

## 3.2 学习代码

学习vrep和ros的通信方式，阅读steeringwheel的控制代码

## 3.3 学习CoppeliaSim

先参考刘健恒同学完成的教程：[教程网址](https://github.com/jianhengLiu/CoppeliaSim_Steeringwheel_Tutorial)

学习基础之后上网查询想过操作进一步学习。



# 4.ISSUE

keyboard_steeringwheel.py中的所有Print后均未加括号，如果使python2.7则会报错。



解决USB的永恒绑定授权

https://www.jb51.net/os/Ubuntu/392419.html

```
lsusb -vvv
```

找出USB设备的vendorID和productID

```
$ sudo vi /etc/udev/rules.d/50-myusb.rules
SUBSYSTEMS=="usb", ATTRS{idVendor}=="067b", ATTRS{idProduct}=="2303", GROUP="users", MODE="0666"
```

其中067b和2303替换成vendorID和productID，users改成自己的用户名。

重启并重新加载udev规则：

```
$ sudo udevadm control --reload
```



 sudo ls -all /dev/bus/usb/001

