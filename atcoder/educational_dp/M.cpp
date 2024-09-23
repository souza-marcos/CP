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

vector<vector<ll>> memo;
vector<int> arr;
int n, k; 

ll dp(int i, int cap){
    if(i >= n) return (cap == 0);
    if(cap < 0) return 0;
    ll& p = memo[i][cap];

    ll val = 0;
    for(int j = min(arr[i], cap); j >= 0; j --){
        val += dp(i + 1, cap - j);
        if(val >= MOD) val -= MOD;
    }
    return p = val;    
}

int main(){ _
    cin >> n >> k;
    arr.resize(n);
    for(int& el: arr) cin >> el;
    memo.assign(n+1, vector<ll>(k + 1, -1));
    cout << dp(0, k) << endl;
    return 0;
} 
    