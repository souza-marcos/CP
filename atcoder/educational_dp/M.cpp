#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()
const int MAXK = 1e5;
const int MOD = 1e9 + 7;

ll memo[101][MAXK + 1];
ll sum[101][MAXK + 1];

int main(){ _
    int n, k;
    cin >> n >> k;
    vector<int> a(n); for(int& el : a) cin >> el;

    memo[0][0] = 1, sum[0][0] = 1;
    for(int i = 1; i <= a[0]; i++){
        memo[0][i] = 1; 
        sum[0][i] = sum[0][i-1] + 1 ;
        if(sum[0][i]>= MOD) sum[0][i] -= MOD;
    }
    for(int i = a[0] + 1; i <= k; i ++) sum[0][i] = sum[0][i-1];

    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= k; j ++){
            int l = j-a[i]-1;
            memo[i][j] = (sum[i-1][j] - (l >= 0? sum[i-1][l] : 0) + MOD) % MOD;
            sum[i][j] = memo[i][j] + (j>0?sum[i][j-1]:0);
            if(sum[i][j] >= MOD) sum[i][j] -= MOD;
        }
    }
    cout << memo[n-1][k] << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j <= k; j ++){
    //         cout << memo[i][j] << " ";
    //     }cout << endl;
    // }
    // cout << "__________________\n";
    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j <= k; j ++){
    //         cout << sum[i][j] << " ";
    //     }cout << endl;
    // }

    return 0;
} 
    