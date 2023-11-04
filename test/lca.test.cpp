#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "tempalte.cpp"
#include "tree/lca.cpp"

int main() {
  int n, q; cin >> n >> q;
  lca<int> l(n);
  rep(i, n - 1) {
    int p; cin >> p;
    l.add_edge(i + 1, p);
  }
  l.init();
  rep(i, q) {
    int u, v; cin >> u >> v;
    cout << l.get(u, v) << endl;
  }
}
