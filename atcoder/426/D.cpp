#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    auto calc = [&](string s) -> ll {
        vector<int> pref(n);
        pref[0] = s[0] == '1';
        for(int i = 1; i < n; i ++){
            pref[i] = pref[i-1] + (s[i] == '1');
        }
        // Numero de 1's * 2 + 0's

        vector<pair<int, int>> aux;
        for(int i = 0; i < n; i ++){
            if(s[i] == '1') continue; // TO transformando em UM

            int left = (i > 0? pref[i-1]: 0);
            int right = (pref[n-1] - pref[i]);
            
            aux.push_back({left * 2 + (i-left), right * 2 + (n-i-1-right)*1});
        }
        if(sz(aux) == 0) return 0ll;

        int l = 0;
        while(l < sz(aux) and aux[l].first < aux[l].second) l ++;
        if(l == 0) return aux[l].second;
        if(l == sz(aux)) return aux.back().first;
        return aux[l].second + aux[l-1].first;
    };  
    int val = calc(s);
    for(auto& el : s) el = (el == '1'? '0' : '1');
    val = min(val, calc(s));
    cout << val << endl;
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
