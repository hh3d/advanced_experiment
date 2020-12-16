# ROSのビルド

## 準備
- 研究開発用ディレクトリーcatkin_wsおよびsrcを作成する。
  ```
  $ mkdir -p ~/catkin_ws/src
  ```

## ビルド
- catkin_makeコマンドを用いてビルドする。
  ```
  $ cd ~/catkin_ws
  $ catkin_make
  $ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
  $ source ~/.bashrc
  $ roscd
  ↓正常にビルドできていれば、下記の場所に移動する。
  ~/catkin_ws/devel
  ```
