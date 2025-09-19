#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    
    int n; ll d; cin >> n >> d;
    vector<pair<ll, int>> st;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        if(a > 0) st.push_back({a, i});
    }
    sort(st.rbegin(), st.rend());

    if(sz(st) == 0){

        cout << -1 << endl;
        exit(0);
    }

    if(sz(st) == 1 and st[0].first < d){
        cout << -1 << endl;
        exit(0);
    }

    vector<ll> res;

    int cur = 0;
    while(d > 0){
        for(int i = 0; i < min(d, st[cur].first); i ++) res.push_back(st[cur].second);
        d -= st[cur].first;
        cur ^= 1;
    }

    for(auto el : res) cout << el + 1 <<  " ";
    cout << endl;
}