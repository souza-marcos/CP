#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> gr;
vector<bool> vis;
int n, m;

void dfs(int v){
    vis[v] = true;
    for(auto w: gr[v])
        if(!vis[w]) dfs(w);
}


int main(){ _
    
    int n, m; cin >> n >> m;
    gr.resize(n); // n alunos
    vis.resize(n, false);

    while(m --){
        int i, j; cin >> i >> j;
        i --, j--;      
        gr[i].push_back(j);
        gr[j].push_back(i);
    }
    int times = 0;
    for(int i = 0; i < n ; i++){
        if(!vis[i]){
            times ++;
            dfs(i);
        }
    }


    cout << times << endl;

    return 0;
} 
