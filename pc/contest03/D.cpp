#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

const int MAX = 2e5 + 10;

vector<int> v;
int memo[MAX];
int n; 

int dp(int i){
    if(i == n) return 0;
    if(i > n) return INF;
    int &p = memo[i];

    if(p != -1) return p;

    return p = min(dp(i + 1) + 1, dp(i + v[i] + 1));
}

void solve(){
    cin >> n;
    v.assign(n + 10, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    memset(memo, -1, sizeof(int) * (n + 10));

    cout << dp(0) << endl;

    // for(int i = 0; i < n; i++) cout << v[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i++) cout << memo[i] << " ";
    // cout << endl;
}

int main(){_
    int t; cin >> t;
    while(t --) solve();

    return 0;
}