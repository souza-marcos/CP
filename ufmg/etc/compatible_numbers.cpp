// https://codeforces.com/contest/165/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
int dp[1<<22];
int main(){ _
    int n; cin >> n;
    vector<int> arr(n); 
    for(int& el : arr){
        cin >> el;
        dp[el] = el;
    } 

    // Reduz a perguntar se existe y que eh submask de ((1 << 22)-1) ^ x

    for(int i = 0; i < 22; i ++){
        for(int mask = 0; mask < (1 << 22); mask ++){
            if(mask & (1 << i) and dp[mask] == 0){
                dp[mask] = dp[mask ^ (1 << i)]; 
            }
        }
    }

    for(int el : arr){
        int op = el ^ ((1 << 22)-1);
        if(dp[op]==0) cout << "-1 ";
        else cout << dp[op] << " ";
    }
    cout << endl;
    return 0;
} 
