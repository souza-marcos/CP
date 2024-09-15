#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<pair<int, int>> rect;
int n, k; 

int memo[1001][101];
int vis[1001][101];
int curit = 0;

int dp(int i, int j){
    if(j <= 0) return 0;
    if(i >= n) return INF;

    int& v = vis[i][j];
    int& p = memo[i][j];
    if(v == curit) return p;
    v = curit;

    int minval = dp(i + 1, j);
    auto [ai, bi] = rect[i];
    int tot = ai + bi;
    int costk = 0;
    for(int k = 1; k <= tot; k ++){
        if(ai <= bi) costk += ai, bi --;
        else costk += bi, ai --;
        minval = min(minval, dp(i + 1, j - k) + costk);
    }
    return p = minval;
}

void solve(){
    cin >> n >> k;
    rect.resize(n);
    for(auto& [a, b] : rect){
        cin >> a >> b;
    }
    int val = dp(0, k);
    if(val == INF) cout << -1 << endl;
    else cout << val << endl;
}

int main(){ _
    memset(vis, -1, sizeof vis);
    int t; cin >> t;
    while(t --) solve(), ++curit;
    return 0;
} 
