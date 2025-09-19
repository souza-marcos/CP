#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 501;
int memo[MAX][MAX];
vector<int> arr;

int dp(int i, int j){
    int& p = memo[i][j];
    if(p != -1) return p;
    if(i == j) return p = 1;
    if(i > j) return p = 0;

    int mn = 1 + dp(i + 1, j);
    if(arr[i] == arr[i+1]) mn = min(mn, 1 + dp(i + 2, j));
    for(int k = i + 2; k <= j; k ++){
        if(arr[k] == arr[i]){
            mn = min(mn, dp(i+1, k-1) + dp(k + 1, j));
        }
    }
    return p = mn;
}


int32_t main(){

    int n; cin >> n;
    arr.resize(n);
    for(int& el : arr) cin >> el;

    memset(memo, -1, sizeof memo);
    cout << dp(0, n-1) << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < n; j ++){
    //         cout << memo[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

