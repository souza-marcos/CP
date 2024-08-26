#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

map<string, int> dict;
vector<pair<int, int>> v;
int memo[16][1 << 16];
int n;

int dp(int el, int mask){
    if(__builtin_popcount(mask) >= n) return 0;

    int& p = memo[el][mask];
    if(p != -1) return p;

    int min_val = INF;
    for(int i = 0; i < n; i++){
        if((1 << i) & mask) continue; // já usei

        if(v[el].first == v[i].first or v[el].second == v[i].second)
            min_val = min(min_val, dp(i, (1<<i)|mask));
    }

    if(min_val == INF) return p = n - __builtin_popcount(mask);
    return p = min_val;
}

void solve(){
    cin >> n;
    v.assign(n, {});
    dict.clear();

    int cnt = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(!dict.count(s)) dict[s] = cnt ++; 
        v[i].first = dict[s];

        cin >> s;
        if(!dict.count(s)) dict[s] = cnt ++; 
        v[i].second = dict[s];
    }
    // cout << "__________________\n";
    // for(auto [k, v] : dict) cout << k << "-> " << v << endl;
    // cout << "__________________\n";

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < (1 << n); j++){
    //         cout << memo[i][j] << " ";
    //     }cout << endl;
    // }

    memset(memo, -1, sizeof memo);
    int min_val = INF;
    for(int i =0; i < n; i++){
        min_val = min(min_val, dp(i, 1 << i));
    }
    cout << min_val << endl;


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
