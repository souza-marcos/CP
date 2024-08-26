#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4 +10;
vector<vector<int>> g(MAX);
int dis[MAX];

pair<int, int> max_node = {-1, -1} ;

void dfs(int s){
    for(auto el: g[s]){
        if(dis[el] == -1){
            dis[el] = dis[s] + 1;
            if(max_node.second < dis[el]) max_node = {el, dis[el]};
            dfs(el);
        }
    }
}

int main(){ _
    memset(dis, -1, sizeof dis);

    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a); 
    }

    dis[0] = 0;
    dfs(0);
    memset(dis, -1, sizeof dis);
    int node = max_node.first;
    max_node = {-1, -1};
    dfs(node);
    
    cout << max_node.second + 1 << endl;
    
    return 0;
} 
