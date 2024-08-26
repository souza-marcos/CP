#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> grafo;
vector<bool> vis;

void bfs(int v){
    queue<int> q;
    q.push(v); vis[v] = true;

    while(!q.empty()){
        int w = q.front(); q.pop();
        cout << w << " ";

        for(auto el: grafo[w]){
            if(!vis[el]) {
                q.push(el);
                vis[el] = true;
            }
        }

    }

}

int main(){ _

    grafo = {{1}, {0, 3}, {3, 7}, {1, 2, 4, 5}, {3, 5}, {3, 4, 6}, {5, 7}, {2, 6}, {}};
    vis.resize(grafo.size(), false);

    for(int i = 0; i < grafo.size(); i ++){
        if(!vis[i]) bfs(i);
    }

    return 0;
} 
