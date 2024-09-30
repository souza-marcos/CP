#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;
int n; 
vector<vector<bool>> arr;
int memo[21][1 << 21];

int dp(int i, int used){
    if(used == (1 << n)-1 and i == n) return 1;
    if(i >= n) return 0;

    int &p = memo[i][used];
    if(p != -1) return p;

    ll val = 0;
    for(int j=0; j<21; j ++){
        if(used & (1 << j)) continue;
        if(arr[i][j]) val += dp(i + 1, used | (1 << j));
        if(val >= MOD) val -= MOD;
    }
    return p = val;
}

int main(){ _
    cin >> n;
    memset(memo, -1, sizeof memo);
    arr.assign(n, vector<bool>(n));
    int el = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) cin >> el, arr[i][j] = el;
    }
    cout << dp(0, 0) << endl;
    return 0;
} 
