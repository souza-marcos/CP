#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    string s; cin >> s;
    vector<vector<int>> pref(sz(s) + 1, vector<int>(26, 0));
    for(int i = 0; i < sz(s); i ++){
        for(int j = 0; j < 26; j ++)
            pref[i + 1][j] = pref[i][j];

        pref[i + 1][s[i]-'A'] ++;  
    }

    ll cnt = 0;
    for(int i = 1; i < sz(s)-1; i ++){
        for(int j = 0; j < 26; j ++){
            cnt += 1LL * pref[i][j] * (pref[sz(s)][j] - pref[i + 1][j]);
        }
    }
    cout << cnt << endl;
    
    return 0;
} 
