# ROSノード

## ROSノードを用いたトピック通信
- 応用実験用のROSパッケージ「advanced_experiment」をクローンしたあとに実行する。
- catkin_makeコマンドを用いてビルドする。
  ```
  $ cd ~/catkin_ws
  $ catkin_make
  $ source devel/setup.bash
  ```

### 1つ目
- roscoreを起動する。
  ```
  $ cd ~/catkin_ws
  $ source devel/setup.bash
  $ roscore
  ```

### 2つ目
- listenerを起動する。
  ```
  $ cd ~/catkin_ws
  $ source devel/setup.bash
  $ rosrun advanced_experiment listener 
  ```

### 3つ目
- talkerを起動する。
  ```
  $ cd ~/catkin_ws
  $ source devel/setup.bash
  $ rosrun advanced_experiment talker
  ```
