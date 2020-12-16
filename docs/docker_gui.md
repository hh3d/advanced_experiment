# Docker（GUI編）
- DockerはCUIの利用を想定している。
- X Window System（X11）を用いてホストOS上でGUIを表示できる。ホストOSに表示を依頼する（＝X11 Forwarding）。
- Dockerを起動した状態（Dockerコマンドが使用できる状態）で下記の作業を行う。

## Ubuntu
### 準備
- dockerグループにユーザーを追加する。
  ```
  $ sudo gpasswd -a $USER docker
  ```
- ソケット通信に関するファイルの所有者を変更する。
  ```
  $ sudo chgrp docker /var/run/docker.sock
  ```
- dockerサービスを再起動する。
  ```
  $ sudo service docker restart
  ```
- コンピューターを再起動する。
  ```
  $ sudo reboot
  ```
- 接続が許可されているホストにLOCALがあることを確認する。
  ```
  $ xhost
  ```

## 実行
- イメージをダウンロードする。
  ```
  $ docker pull ros:melodic-robot-bionic
  ```
- コンテナーを作成する。
  ```
  $ docker run -itd --env="DISPLAY" --env="QT_X11_NO_MITSHM=1" --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" --name ros ros:melodic-robot-bionic
  ```
- コンテナーに入る。
  ```
  $ docker exec -it ros bash
  ```

## Mac
### 準備
- XQuartzをインストールする。
  - https://www.xquartz.org/
- XQuartzを起動し、［環境設定］→［セキュリティ］から「ネットワーク・クライアントからの接続を許可」にチェックを入れる。
- コンピューターを再起動する。
- 再度、XQuartzを起動する。

### 実行
- イメージをダウンロードする。
  ```
  $ docker pull ros:melodic-robot-bionic
  ```
- イメージの存在を確認する。
  ```
  $ docker images
  ```
- コンテナーを作成する。
  ```
  $ docker run -it -e DISPLAY=$(hostname):0 -v ~/.Xauthority:/root/.Xauthority --name ros ros:melodic-robot-bionic
  ```

### 再実行
- コンテナーを起動する。
  ```
  $ docker start ros
  ```
- コンテナーに入る。
  ```
  $ docker exec -it ros bash
  ```

## Windows
### 準備
- 事前にコンテナーのIPアドレスを確認しておく。
  ```
  $ hostname -i
  ```
- WindowsにXmingをインストールする。
  - http://www.straightrunning.com/XmingNotes/
  - Public Domain Releases（無料版）のXming 6.9.0.31を選択する。
- Xmingの設定を変更する。
  - Xmingのインストール先（/Program Files/Xming）にあるX0.hostsファイルに、X Windowの転送を許可するサーバ（X Windowを転送するサーバ）のIPアドレスを記入する。
- PCを再起動する。

## 実行
- Xmingを起動する。
  - Display numberは0とする。
- イメージをダウンロードする。
  ```
  $ docker pull ros:melodic-robot-bionic
  ```
- ホストOSのIPアドレスを確認する。
  ```
  $ ipconfig
  ```
- ホストOSのIPアドレスを指定しつつ、コンテナーを作成する。
  ```
  $ docker run -it -e DISPLAY=IPアドレス:0.0 -v ~/.Xauthority:/root/.Xauthority --name ros ros:melodic-robot-bionic
  ```
- コンテナーに入る。
  ```
  $ docker exec -it ros bash
  ```
