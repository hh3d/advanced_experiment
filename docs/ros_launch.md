# roslaunchの利用
## 基本
毎回、複数のターミナルを開くのは面倒なので、ここからはROSコマンド「roslaunch」を使用します。roslaunchコマンドでlaunchファイルを実行すると、複数のROSノードを1つのターミナルで起動することができます。また、ROSマスターが起動していなかった場合は、起動してくれます。

サンプルプログラムをGitHub上に公開しているので、~/catkin_ws/srcにcloneし、使用してみてください。既にclone済みの場合はpullしてください。
```
$ cd ~/catkin_ws/src
$ git clone https://github.com/stl-apu/advanced_experiment.git
```  
サンプルプログラムをビルドします。
```
$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash
```
下記のとおり実行します。launchディレクトリー内のturtle_test.launchを確認すると、2つのROSノードが起動することが分かります。
```
$ roslaunch advanced_experiment turtle_test.launch
```

## 応用基礎

※Dockerの人はこのセクションを実行できません。

- 画像処理に必要なROSパッケージをインストールします。
  ```
  $ sudo apt install ros-melodic-usb-cam
  $ sudo apt install ros-melodic-cv-camera
  $ sudo apt install ros-melodic-opencv-apps
  ```
- 画像処理を実行します。launchディレクトリー内のedge_detection.launchを確認すると、4つのROSノードが起動することが分かります。
```
$ roslaunch advanced_experiment edge_detection.launch
```
- ROSパッケージ「opencv_apps」は画像処理用ライブラリーであるOpenCVをROSで気軽に使用できるようにしたもので、この例では同パッケージ内のROSノード「edge_detection（エッジ検出）」を利用しています。
- 2つのウィンドウが表示され、顔の輪郭などに白線が出ていればOKです。


## 応用

※Dockerの人はこのセクションを実行できません。

画像処理の結果を利用して、亀を動かすことができます。

camera_infoの情報を利用することになるので、カメラのキャリブレーションを行う。→Camera Calibration

試しに実行する。5つのROSノードが起動する。  
```
roslaunch stl_ros_sample turtle_operation.launch
```  
ROSパッケージ「opencv_apps」のROSノード「hough_circles（ハフ変換）」を利用して真円を検出する。そして、鈴木のROSパッケージ「stl_ros_sample」のROSノード「turtle_operation」で、真円の中心位置を亀の操作量へ変換する。

何か円形のものを撮影し、円を検出させる。画像の上の方に円を検出させると前進、下の方に検出させると後進する。また、左の方に円を検出させると左回転、右の方に円を検出させると右回転する。

恐らくカメラの解像度や撮影時の背景によって上手く動作しないので、ROSパラメーターを調整する。

launchディレクトリー内のturtle_operation.launchを開き、下記のvalueを適当に変更し、上書き保存する。（※改めてcatkin_makeする必要はない。）

- **accumulator_threshold**  
円が検出されないときは値を小さく、円が検出されすぎるときは値を大きくする。  
- **scale_linear**  
亀の直進移動が早すぎる場合は値を大きく、遅すぎる場合は値を小さくする。  
- **scale_angular**  
亀の回転移動が早すぎる場合は値を大きく、遅すぎる場合は値を小さくする。

亀は上手く動かせましたか？

## ポイント
重要なポイントは、5つのノードのうち、鈴木は1つのノードしか開発していないということです。ROSはユーザー数が多いため、画像の取得や表示など、多くの人が必要としている機能は既に実装・公開されています。そのため、自分が得意とする部分の開発に注力することができます。

トヨタ自動車の生活支援ロボットHSRも大所帯で開発していますが、愛県大グループでは点群処理用ROSパッケージの開発のみを行っており、その他の部分はトヨタ自動車や他の研究機関が開発してくれています。ROSを利用することで共同研究しやすくなったと言えます。

ROSの演習は以上です。お疲れ様でした。（何か間違いを見つけたら教えてください。）

[トップへ](#)









