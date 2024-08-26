#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<pair<int, int>> musics;
int memo[16][1 << 16];
int n;

int dp(int last, int mask){
    if(__builtin_popcount(mask) >= n) return 0;

    int& p = memo[last][mask];
    if(p != -1) return p;

    int maxval = 0;
    for(int i = 0; i < n; i ++){
        if(mask & (1 << i)) continue; // ja usei
        auto [gf, af] = musics[last];
        auto [gs, as] = musics[i];

        if(gf == gs or af == as) maxval = max(maxval, dp(i, mask | (1 << i)) + 1);
    }

    return p = maxval;
}

void solve(){
    map<string, int> dict;
    cin >> n;
    musics.resize(n);
    memset(memo, -1, sizeof memo);

    int cnt = 0;
    for(int i = 0; i < n ; i++){
        string g, w;
        cin >> g >> w;
        if(!dict.count(g)) dict[g] = cnt ++;
        if(!dict.count(w)) dict[w] = cnt ++;
    
        musics[i] = {dict[g], dict[w]};
    }

    int maxval = 0;
    for(int i = 0; i < n; i ++){
        maxval = max(maxval, dp(i, 1 << i));
    }
    cout << n - maxval -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
