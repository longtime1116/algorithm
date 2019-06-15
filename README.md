# std

* priority_queue
  * 優先度付きキュー
* map
  * key に関して二分木で実装された連想配列
  * 重複を許す場合は multimap
* set
  * 二分木で実装された順序付集合
  * 重複を許す場合は multiset

# lib
* Union-Find 木
  * 木でグループ分けを表現。nodeの根にあたるものが一致するならば同グループ。

* 二部グラフ(bipartite_graph)判定
  * 隣接する2つを別の色で分けられるか？
  * 判定自体よりも、分けられる場合(奇サイクルが存在しない場合)の特徴を活かす問題が出ることがあるので注意。

* 最短路問題
  * 単一始点最短経路問題
    * 負の辺が存在する場合はベルマンフォードを使うと良い。O(E * V)
    * 全て正なのであればダイクストラを使うほうが早い。O(E * logV)
  * 全点対最短路問題
    * 正負関係なく、ワーシャルフロイドが使える。(O(V^3))
