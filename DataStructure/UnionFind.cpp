#include <bits/stdc++.h>

#pragma region snippet
// prefix: unionfind

struct UnionFind {
   public:
    UnionFind(int n) {
        assert(0 <= n && n <= 1e7);
        _n = n;
        parent.assign(n, -1);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        std::stack<int> path;
        while (parent[a] >= 0) {
            path.push(a);
            a = parent[a];
        }
        while (!path.empty()) {
            int v = path.top();
            path.pop();
            parent[v] = a;
        }
        return a;
    }

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int root_a = leader(a), root_b = leader(b);
        if (root_a == root_b) return root_a;
        parent[root_a] += parent[root_b];
        parent[root_b] = root_a;
        return root_a;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int size() { return _n; }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent[leader(a)];
    }

   private:
    int _n;
    std::vector<int> parent;
};

#pragma endregion

int main() {
    int N, Q;
    std::cin >> N >> Q;
    UnionFind tree(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            tree.merge(u, v);
        } else {
            std::cout << (int)tree.same(u, v) << std::endl;
        }
    }
}