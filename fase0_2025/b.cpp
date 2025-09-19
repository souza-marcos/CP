#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int) x.size()

int32_t main() { _

    int n ; cin >> n;
    vector<vector<pair<int, char>>> g(n);
    vector<int> arr(n-1);
    string s;
    for(auto& el : arr) cin >> el, el --;
    cin >> s;

    for(int i = 1; i < n; i ++){
        g[arr[i-1]].push_back({i, s[i-1]});
    }

    string cur_str;
    vector<int> pi(n);

/*

pi function
for(int i = 1, j = 0; i < n; i ++){
    while(j > 0 and str[i] != str[j]) j = pi[j-1];
    if(str[i] == str[j]) j ++;
    pi[i] = j;
}

*/
    // Vou ter que computar o automato antes.
    
    vector<vector<int>> automato(26, vector<int>(n, 0));

    int maxv = 0;
    auto dfs = [&](auto&& self, int v, char next) -> void {
        cur_str.push_back(next);
        int i = sz(cur_str) - 1;
        if(i == 0) {
            pi[0] = 0;
            
            for(int c = 0; c < 26; c ++) 
                automato[c][0] = 0;
            automato[cur_str.back()-'a'][0] = 1;
        }else {

            // int j = pi[i-1];
            // while(j > 0 and cur_str[i] != cur_str[j]) j = pi[j-1];
            // if(cur_str[i] == cur_str[j]) j++;
            // pi[i] = j;

            // cout << cur_str << endl;
            pi[i] = automato[cur_str[i]-'a'][pi[i-1]];
            for(int c = 0; c < 26; c ++){
                automato[c][i] = (c == (cur_str.back()-'a')? i+1: automato[c][pi[i-1]]);
                // cout << (char)('a' + c) << " " << automato[c][i] << endl;
            }

            int k = sz(cur_str) - pi[i];
            int per = (k < sz(cur_str) and sz(cur_str)%k == 0? k : 0);
            maxv = max(maxv, per);
        }

        for(auto [u, label] : g[v]){
            self(self, u, label);
        }
        cur_str.pop_back();
    };

    for(auto [i, label] : g[0])
        dfs(dfs, i, label);

    cout << maxv << endl;

    return 0;
}