#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
bool vis[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comp.push_back(i);

            // iterative DFS
            stack<int> st;
            st.push(i);
            vis[i] = true;

            while (!st.empty()) {
                int node = st.top();
                st.pop();

                for (int next : adj[node]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        st.push(next);
                    }
                }
            }
        }
    }

    cout << comp.size() - 1 << "\n";

    for (int i = 1; i < comp.size(); i++) {
        cout << comp[i - 1] << " " << comp[i] << "\n";
    }

    return 0;
}