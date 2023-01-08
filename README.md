# 説明書

## Template
### bool chmax(k, n):
* n > kのときkをnに更新.更新した時trueを返す<br>

### bool chmin(k, n):
* n < kのときkをnに更新.更新した時trueを返す<br>

### pair\<int, bool\> ub(vector\<T\> v, T key):
* 第一要素にv[i] > kとなる最小のiを返す。存在しない時第二要素でfalseを返す<br>

### pair\<int, bool\> lb(vector\<T\> v, T key):
* 第一要素にv[i] >= kとなる最小のiを返す。存在しない時第二要素でfalseを返す<br>

### pair\<int, bool\> rub(vector\<T\> v, T key):
* 第一要素にv[i] < kとなる最大のiを返す。存在しない時第二要素でfalseを返す<br>

### pair\<int, bool\> rlb(vector\<T\> v, T key):
* 第一要素にv[i] <= kとなる最大のiを返す。存在しない時第二要素でfalseを返す

## RollingHash
[Original](https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp)
### RollingHash(string s)
* コンストラクタ
### get(i64 l, i64 r)
* [l, r)のハッシュを取得
### connect(u64 h1, u64 h2, 64 h2len) 
* ハッシュh1, h2を繋げたハッシュを取得する。h2lenはハッシュh2に対応する文字列の長さ。
### connect(string s) 
* sを繋げたハッシュに更新
