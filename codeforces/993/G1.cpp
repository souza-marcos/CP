#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<int> g, comp, endpoint;
vector<int> dp;


bool dfs(int v, int id){
    comp[v] = id;
    if(comp[g[v]] == id) {
        endpoint[g[v]] = 1; 
        dp[v] = 0;
        return true;
    }
    else if (comp[g[v]] != -1) {
        dp[v] = dp[g[v]] + 1;
        return false;
    }
    else {
        bool in = dfs(g[v], id);
        if(in) dp[v] = 0;
        else dp[v] = dp[g[v]] + 1;

        if(in and endpoint[v] == 1) {
            return false;
        }
        else if(in) return true;

        return false;
    }
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    for(auto& el: g) cin >> el, el --;
    comp.assign(n, -1), endpoint.assign(n, 0);
    dp.assign(n, -1);


    int maxv = 0;
    for(int i = 0; i < n; i ++){
        if(comp[i] == -1) dfs(i, i);
    }
    for(auto el : dp) maxv = max(maxv, el);
    cout << maxv + 2 << endl;
}

int main(){ _

    int t; cin >> t;
    while(t -- ) solve();
    return 0;
} 
