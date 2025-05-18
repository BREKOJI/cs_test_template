#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> & edges);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int> (2));
    for (int i = 0; i < m; i ++ ) {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<int> ans = topologicalSort(n, edges);
    if (ans.size() == 1 || ans[0] == -1) 
        cout << -1 << endl;
    else {
        for (int node : ans) {
            cout << node << ' ' ;
        }
        puts("");
    }
    return 0;
}

vector<int> topologicalSort(int n, vector<vector<int>> & edges) {
    vector<vector<int>> adj(n + 1);// from 1 on
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < int(edges.size()); i ++ ) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].emplace_back(v);
        inDegree[v] ++ ;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i ++ )
        if (inDegree[i] == 0) {
            q.emplace(i);
            ans.emplace_back(i);
        }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            inDegree[v] -- ;
            if (inDegree[v] == 0) {
                q.emplace(v);
                ans.emplace_back(v);
            }
        }
    }
    if (ans.size() != n) {
        return {-1};
    }
    return ans;
}