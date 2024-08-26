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

ll arr[MAX];
ll seg[4 * MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l]; // Folha
    
    int m = (l + r)/2;
    return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
}

ll query(int a, int b, int p, int l, int r){
    if(r < a or l > b) return 0;
    if(a <= l and b >= r) return seg[p];

    int m = (l + r)/ 2;
    return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
}

ll update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = x;

    int m = (l + r)/2;
    return seg[p] = update(i, x, 2 * p, l, m) + update(i, x, 2 * p + 1, m + 1, r);
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n - 1);


    while(m --){
        int q; cin >> q;

        if(q == 1){
            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n - 1);
        }
        else{
            int l, r; 
            cin >> l >> r; r --;
            cout << query(l, r, 1, 0, n - 1) << endl;
        }

    }
    
    return 0;
}