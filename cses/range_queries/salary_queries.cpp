#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 6e5 + 10;

// Instead to response the queries on the fly we see all the queries first to get the different positions
// and do so a index compression 

vector<ll> fenwick;

void update(int k, int delta){
    for(int i = k; i < sz(fenwick); i = i | (i + 1))
        fenwick[i] += delta;
}
ll query(int a, int b){
    auto qq = [&](int k) -> ll {
        ll res = 0;
        while(k >= 0){
            res += fenwick[k];
            k = (k & (k + 1)) -1;
        }
        return res;
    };
    return qq(b) - qq(a-1);
}

int main(){ _

    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    
    vector<ll> els;
    for(auto& el : arr) {
        cin >> el;
        els.push_back(el);
    }
    vector<tuple<ll, ll, ll>> queries;

    while(q --){
        string t; cin >> t;
        ll a, b; cin >> a >> b;
        queries.push_back({t[0]=='?', a, b}); // 0 -> !, 1 -> ? 
        if(t[0]=='?'){
            els.push_back(a), els.push_back(b);
        }
        else{
            els.push_back(b);
        }
    }

    sort(els.begin(), els.end());
    els.erase(unique(els.begin(), els.end()), els.end());

    auto dict = [&](ll to_search) -> int {
        return lower_bound(els.begin(), els.end(), to_search) - els.begin();
    };  

    // build fenwick tree on the range of els
    fenwick.assign(sz(els) + 1, 0);
    for(ll el : arr)
        update(dict(el), +1);
    
    for(auto [t, a, b] : queries){

        if(t == 1){ // ?
            cout << query(dict(a), dict(b)) << endl;
        }
        else {
            a --;
            update(dict(arr[a]), -1);
            arr[a] = b;
            update(dict(arr[a]), +1);
        }
    }
    return 0;
} 
