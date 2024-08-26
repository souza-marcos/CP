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

bitset<40> seg[4 * MAX];
int arr[MAX];

bitset<40> build(int p, int l, int r){
    if(l == r) {
        seg[p][arr[l]] = true;
        return seg[p];
    }

    int m = (l + r)/2;
    return seg[p] = build(2 * p, l, m) | build(2 * p + 1, m + 1, r);
}

bitset<40> update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) {
        seg[p].reset(); seg[p][x] = true;
        return seg[p];
    } 

    int m = (l + r)/2;
    return seg[p] = update(i, x, 2 * p, l, m) | update(i, x, 2 * p + 1, m + 1, r);
}

bitset<40> query(int a, int b, int p, int l, int r){
    if(b < l or a > r) return bitset<40>(0);
    if(a <= l and r <= b) return seg[p];

    int m = (l + r)/2;
    return query(a, b, 2 * p, l, m) | query(a, b, 2*p + 1, m+1, r);
}


int main(){ _

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i], arr[i] --;

    build(1, 0, n - 1);
    while(q --){
        int t; cin >> t;
        if(t == 1){ // query
            int a, b; cin >> a >> b; a--, b--;     
            cout << query(a, b, 1, 0 , n - 1).count() << endl;
        }else{
            int i, x; cin >> i >> x; i--, x --;
            update(i, x, 1, 0, n -1);
        }
    }

    return 0;
} 
