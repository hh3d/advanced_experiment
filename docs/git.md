# Git
Gitを使用して、応用実験で使用するプログラムをダウンロードする。

## 準備
コンテナーに入り、必要な設定を行う。
- vimをインストールする。
  ```
  $ sudo apt -y install vim
  ```
- gitをインストールする。
  ```
  $ sudo apt -y install git
  ```
- gitがインストールされたことを確認する。
  ```
  $ git version
  ```
- ユーザーの名前とメールアドレスを登録する。
  ```
  《記法》
  $ git config --global user.name "名前"
  $ git config --global user.email "メールアドレス"
  ```
  ```
  《実例》
  $ git config --global user.name "Takuo Suzuki"
  $ git config --global user.email "takuo.suzuki@ist.aichi-pu.ac.jp"
  ```

## 使い方
-「ROSの環境構築」の「ビルド」の作業を行い、catkin_wsなどが作成済みである状態で始めてください。
- ROSでは、プログラムをワークスペースのソースに置くので、ディレクトリーを移動する。
  ```
  $ cd ~/catkin_ws/src
  ```
- cloneコマンドでプログラムをコピーする。
  ```
  $ git clone https://github.com/stl-apu/advanced_experiment.git
  ```
- lsコマンドでadvanced_experimentがあるを確認する。
  ```
  $ ls
  ```
- ディレクトリーadvanced_experimentに移動する。
  ```
  $ cd advanced_experiment
  ```
- ブランチの一覧を確認する。
  ```
  $ git branch
  ```
- ブランチ「develop」に移動する。
  ```
  $ git checkout develop
  ```
- 自分用のブランチを作成する。
  ```
  《記法》
  $ git branch feature/名_性
  ```
  ```
  《実例》
  $ git branch feature/takuo_suzuki
  ```
- 自分用のブランチに移動する。
  ```
  $ git checkout feature/名_性
  ```
- test.txtを編集し、保存する。
  ```
  $ vim test.txt
  ```
- 編集内容をcommitの対象にする。
  ```
  $ git add -A
  ```
- commitする。
  ```
  《記法》
  $ git commit -m "コミット文"
  ```
  ```
  《実例》
  $ git commit -m "Change test.txt"
  ```
- pushする。恐らくSSHの設定が済んでいないとpushできない。→来週
  ```
  $ git push origin feature/名_性
  ```
- 上位のブランチから編集内容を取り込む。
  ```
  $ git checkout develop
  $ git merge feature/名_性
  ```
- 複数人が同時に同じファイルを編集すると衝突（conflict）が発生する。
