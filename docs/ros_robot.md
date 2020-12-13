# 実機
## 準備
- 不足しているパッケージが無いかを確認する。
  ```
  $ sudo apt update
  $ sudo apt -y upgrade
  $ sudo apt -y install wget
  $ wget https://raw.githubusercontent.com/ROBOTIS-GIT/robotis_tools/master/install_ros_melodic.sh
  $ chmod 755 ./install_ros_melodic.sh
  $ bash ./install_ros_melodic.sh
  $ sudo apt -y install ros-melodic-joy ros-melodic-teleop-twist-joy \
  ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc \
  ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan \
  ros-melodic-rosserial-arduino ros-melodic-rosserial-python \
  ros-melodic-rosserial-server ros-melodic-rosserial-client \
  ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server \
  ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro \
  ros-melodic-compressed-image-transport ros-melodic-rqt-image-view \
  ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
  ```
- TurtleBot3用のパッケージをインストールする。
  ```
  $ source /opt/ros/melodic/setup.bash
  $ sudo apt -y install ros-melodic-turtlebot3-msgs
  $ sudo apt -y install ros-melodic-turtlebot3
  ```
- 環境変数を設定する。
  ```
  $ echo "export TURTLEBOT3_MODEL=burger" >> ~/.bashrc
  $ echo "export ROS_MASTER_URI=http://172.17.0.2:11311" >> ~/.bashrc（※コンテナーのIPアドレス）
  $ echo "export ROS_HOSTNAME=172.17.0.2" >> ~/.bashrc（※コンテナーのIPアドレス）
  ```

## 実行
### ターミナル1
- 環境変数を設定する。
  ```
  $ source ~/.bashrc
  ```
- ROSマスターとROSノードを起動する。
  ```
  $ roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
  ```
### ターミナル2
- PCからリモートで入る。
  ```
  $ ssh pi@10.0.1.3（※ロボットのIPアドレス）
  ```
- ROSノードを起動する。
  ```
  $ roslaunch turtlebot3_bringup turtlebot3_robot.launch
  ```
  
