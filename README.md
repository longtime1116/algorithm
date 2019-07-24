# std

* priority_queue
  * 優先度付きキュー
* map
  * key に関して二分木で実装された連想配列
  * 重複を許す場合は multimap
* set
  * 二分木で実装された順序付集合
  * 重複を許す場合は multiset
* multiset
  * erase するときにひとつだけ消す場合とまるごと消す場合で処理が違うので注意
  * (他のも同様だが)lower_bound等で二分探索するときに、STL の関数を使うのではなくインスタンスに対してメッセージを送らないと、O(n)になってしまうので注意

# lib
* Union-Find 木
  * 木でグループ分けを表現。nodeの根にあたるものが一致するならば同グループ。

* 二部グラフ(bipartite_graph)判定
  * 隣接する2つを別の色で分けられるか？
  * 判定自体よりも、分けられる場合(奇サイクルが存在しない場合)の特徴を活かす問題が出ることがあるので注意。

* 最短路問題系
  * 単一始点最短経路問題
    * 負の辺が存在する場合はベルマンフォードを使うと良い。O(E * V)
    * 全て正なのであればダイクストラを使うほうが早い。O(E * logV)
  * 全点対最短路問題
    * 任意の二点間の最短経路が欲しければワーシャルフロイドが使える。(O(V^3))
    * 負の閉路がなければ、負の辺があっても使える。
    * 負の閉路があるかどうかは、任意の二点間のコストが負になっているかどうかをチェックすれば良い
  * 最小全域木のコスト計算はプリム法


* 数学系
  * combination計算
    * nCr の計算をパスカルの三角形を使って事前計算する
  * 素因数分解(factoring.cpp)
  * エラストテネスの篩による素数列挙(sieve.cpp)
  * 繰り返し二乗法により n^p (mod m) を高速に求める(mod_pow.cpp)
