#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
int n;
vector<int> g, vis;
int cnt;

int dfs(int v){
    vis[v] = cnt;
    if(vis[g[v]] < cnt) return dfs(g[v]) + 1;
    return 1;
}

int main(){ _
    cin >> n;
    g.resize(n);
    vis.resize(n, 0);
    for(int &el: g) cin >> el, el --;

    int ans = 0, cnt = 1;
    for(int i = 0; i < n; i++){
        ans += dfs(i) + 1;
        cnt ++;
    }

    cout << ans << endl;
    return 0;
} 
