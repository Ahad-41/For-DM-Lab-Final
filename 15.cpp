#include <bits/stdc++.h>
using namespace std;

int node, adjMatrix[1000][1000];
bool visited[1000];

void dfs(int currNode) {
    visited[currNode] = true;
    for (int i = 1; i <= node; i++) {
        if (adjMatrix[currNode][i] and !visited[i]) dfs(i);
    }
}

int main()
{
    cin >> node;

    int totalEdge = 0;
    for (int i = 1; i <= node; i++) {
        for (int j = 1; j <= node; j++) {
            cin >> adjMatrix[i][j];
            totalEdge += adjMatrix[i][j];
        }
    }
    totalEdge /= 2;

    int connectedComponent = 0;
    for (int i = 1; i <= node; i++) {
        if (!visited[i]) {
            dfs(i);
            connectedComponent++;            
        }
    }

    if (connectedComponent == 1 and totalEdge == node-1) cout << "The graph is a tree\n";
    else cout << "The graph is not a tree\n";

    return 0;
}