// https://codeforces.com/problemset/problem/2031/D
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll


// -> Processa os caras do maior(mais a direita primeiro) para o menor, todo mundo que tiver a direita de mim e não foi processado ainda
// deve ter o meu valor(porque eu sou o maior atual, logo quem está a minha direita consegue me alcançar).
// - Fica guardado o maior valor que um cara menor que eu recebeu (se for 0 (ninguem foi processado) logo o melhor valor sou eu mesmo).

// 2 3 1 4
// - - - 4
// - 3 3 4
// 3 3 3 4 

// 1 1 3 1
// - - 3 3
// 1 1 3 3 

// 2 1 1 3
// - - - 3
// 2 2 2 3

const int MAX = 5e5+2;
namespace seg {
    int seg[4*MAX];

    void build(int p, int l, int r){
        if(l == r) return void(seg[p] = 0);
        int m = (l + r)/2;
        build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
        seg[p] = 0;
    }

    int query(int p, int l, int r, int lq, int rq) {
        if(lq <= l and r <= rq) return seg[p];
        if(l > rq or r < lq) return 0;
        int m = (l + r)/2;
        return max(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m + 1, r, lq, rq));
    }

    int update(int p, int l, int r, int pos, int val){
        if(l == r and l == pos) return seg[p] = val;
        if(l > pos or r < pos) return seg[p];
        int m = (l + r)/2;
        return seg[p] = max(update(p << 1, l, m, pos, val), update(p << 1| 1, m + 1, r, pos, val));
    }
};

void solve(){
    int n; cin >> n;
    vector<int> arr(n); 
    vector<pair<int, int>> to_process;
    int i = 0;
    for(int &el : arr) cin >> el, to_process.push_back({el, i ++});

    sort(to_process.rbegin(), to_process.rend());

    seg::build(1, 0, n-1);

    vector<int> res(n, -1);
    for(auto [val, pos] : to_process){
        // cout << val << " " << pos << endl; 
        if(res[pos] == -1){
            int mx = seg::query(1, 0, n-1, 0, val-1);
            // cout << val -1 << " => " << mx << endl;
            if(mx == 0) res[pos] = val;
            else res[pos] = mx;
        
            seg::update(1, 0, n-1, val, res[pos]);
            for(int i = pos+1; i < n and res[i] == -1; i ++){
                res[i] = res[pos];
                seg::update(1, 0, n-1, arr[i], res[i]);
            }
        }

        // for(int el: res) cout << el << " ";
        // cout << endl;
    }

    for(int i : res) cout << i << ' ';
    cout << endl;
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t--) solve();
} 
