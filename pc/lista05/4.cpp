#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

// implementar uma segtree de frequencia 

vector<array<int, 9>> seg;
vector<int> lazy;

void unlazy(int p, int l, int r){
    if(lazy[p] == 0) return;

    if(l != r) lazy[p << 1] += lazy[p], lazy[p << 1 | 1] += lazy[p];
    
    array<int, 9> aux = seg[p];
    for(int i = 0; i < 9; i ++){
        int pos = (i + lazy[p]) % 9;
        seg[p][pos] = aux[i];
    }

    lazy[p] = 0;
}
#define arri9 array<int, 9>

void combine(arri9& a, arri9& b, arri9& c){
    for(int i = 0; i < 9; i ++)
        c[i] = a[i] + b[i];
}

void build(int p, int l, int r){
    lazy[p] = 0;
    if(l == r) { seg[p][1] = 1; return; } 
    int m = (l + r)/2;
    build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
    combine(seg[p << 1], seg[p << 1 | 1], seg[p]);
}

void update(int p, int l, int r, int lu, int ru, int val){
    unlazy(p, l, r);

    if(ru < l or r < lu) return;
    if(lu <= l and r <= ru){
        lazy[p] += val;
        unlazy(p, l, r);
        return;
    }


    int m = (l + r)/2;
    update(p << 1, l, m, lu, ru, val), update(p << 1 | 1, m+1, r, lu, ru, val);
    combine(seg[p << 1], seg[p << 1 | 1], seg[p]);
}

array<int, 9> query(int p, int l, int r, int lq, int rq){
    unlazy(p, l, r);
    
    if(lq > r or rq < l) return array<int, 9>();
    if(lq <= l and rq >= r) return seg[p];

    int m = (l + r)/2;
    auto left = query(p << 1, l, m, lq, rq), right = query(p << 1 | 1, m + 1, r, lq, rq);
    array<int, 9> res;
    combine(left, right, res);
    return res;
}

void solve(int p, int l, int r){
    unlazy(p, l, r);
    if(l == r) {
        for(int i = 0; i < 9; i++) 
            if(seg[p][i] != 0) { 
                cout << i << endl; 
                return; 
            } 
    }
    int m = (l + r)/2;
    solve(p << 1, l, m), solve(p << 1 | 1, m + 1, r);
}

int main(){ _
    int n, q; cin >> n >> q;
    seg.assign(4 * n, array<int, 9>{0, 0, 0, 0, 0, 0, 0, 0, 0});
    lazy.assign(4 * n, 0);
    build(1, 0, n-1);
    while(q --) {
        int a, b; cin >> a >> b;
        auto val = query(1, 0, n-1, a, b);
        int times = -1, number = 0;
        for(int i = 0; i < 9; i ++){
            if(val[i] >= times) times = val[i], number = i;
        }
        update(1, 0, n-1, a, b, number);
    }   

    solve(1, 0, n-1);

    return 0;
} 
