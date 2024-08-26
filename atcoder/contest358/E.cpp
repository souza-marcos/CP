#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;

int K;
vector<int> fact, ifact;

ll comb(int n, int r){
    return (fact[n] * ifact[r] % MOD )* ifact[n-r] %MOD;
}

int main() {
    cin >> K;
    fact.assign(K + 1, 1);
    ifact.assign(K + 1, 1);

    for(int i = 0; i < K; i++) fact[i + 1] = fact[i] * (i + 1) % MOD;
    ifact[K] = pow(fact[K], -1, MOD);

    for(int i = K; i > 0; i--) ifact[i-1] = ifact[i] * i % MOD;

    vector<int> C(26);
    for (int i = 0; i < 26; ++i) cin >> C[i];
    
    int dp[K][26];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j ++){
            for(int k = 0; k < min(C[i], K-j); i++){
               // dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * comb(j + k, k)) % MOD;
            }
        }
    }

    ll sum = 0;
    for(int j = 0; j < 26; j ++){
        sum = sum + dp[25][j] % MOD;
    }


    return 0;
}