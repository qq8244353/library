bool is_only_nibu(const vector<vector<int>>& to) {
  int n = to.size();
  vector<int> dep(n, -1);
  int d = 0;
  auto dfs = [&](auto&& self, int v, int p) -> bool {
    if (dep[v] >= 0) {
      if (d != dep[v]) {
        return false;
      } else {
        return true;
      }
    }
    dep[v] = d;
    d = (d + 1) % 2;
    for (auto u : to[v]) {
      if (u == p) continue;
      auto ret = self(self, u, v);
      if (ret == false) {
        return false;
      }
    }
    d = (d + 1) % 2;
    return true;
  };
  for (int s = 0; s < n; s++) {
    if (dep[s] == -1) {
      auto ret = dfs(dfs, s, -1);
      if (ret == false) {
        return false;
      }
    }
  }

  return true;
}

pair<bool, int> is_nibu(const vector<vector<int>>& to) {
  int n = to.size();
  vector<int> dep(n, -1);
  int d = 0;
  auto dfs = [&](auto&& self, int v, int p) -> bool {
    if (dep[v] >= 0) {
      if (d != dep[v]) {
        return false;
      } else {
        return true;
      }
    }
    dep[v] = d;
    d = (d + 1) % 2;
    for (auto u : to[v]) {
      if (u == p) continue;
      auto ret = self(self, u, v);
      if (ret == false) {
        return false;
      }
    }
    d = (d + 1) % 2;
    return true;
  };
  auto ret = dfs(dfs, s, -1);
  if (ret == false) {
    return {false, 0};
  }
  return {true, count(dep.begin(), dep.end(), 0)};
}

