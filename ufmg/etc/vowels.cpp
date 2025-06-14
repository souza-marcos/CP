// https://codeforces.com/contest/165/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

#pragma GCC optimize ("O3")

int dp[1<<24];
int main(){ _
    int n; cin >> n;

    // O problema nos dá n palavras e quer que respondemos a soma do 
    // quadrado dos quntidade de boas palavras dado um conjunto de vogais,
    // dentre todas os conjuntos de vogais possiveis.

    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        int msk =0;
        for(auto ch : s){
            msk |= 1 << (ch-'a');
        }
        dp[msk] += 1; // Se o conjunto escolhido | msk != 0 ent tem palavra boa
    }

    for(int i = 0; i < 24; i ++){
        for(int msk = 0; msk < (1 << 24); msk ++){
            if((msk>>i) & 1){
                dp[msk] += dp[msk ^ (1 << i)];
            }
        }
    }
    int res = 0;
    for(int msk = 0; msk < (1 << 24); msk ++){
        int op = msk ^ ((1<<24) -1); // dp[op] -> quantas não satisfazem as vogais
        ll val = n-dp[op];
        res ^= val * val;
    }
    cout << res << endl;
    return 0;
} 
