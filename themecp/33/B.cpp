#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<vector<int>> dp;
vector<vector<int>> prec_indices; 
string s, l, r; 

bool can(int i, int j){ // Consigo achar uma string que não está na primeira
    if(j < 0) return false; // eh subsequencia
    if(i < 0) return true; // n eh subsequencia

    if(dp[i][j] != -1) return dp[i][j];

    for(int index = l[j]; index <= r[j]; index ++){
        bool fliped_ans = true;

        auto& row = prec_indices[index];
        if(sz(row) > 0){
            auto it = lower_bound(row.begin(), row.end(), i+1);
            if(it-row.begin() > 0){
                --it;
                fliped_ans &= can((*it)-1, j-1);                
            }
        }
        // for(int k = 0; k < sz(row); k ++){
        //     if(row[k] > i) break;
        //     fliped_ans &= can(row[k]-1, j-1);
        // }

        if(fliped_ans){
            dp[i][j] = 1;
            return true;
        }
    }

    dp[i][j] = 0;
    return false;
}


void solve(){

    cin >> s;
    int m; cin >> m;
    cin >> l >> r;

    prec_indices.assign(60, {});
    for(int i = 0; i < sz(s); i ++){
        prec_indices[s[i]].push_back(i);
    }

    dp.assign(sz(s), vector<int>(m, -1));
    bool res = can(sz(s)-1, sz(l)-1);
    cout << (res ? "YES\n": "NO\n");
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
