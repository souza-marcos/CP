#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n, life;
int memo[1010][2010];
vector<pair<int, int>> v;

int dp(int i, int j){
    if(j <= 0) return 0;
    if(i == n) return INF;
    
    int& p = memo[i][j];
    if(p != -1) return p;
    return p = min(dp(i + 1, j), dp(i + 1, j - v[i].first) + v[i].second);
}

void solve(){
    memset(memo, -1, sizeof(int) * 1010 * 2010);
    v.assign(n, {});
    for(auto& [dano, mana] : v) cin >> dano >> mana;

    int res = dp(0, life);
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
}

int main(){_
    while(cin >> n >> life) solve();

    return 0;
}