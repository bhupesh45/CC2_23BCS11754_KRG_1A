#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int parent[MAXN];
int rnk[MAXN];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int findSet(int v) {
    if (parent[v] != v)
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);

        parent[b] = a;

        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);

    makeSet(n);

    int mstWeight = 0;

    for (auto &e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            unionSet(e.u, e.v);
            mstWeight += e.w;
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int mst = kruskal(n, edges);
    cout << "MST wt: " << mst << endl;

    return 0;
}