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

