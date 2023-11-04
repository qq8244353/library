
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using i64 = long long;
using i128 = __int128;
constexpr int INF = numeric_limits<int>::max();
constexpr i64 I64F = numeric_limits<i64>::max();
constexpr i128 I12F = numeric_limits<i128>::max();
using u64 = unsigned long long;
using ld = long double;
using i_i = pair<int, int>;
using l_l = pair<i64, i64>;
using d_d = pair<double, double>;
using s_s = pair<string, string>;
using i_i_i = tuple<int, int, int>;
using i_i_i_i = tuple<int, int, int, int>;
using l_l_l = tuple<i64, i64, i64>;
using l_l_l_l = tuple<i64, i64, i64, i64>;
using _bool = int;
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define ifbit(n,k) ((n>>k)&1) //if kth bit of n is on then true (sitakara, 0-indexed)
#define zpad(i) cout << setfill('0') << setw(i)
#define dout cout << fixed << setprecision(10)
#define douts(i) cout << fixed << setprecision(i) << scientific
#define pcnt __builtin_popcount
template <class T> bool chmax(T &l, const T &r) { if (l < r) { l = r; return true; } return false; }
template <class T> bool chmin(T &l, const T &r) { if (l > r) { l = r; return true; } return false; }
template <class T> pair<int, bool> ub(const vector<T> &v, const T &key) { int ind = upper_bound(v.begin(), v.end(), key) - v.begin(); if (ind == (int)v.size()) return make_pair(0, false); return make_pair(ind, true); }
template <class T> pair<int, bool> rub(const vector<T> &v, const T &key) { int ind = upper_bound(v.rbegin(), v.rend(), key, [](const T & l, const T & r) { return l > r; }) - v.rbegin(); if (ind == (int)v.size()) return make_pair(0, false); return make_pair((int)v.size() - 1 - ind, true); }
template <class T> pair<int, bool> lb(const vector<T> &v, const T &key) { int ind = lower_bound(v.begin(), v.end(), key) - v.begin(); if (ind == (int)v.size()) return make_pair(0, false); return make_pair(ind, true); }
template <class T> pair<int, bool> rlb(const vector<T> &v, const T &key) { int ind = lower_bound(v.rbegin(), v.rend(), key, [](const T & l, const T & r) { return l > r; }) - v.rbegin(); if (ind == (int)v.size()) return make_pair(0, false); return make_pair((int)v.size() - 1 - ind, true); }

template<class T> struct lca {
  public:
    lca(int n_) : n(n_), to(n), co(n), dep(n), costs(n) {
        l = 0;
        while ((1 << l) < n) { l++; }
        par = vector<vector<int>>(n + 1, vector<int>(l, n));
    }
    void add_edge(int a, int b, T c = 1) {
        to[a].push_back(b);
        co[a].push_back(c);
        to[b].push_back(a);
        co[b].push_back(c);
    }
    void init(int root_ = 0) {
        root = root_;
        dfs(root);
        for (int i = 0; i < l - 1; i++) {
            for (int v = 0; v < n; v++) {
                par[v][i + 1] = par[par[v][i]][i];
            }
        }
    }
    int get(int a, int b) {
        if (dep[a] > dep[b]) { swap(a, b); }
        int gap = dep[b] - dep[a];
        for (int i = l - 1; i >= 0; i--) {
            int len = 1 << i;
            if (gap >= len) {
                gap -= len;
                b = par[b][i];
            }
        }
        if (a == b) { return a; }
        for (int i = l - 1; i >= 0; i--) {
            int na = par[a][i];
            int nb = par[b][i];
            if (na != nb) { a = na, b = nb; }
        }
        return par[a][0];
    }
    T dist(int a, int b) {
        int c = get(a, b);
        return costs[a] + costs[b] - costs[c] * 2;
    }
  private:
    int n, root, l;
    vector<vector<int>> to;
    vector<vector<T>> co; //cost
    vector<int> dep;
    vector<T> costs; //costs sum
    vector<vector<int>> par;
    void dfs(int v, int d = 0, T c = 0, int p = -1) {
        if (p != -1) { par[v][0] = p; }
        dep[v] = d;
        costs[v] = c;
        for (int i = 0; i < to[v].size(); i++) {
            int u = to[v][i];
            if (u == p) { continue; }
            dfs(u, d + 1, c + co[v][i], v);
        }
    }
};


