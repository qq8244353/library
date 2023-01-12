# 表記
i64 : long long<br>
u64 : unsigned long long<br>
i_b : pair\<int, bool\><br>
i_i : pair\<int, int\><br>
i_i_i : tuple\<int, int, int\><br>
l_l : pair\<long long, long long\><br>
l_l_l : pair\<long long, long long, long long\><br>

# 説明書
## Template
### bool chmax(k, n):
* n > kのときkをnに更新.更新した時trueを返す<br>

### bool chmin(k, n):
* n < kのときkをnに更新.更新した時trueを返す<br>

### i_b ub(vector\<T\> v, T key):
* 第一要素にv[i] > kとなる最小のiを返す。存在しない時第二要素でfalseを返す<br>

### i_b lb(vector\<T\> v, T key):
* 第一要素にv[i] >= kとなる最小のiを返す。存在しない時第二要素でfalseを返す<br>

### i_b rub(vector\<T\> v, T key):
* 第一要素にv[i] < kとなる最大のiを返す。存在しない時第二要素でfalseを返す<br>

### i_b rlb(vector\<T\> v, T key):
* 第一要素にv[i] <= kとなる最大のiを返す。存在しない時第二要素でfalseを返す

## prime
素因数分解系ライブラリ

### prime(int n)
* コンストラクタ

### l_l fast_get(int k)
* $O(log(k))$ で素因数分解する
* $1 \leq k \leq n$ であることが必要
* pair(素因数, 指数)
* [参考](https://atcoder.jp/contests/abc177/editorial/82)

### l_l get(i64 k)
* $O(\sqrt(k))$ で素因数分解する
* $1 \leq k * k \leq n$ であることが必要
* pair(素因数, 指数)

### bool [k]
* kが素数であるかを判定する 
* $1 \leq k \leq n$ であることが必要

### vector<i64> get_all(i64 k)
* $O(\sqrt(k))$でkの約数を全列挙する(昇順)


## RollingHash
[Original](https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp)
### RollingHash(string s)
* コンストラクタ
### u64 get(i64 l, i64 r)
* [l, r)のハッシュを取得
### u64 connect(u64 h1, u64 h2, 64 h2len) 
* ハッシュh1, h2を繋げたハッシュを取得する。h2lenはハッシュh2に対応する文字列の長さ。
### void connect(string s) 
* sを繋げたハッシュに更新
