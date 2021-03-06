# ROSトピック
- 3つのターミナルを使用して、ROSの基本となるトピック通信について学ぶ。
- 3つ目のターミナルからトピックを投げ、2つ目のターミナルで受け取る。

## コマンドを用いたトピック通信
### 1つ目：マスターの起動
- ROSマスターを起動する。
  ```
  $ roscore
  ```

### 2つ目：トピックの受信
- 別のターミナルを開く。
- コンテナーに入る。
- 利用可能なトピックの一覧を確認する。
  ```
  $ rostopic list
  /rosout
  /rosout_agg
  ```
- トピックを購読してみる。
  ```
  $ rostopic echo /turtle1/cmd_vel
  ```

### 3つ目：トピックの配信
- 別のターミナルを開く。
- コンテナーに入る。
- トピックを1回配信してみる。
  - 前半の3つの値が並進移動量、後半の3つの値が回転移動量を指定する。
   ```
   $ rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist -- '[0.0,0.0,0.0]' '[0.0,0.0,3.14]'
   ```
