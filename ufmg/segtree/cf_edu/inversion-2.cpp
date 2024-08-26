#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MAX = 1e5 + 10;
vector<int> arr;
int seg[4 * MAX];

int build(int p, int l, int r){
    if(l == r) return seg[p] = 1;
    int m = (l + r)/2;
    return seg[p] = build(p << 1, l, m) + build(p << 1 | 1, m + 1, r);
}

int erase(int p, int l, int r, int i){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = 0;
    int m = (l + r)/2;
    return seg[p] = erase(p << 1, l, m, i) + erase(p << 1 | 1, m + 1, r, i);
}

int query(int p, int l, int r, int n){
    if(l == r) return l;
    int m = (l + r)/2;
    if(seg[p << 1 | 1] > n) 
        return query(p << 1 | 1, m + 1, r, n);

    return query(p << 1, l, m, n - seg[p << 1 | 1]);
}

int main(){ _
    
    int n; cin >> n;
    build(1, 0, n-1);
    vector<int> v(n), res; for(auto& el: v) cin >> el;
    for(auto it = v.rbegin(); it != v.rend(); ++it){
        auto el = *it;
        res.push_back(query(1, 0, n-1, el));
        erase(1, 0, n-1, res[sz(res) -1]);
    }

    for(auto it = res.rbegin(); it != res.rend(); ++it){
        cout << (*it) + 1 << " ";
    }cout << endl;
    return 0;
} 
