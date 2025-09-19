#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// seg tree de max, pegando o satisfazivel a mais a esquerda.

const int MAX = 2e5 + 10;
int seg[4*MAX];
vector<int> arr;

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l]; 
    int m = (l + r)/2;
    return seg[p] = max(build(p << 1, l, m), build(p << 1 | 1, m + 1, r));
}

int update(int p, int l, int r, int k, int x){
    if(l > k or r < k) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l + r)/2;
    return seg[p] = max(update(p << 1, l, m, k, x), update(p << 1 | 1, m + 1, r, k, x));
}

int idx_leftmost(int p, int l, int r, int val){
    if(l == r) return l;
    int m = (l + r)/2;
    assert(seg[p << 1] >= val or seg[p << 1 | 1] >= val);
    if(seg[p << 1] >= val) 
        return idx_leftmost(p << 1, l, m, val);
    else return idx_leftmost(p << 1 | 1, m + 1, r, val);
}

void print(int p, int l, int r){
    if(l == r) {
        cout << seg[p] << " ";
        return;
    }
    int m = (l + r)/2;
    print(p << 1, l, m), print(p << 1 | 1, m + 1, r);
}

int main(){ _ 
    // Tenho que manter seg e arr atualizados

    int n, m; cin >> n >> m;
    arr.resize(n);
    for(auto &el : arr) cin >> el;
    build(1, 0, n-1);
    for(int i = 0; i < m; i ++){
        int a; cin >> a;
        if(seg[1] < a){
            cout << 0 << " ";
        } else {
            int idx = idx_leftmost(1, 0, n-1, a);
            arr[idx] -= a;
            update(1, 0, n-1, idx, arr[idx]);
            cout << idx + 1 << " ";
            // print(1, 0, n-1); cout << "\n";
        }
    }
    cout << endl;
    return 0;
} 
