#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _
    int n, q; cin >> n >> q;
    vector<pair<int, int>> queries(q);
    set<pair<int, int>> st;

    vector<int> id(n), szo(n, 1);
    iota(id.begin(), id.end(), 0);
    vector<pair<int, int>> in(n);
    for(auto &[l, r] : in) cin >> l >> r;
    for(auto &[el, lado] : queries) cin >> el >> lado, st.insert({el, lado});

    function<int(int)> find = [&](int a) -> int {
        return id[a] = (id[a] == a ? a : find(id[a]));
    };

    auto uni = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        if(a == b) return;
        if(szo[a] < szo[b]) swap(a, b);
        id[b] = a;
        szo[a] += szo[b];
    };

    // grafo final.
    int cur = 0;
    for(auto [l, r] : in) {
        if(l != -1 and not st.count(make_pair(cur, 1)))
            uni(cur, l-1), cout << cur + 1 << " " << l << "\n" ;
        if(r != -1 and not st.count(make_pair(cur, 2)))
            uni(cur, r-1), cout << cur + 1 << " " << r << "\n" ;
        cur ++;
    }

    vector<int> res(n);
    for(int i = 0; i < n; i ++){
        if(find(i) == find(0)) res[i] = -1;
        else res[i] = INF;
    }

    for(int i = 0; i < n ; i ++) cout << find(i) << " ";
    cout << endl;

    reverse(queries.begin(), queries.end());
    int k = q;
    for(auto [el, lado] : queries){
        el --;
        if(lado == 1)
            uni(el, in[el].first-1);
        else uni(el, in[el].second-1);
        if(find(el) == find(0) and res[el] == 0)
            res[el] = k;
        k --;
    }

    for(auto el : res) cout << el << "\n";
    return 0;
} 
