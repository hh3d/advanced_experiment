# ROSの環境構築
- Ubuntu 18.04に対応したROS Melodic Moreniaをインストールする。
- root以外のユーザーで行う。

## ROSのインストール
- ターミナルに下記のコマンドを1行ずつ入力し、実行する。
  ```
  $ sudo apt install lsb-release（※必要に応じて）
  $ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
  $ sudo apt install gnupg（※必要に応じて）
  $ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
  $ sudo apt update
  $ sudo apt install ros-melodic-desktop-full（※時間の掛かる人は「$ sudo apt install ros-melodic-ros-base」で置き換えてください。）
  $ sudo apt install python-rosdep（※必要に応じて）
  $ sudo rosdep init
  $ rosdep update
  $ echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
  $ source ~/.bashrc
  $ sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
  ```

## 環境変数の確認
- 正しくインストールできたかどうかをターミナルで確認する。  
  ```
  $ printenv | grep ROS
  ↓正常にインストールできていれば、下記のように出力される。
  ROS_ETC_DIR=/opt/ros/melodic/etc/ros
  ROS_ROOT=/opt/ros/melodic/share/ros
  ROS_MASTER_URI=http://localhost:11311
  ROS_VERSION=1
  ROS_PYTHON_VERSION=2
  ROS_PACKAGE_PATH=/opt/ros/melodic/share
  ROSLISP_PACKAGE_DIRECTORIES=
  ROS_DISTRO=melodic
  ```
