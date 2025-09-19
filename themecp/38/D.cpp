// https://codeforces.com/problemset/problem/1779/D
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll
   
const int MAX = 2e5 + 10;

namespace seg {
    int seg[4 * MAX], lazy[4 * MAX];

    int build(int p, int l, int r, vector<int> &v){
        lazy[p] = LINF;
        if(l == r) return seg[p] = v[l];
        int m = (l + r)/2;
        return seg[p] = max(build(p << 1, l, m, v), build(p << 1 | 1, m + 1, r, v));
    }

    void prop(int p, int l, int r){
        if(lazy[p] == LINF) return;
        seg[p] = min(seg[p], lazy[p]);
        if(l != r) lazy[p << 1] = min(lazy[p << 1], lazy[p]), lazy[p << 1 | 1] = min(lazy[p << 1 | 1], lazy[p]);
        lazy[p] = LINF;
    }

    int query(int p, int l, int r, int lq, int rq){
        prop(p, l, r);
        if(lq <= l and rq >= r) return seg[p];
        if(l > rq or r < lq) return 0;
        int m = (l + r)/2;
        return max(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m + 1, r, lq, rq));
    }

    int update(int p, int l, int r, int lu, int ru, int val){
        prop(p, l, r);
        if(l >= lu and r <= ru){
            lazy[p] = val;
            prop(p, l, r);
            return seg[p];
        }
        if(r < lu or l > ru) return seg[p];
        int m = (l + r)/2;
        return seg[p] = max(update(p << 1, l, m, lu, ru, val), update(p << 1 | 1, m + 1, r, lu, ru, val));
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int& el : a) cin >> el;

    vector<pair<int, int>> to_process;

    int i = 0;
    for(int& el : b) {
        cin >> el;
        to_process.push_back({el, i ++ });
    }
    
    int m; cin >> m;
    multiset<int> razors;
    for(int i = 0; i < m; i ++){
        int a; cin >> a;
        razors.insert(a);
    }
    
    // Quero processar os caras maiores primeiro. Mantem next (indice do cara maior que eu).
    // Se não processei um cara e o valor atual é maior do que o final, tenho que usar uma lamina.
    
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]) return void(cout << "No" << endl);
    }
    
    vector<int> st, next(n, n);
    for(int i = 0; i < n; i++){
        while(sz(st) > 0 and b[st.back()] < b[i]){
            next[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }

    seg::build(1, 0, n-1, a);

    sort(to_process.begin(), to_process.end(), [&](auto& a, auto& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    multiset<int> quero;
    for(auto [val, idx] : to_process){
        int ai = seg::query(1, 0, n-1, idx, idx);
        if(ai == b[idx]) continue;
        int to = next[idx]-1;
        seg::update(1, 0, n-1, idx, to, b[idx]);
        quero.insert(b[idx]);
    }

    // for(int i : quero) cout << i << " ";
    // cout << endl;


    for(int el : quero){
        auto it = razors.find(el);
        if(it == razors.end()) return void(cout << "No" << endl);
        razors.erase(it);
    }
    cout << "Yes\n";
}

int32_t main(){_ 
    int t; cin >> t;
    while(t --) solve();
}