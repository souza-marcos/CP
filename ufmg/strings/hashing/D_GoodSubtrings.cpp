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
    const int p1 = 31; 
    const int m1 = 1e9 + 9, m2 = 98'765'432;
    vector<ll> ppi;
    vector<pair<ll, ll>> pref;
    hash_str(string &s){
        pref.resize(sz(s)), ppi.resize(sz(s));
        ppi[0] = 1, pref[0] = {s[0]-'a' + 1, s[0]-'a' + 1};
        for(int i = 1; i < sz(s); i ++){
            ppi[i] = (ppi[i-1] * p1) % m2;
            auto [f, se] = pref[i-1];
            pref[i] = {
                (f * p1 + s[i]-'a'+1) % m1,
                (se * p1 + s[i]-'a' + 1) % m2
            };
        }
    } 

    pair<ll, ll> substr(int l, int r){
        assert(l >= 0 and r < sz(pref) and l <= r);
        ll val1 = pref[r].first - (l ? (pref[l-1].first * ppi[r-l+1] % m1): 0);
        ll val2 = pref[r].second - (l ? (pref[l-1].second * ppi[r-l+1] % m2): 0);
        return { (val1 + m1) % m1, (val2 + m2) % m2};
    }
};



int main(){ _
    string s; cin >> s;
    vector<bool> bad(26);
    string a; int i =0;
    for(auto c : s) bad[i] = (c == '0'), i ++;
    int k; cin >> k;


    vector<int> pre(sz(s) + 1);
    pre[0] = 0;
    for(int i = 1; i <= sz(s); i ++)
        pre[i] = pre[i-1]+bad[s[i]-'a'];

    set<pair<ll, ll>> good_s;
    hash_str hs(s);

    for(int i = 0; i < sz(s); i ++){
        for(int j = i; j < sz(s); j++){
            if(pre[j + 1] - pre[i] <= k) 
                good_s.insert(hs.substr(i, j));
        }
    }
    cout << sz(good_s) << endl;
    return 0;
} 
