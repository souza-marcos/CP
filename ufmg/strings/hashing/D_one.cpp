#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

struct hash_str{
    const int p = 31; 
    const int m = 98'765'432;
    vector<ll> ppi;
    vector<ll> pref;
    hash_str(string &s){
        pref.resize(sz(s)), ppi.resize(sz(s));
        ppi[0] = 1, pref[0] = s[0]-'a' + 1;
        for(int i = 1; i < sz(s); i ++){
            ppi[i] = (ppi[i-1] * p) % m;
            pref[i] = (pref[i-1] * p + s[i]-'a'+1) % m;
        }
    } 

    ll substr(int l, int r){
        assert(l >= 0 and r < sz(pref) and l <= r);
        ll val = pref[r] - (l ? (pref[l-1] * ppi[r-l+1] % m): 0);
        return (val + m) % m;
    }
};



int main(){ _
    string s; cin >> s;
    vector<bool> bad(26);
    string a; cin >> a;
    for(int i =0; i < 26; i ++){
        bad[i] = (a[i] == '1');
    }
    int k; cin >> k;


    vector<int> pre(sz(s) + 1);
    pre[0] = 0;
    for(int i = 1; i <= sz(s); i ++)
        pre[i] = pre[i-1]+bad[s[i]-'a'];

    set<ll> good_s;
    hash_str hs(s);

    for(auto el: pre) cout << el << " ";
    cout << endl;

    for(int i = 0; i < sz(s); i ++){
        for(int j = i; j < sz(s); j++){
            int bval = pre[j] - pre[i];
            if(bval <= k){
                ll val = hs.substr(i, j);
                if(!good_s.count(val))
                    cout << bval << " " << s.substr(i, j-i+1) << endl, 
                    good_s.insert(val);
            }
        }
    }
    cout << sz(good_s) << endl;
    return 0;
} 
