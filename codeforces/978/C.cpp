#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int MAXN = 1e5 + 10;
bool arr[2][MAXN];
vector<vector<int>> memo;


// wh : 0 = Cheia, 1 = primeiro ativado, 2 = segundo ativado
int dp(int i, int wh){
    if(i < 0) return -INF;
    if(i == 0) return ((wh == 0)? 0: -INF);

    int& p = memo[i][wh];
    if(p != -1) return p;

    int maxv = -INF;
    if(i >= 2 and (wh == 0)) {
        maxv = max(maxv, dp(i-2, 1) + ((arr[0][i-1] + arr[0][i-2] + arr[1][i-1]) >= 2));
        maxv = max(maxv, dp(i-2, 2) + ((arr[0][i-1] + arr[1][i-1] + arr[1][i-2]) >= 2));
    }
    
    if (i >= 1 and wh == 1) {
        maxv = max(maxv, dp(i-1, 0) + ((arr[0][i-1] + arr[1][i] + arr[1][i-1]) >= 2));
    }
    
    if(i >= 1 and wh == 2){
        maxv = max(maxv, dp(i-1, 0) + ((arr[0][i] + arr[0][i-1] + arr[1][i-1]) >= 2));
    }
    
    if(i >= 3 and wh == 0){ // block h-3
        maxv = max(maxv, dp(i-3, 0) + ((arr[0][i-1] + arr[0][i-2] + arr[0][i-3]) >= 2) + ((arr[1][i-1] + arr[1][i-2] + arr[1][i-3]) >= 2));
    }
    
    if(i >= 3 and wh == 1){
        maxv = max(maxv, dp(i-3, 1) + (((arr[0][i-1] + arr[0][i-2] + arr[1][i-3]) >= 2)) + ((arr[1][i] + arr[0][i-1] + arr[1][i-2]) >= 2));
    }
    
    if(i >= 3 and wh == 2){
        maxv = max(maxv, dp(i-3, 2) + (((arr[0][i] + arr[0][i-1] + arr[1][i-2]) >= 2)) + ((arr[1][i-1] + arr[0][i-2] + arr[1][i-3]) >= 2));
    }

    return p = maxv;
}

int pd(int i, int wh){
    if(i < 0) return -INF;
    if(i == 0) return ((wh == 0) ? 0 : -INF);

    int& p = memo[i][wh];
    if(p != -1) return p;

    int maxv = -INF;
    
    if (wh == 0) {
        if (i >= 3) maxv = max(maxv, dp(i - 3, 0) + ((arr[0][i-1] + arr[0][i-2] + arr[0][i-3]) >= 2) + ((arr[1][i-1] + arr[1][i-2] + arr[1][i-3]) >= 2));
        if (i >= 2) {
            maxv = max(maxv, dp(i - 2, 1) + ((arr[0][i-1] + arr[0][i-2] + arr[1][i-1]) >= 2));
            maxv = max(maxv, dp(i - 2, 2) + ((arr[1][i-1] + arr[1][i-2] + arr[0][i-1]) >= 2));
        }
    }
    
    if (wh == 1 and i >= 1) maxv = max(maxv, dp(i - 1, 0) + ((arr[0][i-1] + arr[1][i] + arr[1][i-1]) >= 2));

    if (wh == 2 && i >= 1) maxv = max(maxv, dp(i - 1, 0) + ((arr[0][i] + arr[0][i-1] + arr[1][i-1]) >= 2));
    
    return p = maxv;
}


void solve(){
    int n; cin >> n;
    for(int i = 0; i < 2; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++){
            arr[i][j] = s[j] == 'A';
        }
    }
    memo.assign(n + 1, vector<int>(3, -1));
    cout << pd(n, 0) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
