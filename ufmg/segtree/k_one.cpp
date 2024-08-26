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
int arr[MAX], seg[4 * MAX]; // sum of segments

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];

    int m = (l + r)/2;
    return seg[p] = build(2 * p, l, m) + build(2 * p + 1, m + 1, r);
}

int update(int i, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = !seg[p];

    int m = (l + r)/2;
    return seg[p] = update(i, 2 * p, l, m) + update(i, 2 * p + 1, m + 1, r);
}

int query(int k, int p, int l, int r){
    if(l == r) return l;
    if(seg[2 * p] >= k){ // Vai para esquerda
        return query(k, 2 * p, l, (l + r)/2);
    }
    return query(k - seg[2 * p], 2 * p + 1, (l + r)/2 + 1, r);
}

int main(){ _
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n -1);
    while(q --){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i;
            update(i, 1, 0, n - 1);
        }else{
            int k; cin >> k; k ++;
            cout << query(k, 1, 0, n - 1) << endl;
        }
    }

    return 0;
} 
