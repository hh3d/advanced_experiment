# Git（続）

## SSHの設定
下記のディレクトリーにid_rsaとid_rsa.pubが存在することを確認する。なお、拡張子「.pub」は公開鍵を表す。
```
$ ls ~/.ssh
```
  存在しない場合は作成する。
  ```
  $ ssh-keygen -t rsa
  ```
Macの場合は下記のコマンドで公開鍵の内容をクリップボードにコピーする。
```
pbcopy < ~/.ssh/id_rsa.pub
```
GitHubのウェブサイトを開き、SSH keysへペーストし、登録する。

## Push
- 上位のブランチに移動し、編集内容を取り込む。
  ```
  $ git checkout develop
  $ git merge feature/名_性
  ```
- 複数人が同時に同じファイルを編集すると、衝突（conflict）が発生する。

- 設定変更
vim .git/config
