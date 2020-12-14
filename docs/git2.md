# Git（続）


## SSHの設定
- どのディレクトリーで行っても大丈夫です。
- 下記のディレクトリーにid_rsaとid_rsa.pubが存在することを確認します。
  ```
  $ ls ~/.ssh
  ```
  - 存在しない場合は作成します。パスフレーズは無しで大丈夫です。
    ```
    $ ssh-keygen -t rsa
    ```
    - ssh-keygenコマンドが無い場合はパッケージをインストールする。
      ```
      $ sudo apt update
      $ sudo apt -y install openssh-server
      ```
- 下記のコマンドで公開鍵の内容をクリップボードにコピーする。
  ```
  $ cat ~/.ssh/id_rsa.pub | xsel --clipboard --input
  ```
  - xselコマンドが無い場合はパッケージをインストールする。
    ```
    $ sudo apt update
    $ sudo apt -y install xsel
    ```
- GitHubのウェブサイトを開き、［Settings］→［SSH and GPG keys］→［SSH keys］へ進み、ボタン「New SSH key」を押す。
- 公開鍵の内容をペーストし、登録する。


## Push
- advanced_experimentディレクトリーで行う。
  ```
  $ cd ~/catkin_ws/src/advanced_experiment
  ```
- 上位のブランチに移動し、編集内容を取り込む。
  ```
  $ git checkout develop
  $ git merge feature/名_性
  ```
- 複数人が同時に同じファイルを編集すると、衝突（conflict）が発生する。

- 設定変更
vim .git/config