#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define ss second 
#define ff first 
#define sz(x) (int)x.size()

int32_t main() { _
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pref;
    pref.push_back(0);
    for(int i = 0; i < sz(s); i ++){
        pref.push_back(pref.back() + (s[i] == '.'));
    }
    k = min(k, pref.back());
    string res(sz(s), '.');
    res[sz(s)-1] = '#';
    
    int cur = k;
    res[cur] = '#';
    for(int i = 0; i < n; i ++){
        if(s[i] == 'o') {
            res[i + cur] = 'o';
        }else if(s[i] == '.') cur --;
        cur = max(0ll, cur);
    }
    cout << res << endl;
}