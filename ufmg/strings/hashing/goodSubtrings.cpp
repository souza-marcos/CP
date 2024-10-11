#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;
const ll pol = 13331;
const int MAX = 1510;

ll hashm[MAX];
ll pmod[MAX];

int main(){ _
    string s, a; cin >> s >> a;
    int k; cin >> k;
    vector<int> pref(sz(s) + 1);
    pref[0] = 0;
    hashm[0] = 0; pmod[0] = 1; 
    for(int i = 0; i < sz(s); i ++){
        hashm[i + 1] = hashm[i] + (s[i] - 'a' + 1) * pmod[i];
        if(hashm[i + 1] >= MOD) hashm[i + 1] %= MOD;

        pmod[i + 1] = pmod[i] * pol;
        if(pmod[i + 1] >= MOD) pmod[i + 1] %= MOD;

        pref[i + 1] = pref[i] + (a[s[i] - 'a'] == '1');
    }

    map<ll, bool> cnt;
    int res = 0;
    for(int i = 1; i <= sz(s); i ++){
        for(int j = i; j <= sz(s); j ++){
            if(pref[j] - pref[i-1] <= k){
                cout << pref[j] - pref[i-1] << " => " << s.substr(i, j-i+1) ;
                ll val = (hashm[j] - hashm[i-1] * pmod[j-i+1]) %MOD;
                cout << " " << val << endl;
                if(!cnt.count(val)) cnt[val] = 1, res ++;
            }else break;
        }
    }
    cout << res << endl;

    return 0;
} 
