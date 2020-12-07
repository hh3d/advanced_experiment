# シミュレーション
- rootユーザーで行ってください。

## 準備
- 環境変数DISPLAYが設定されていることを確認する。
  ```
  $ echo $DISPLAY
  ```
- シミュレーション実験用のROSパッケージをインストールする。
  ```
  $ sudo apt update
  $ sudo apt -y install ros-$(rosversion -d)-turtlesim
  ```

## 実行
- turtlesimをキーボードで動かす。  
- 全部で3つのターミナルを用いる。ターミナルを3つ用意しても良いですし、1つのターミナルに3つのタブを作成しても良いです。
- 全てのターミナルに共通して、下記を実行する。
  - コンテナーに入る。
  ```
  $ docker exec -it ros bash
  ```
  - コンテナーに入ったあと、環境変数などを設定する。
  ```
  $ source ros_entrypoint.sh
  ```
- 3つ目のターミナルをアクティブにした状態で矢印キーを入力すると、ロボットを動かせる。
- 「Ctrlキー＋cキー」で停止できる。

### 1つ目のターミナル  
- ROSマスターを起動する。  
  ```
  $ roscore
  ```

### 2つ目のターミナル  
- バーチャルなロボットとして、turtlesimノードを起動する。  
  ```
  $ rosrun turtlesim turtlesim_node
  ```

### 3つ目のターミナル  
- ロボットを動かすため、キーボード入力を速度情報に変換するROSノードを起動する。
  ```
  $ rosrun turtlesim turtle_teleop_key
  ```
