#include <bits/stdc++.h>
using namespace std;

struct edge {
    int w, u, v;
    bool operator<(const edge& arr) const {
        return w < arr.w;
    }
};

int n, e, parent[100];
vector<edge> arr;

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

int mst() {
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    int count = 0, minCost = 0;
    for (int i = 0; i < e; i++) {
        int u = find(arr[i].u);
        int v = find(arr[i].v);
        if (u != v) {
            parent[u] = v;
            count++;
            minCost += arr[i].w;
            if (count == n - 1) break;
        }
    }

    return minCost;
}

int main()
{
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int u, v, w; cin >> u >> v >> w;
        arr.push_back({w, u, v});
    }
    sort(arr.begin(), arr.end());
    cout << mst() << endl;
}