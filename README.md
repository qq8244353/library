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
