#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

const int MAX = 1e5 + 10;

int arr[MAX];
int seg[4 * MAX];
int lz[4 * MAX];


// Propagation of deltas
void unlazy(int p, int a, int b){

    if(lz[p] == 0) return; // Nada pra propagar

    if(a != b) lz[2 * p] += lz[p], lz[2 * p + 1] += lz[p];

    // Seg de soma
    seg[p] += lz[p] * (b - a + 1);
    lz[p] = 0;
}

// Update a range by +x in this case
int update(int a, int b, int x, int p, int l, int r){
    unlazy(p, l, r);

    if(b < l or a > r) return seg[p]; // Disjuntos
    if(a <= l and r <= b){
        lz[p] += x;
        unlazy(p, l, r);

        return seg[p];
    } 
    
    int m = (l + r)/2;
    return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p + 1, m + 1, r);

}

int query(int a, int b, int p, int l, int r ){
    unlazy(p, l, r);
    
    if(r < a or b < l) return 0;
    if(a <= l and r <= b) return seg[p] + lz[p]; // Cobre o caso da folha

    int m = (l + r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p + 1, m + 1, r);

}

int build(int p, int l, int r){
    // lz[p] = 0;
    if(l == r) return seg[p] = arr[l];

    int m = (l + r)/ 2;
    return seg[p] = build(2*p, l, m) + build(2*p + 1, m + 1, r);
}

int main(){ _
    memset(lz, 0, sizeof lz);
    memset(arr, 1, sizeof arr);

    int n, q; cin >> n >> q;

    // build(1, 0, n - 1);

    while(q --){
        int type; cin >> type;

        if(type == 1){
            int l, r, x; cin >> l >> r >> x; 
            update(l, r, x, 1, 0, n -1);
        }
        else{
            int l, r; cin >> l >> r;
            cout << query(l, r, 1, 0, n - 1) << " ";
        }
    }

    return 0;
} 
