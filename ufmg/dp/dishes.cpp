#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXMASK (1 << 18)
#define MAXN 20
int n, m, k;

int rules[MAXN][MAXN];
int dishes[MAXN];

ll dp[MAXMASK][MAXN];

// MAIOR satisfação 
// pratos já exp, mascara(pratos comidos), ultimo prato
ll solve(int qtd, int mask, int last){
    if(qtd == m) return 0;

    ll &val = dp[mask][last];
    if(val >= 0) return val;

    ll maxval = 0;
    for(int i = 0; i < n; i++){
        if((mask >> i) & 1) continue; // ja comeu

        maxval = max(maxval, solve(qtd + 1, mask | (1 << i), i) + dishes[i] + rules[last][i]);
    }
    return val = maxval;
}


int main(){ _
    cin >> n >> m >> k;

    memset(dp, -1,  sizeof dp);

    // dishes
    for(int i = 0; i < n; i ++){
        cin >> dishes[i];
    }

    // rules
    for(int i = 0; i < k; i++){
        int x, y, c; cin >> x >> y >> c; 
        x --, y --;
        rules[x][y] = c;
    }

    ll maxval = 0;
    for(int i = 0; i < n; i++){
        maxval = max(maxval, solve(1, 1 << i, i) + dishes[i]);
    }
    cout << maxval << endl;

    return 0;
} 
