# Launching

Launching: The launching machine  on the PR vehicle of WTRobocon in 2020.

This machine aims to use a few M3508 which are rotating continuously to pass the football from PR to TR.

In order to achieve this, this node will hear from joy_node, and send message to package 'wtr_usb2ros' so that 4 M3508 will rotate.



Here's the way we control the motors via the remote control:

## Guide for remote control

手柄左侧的黑色十字按钮的上下键为加减速功能。

手柄右侧的A、B键分别为默认速度开启和急停按钮。

可执行文件launching执行或者launch文件执行的时候，电机默认不旋转，当按下A时或者按下加速键（十字上键）时，电机开始旋转。而按下减速键（十字下键）时，电机减速；按下B键时立即停止旋转。



## Tips for assembly

由于1号3号电机的旋转方向相同，2号4号电机旋转方向相同，因此需要将电调编号设置为奇数偶数分列两侧。