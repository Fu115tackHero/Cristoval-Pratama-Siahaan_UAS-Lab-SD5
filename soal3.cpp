#include <iostream>
#include <vector>
using namespace std;

int dfs(int node, vector<vector<int>>& graph, vector<int>& depth) {
    int maxDepth = 1;
    for (int child : graph[node]) {
        maxDepth = max(maxDepth, dfs(child, graph, depth) + 1);
    }
    depth[node] = maxDepth;
    return maxDepth;
}

int main() {
    int n;
    cin >> n;
    vector<int> manejer(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> manejer[i];
        if (manejer[i] != -1) {
            graph[manejer[i]].push_back(i);
        }
    }
    vector<int> depth(n + 1, 0);
    int maksimum = 0;
    for (int i = 1; i <= n; i++) {
        if (manejer[i] == -1) {
            maksimum = max(maksimum, dfs(i, graph, depth));
        }
    }
    cout << maksimum << endl;
    return 0;
}

    
