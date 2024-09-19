#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()


int main(){ _
    cout << fixed << setprecision(15);
    int n; cin >> n;
    vector<double> arr(n); for(auto& el: arr) cin >> el;
    
    double memo[n + 1][n + 1];
    memset(memo, 0, sizeof memo);

    memo[0][0] = 1; // prob of i heads in j first tosses
    for(int j = 1; j <= n; j ++) memo[0][j] = memo[0][j-1] * (1-arr[j-1]);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            memo[i][j] = memo[i][j-1] * (1 - arr[j-1]) + memo[i-1][j-1]*arr[j-1];
        }
    }
    double res = 0;
    for(int i = n; i >= ceil(n/2.0); i--)
        res += memo[i][n];

    // for(int i = 0; i <= n; i ++){
    //     for(int j = 0; j <= n; j ++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }

    cout << res << endl;

    return 0;
} 
