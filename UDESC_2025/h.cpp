#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define ss second 
#define ff first 
#define sz(x) (int)x.size()

vector<int> v(5e5+10);
vector<vector<int>> adj(v.size());
vector<int> dpc(v.size()),dps(v.size());

void dfs(int i,int p=-1) {
    int sum=v[i],best=0;
    for(int u:adj[i]) {
        if(u==p) continue;
        dfs(u,i);
        sum+=dpc[u];
        if(max(dps[u],dpc[u])>0) best+=max(dps[u],dpc[u]);
    }

    dpc[i] = sum;
    dps[i] = best;
    if(dps[i]<0) dps[i] = 0;
}

int32_t main() { _
	int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=1;i<n;i++) {
        int si;
        cin >> si;
        adj[si-1].push_back(i);
        // adj[si].push_back(i-1);
    }

    dfs(0);
    cout << max({0LL,dps[0],dpc[0]}) << '\n';
    return 0;
}