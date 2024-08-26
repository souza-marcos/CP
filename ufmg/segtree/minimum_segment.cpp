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

int build(int p, int l, int r){
    if (l == r) return seg[p] = arr[l];

    int m = (l + r)/2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

int update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p]; // Check later
    if(l == r) return seg[p] = x; // Folha

    int m = (l + r)/2;
    return seg[p] = min(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

// query [a, b]
int query(int a, int b, int p, int l, int r){

    if(b < l or a > r) return INF;
    if(a <= l and r <= b) return seg[p];

    int m = (l + r)/2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

int main(){ _

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n -1);

    while(m --){
        int q; cin >> q;
        if(q == 1){ // update
            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n - 1);
        }else{ // query
            int l, r; cin >> l >> r; r --;
            cout << query(l, r, 1, 0, n - 1) << endl;
        }
    }

    return 0;
} 
