#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int ctot, m, c0, d0;
int memo[11][1010];
int a[110], b[110], c[110], d[110];

int dp(int i, int c_res){
    if(c_res < 0) return -INF;
    if(i == -1){ // Sem cobertura
        int each = c_res/c0;
        return each * d0;
    }
    int& p = memo[i][c_res];

    if(p != -1) return p;
    int each = min(c_res/c[i], a[i]/b[i]);

    int max_val = -INF;
    for(int k = 0; k <= each; k++){
        max_val = max(max_val, dp(i - 1, c_res - k * c[i]) + k * d[i]);
    }
    return p = max_val;
}

int main(){ _
    
    cin >> ctot >> m >> c0 >> d0;
    for(int i =0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    memset(memo, -1, sizeof memo);
    cout << dp(m - 1, ctot) << endl;

    // for(int i = 0; i < 11; i ++) for(int j = 0; j < 1010; j ++) cout << memo[i][j] << " \n"[j == ctot -1]; 

    return 0;
} 
