# wtr_chassis

本工作空间项目包含了数个package。

```
├── catkin_ws
│   └── src
│       ├── joy
│       ├── launching
│       ├── twist2multiarray
│       └── wtr_canbus
└── 
```

## package

### joy

内含有xbox的可执行文件joy_node，以及xbox，可以将手柄的数据发送并且转换为小车的运动速度与角速度

```cpp
rosrun joy joy_node
若是控制底盘，则还需运行
rosrun joy xbox
```

### launching

用来控制发射机构的电机，可执行文件为launching_node

```cpp
rosrun joy joy_node
rosrun launching launching_node
```

### twist2multiarray

```cpp
rosrun twist2multiarray PR //若为TR则写作TR
```

### wtr_canbus

```cpp
rosrun wtr_usb2can main
```



## PR/TR launch文件

launch文件写在twist2multiarray内

```cpp
roslaunch twist2multiarray PR.launch
roslaunch twist2multiarray TR.launch
```

