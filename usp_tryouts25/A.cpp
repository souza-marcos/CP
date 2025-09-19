#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    int n;
    cin >> n;

    vector<pair<int,int>> dp(2*n);
    map<int,pair<int,int>> m;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) {
        cin >> v[i];
        if(m.count(v[i])) m[v[i]].ss = i;
        else m[v[i]] = make_pair(i,0);
    }

    dp.push_back({0,0});
    for(int i=2*n-2;i>=0;i--) {
        if(m[v[i]].ss==i) dp[i] = dp[i+1];
        else {
            int p = m[v[i]].ss;
            auto c = make_pair(1+dp[p+1].ff,p-i+dp[p+1].ss);
            auto nc = dp[i+1];
            if(c.ff>nc.ff) dp[i] = c;
            else if(nc.ff>c.ff) dp[i] = nc;
            else if(c.ss<=nc.ss) dp[i] = c;
            else dp[i] = nc;
        }
    }

    cout << dp.front().ff << ' ' << dp.front().ss << '\n';
}