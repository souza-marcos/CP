#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 4e5 + 10;

bool seg[4 * MAX];

void init(){
    memset(seg, 0, sizeof seg);
}

bool add(int p, int l, int r, int i){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = true;
    int m = (l + r)/2;  
    auto left = add(p << 1, l, m, i), right = add(p << 1 | 1, m + 1, r, i);
    seg[p] = (!left) | (!right);
    return seg[p] = !seg[p];
}

bool query(int p, int l, int r, int lq, int rq){
    if(lq > r or rq < l) return 1;
    if(lq <= l and rq >= r) return seg[p];
    int m = (l + r)/2;
    auto left = query(p << 1, l, m, lq, rq), right = query(p << 1 | 1, m + 1, r, lq, rq);
    return !( (!left) | (!right));
}

void solve(){
    int n; cin >> n;
    
    init();
    vector<pair<int, int>> arr;
    vector<int> cnt(MAX, 0);
    for(int i = 0; i < n; i ++){
        int l, r; cin >> l >> r;
        arr.push_back({l, r});
        if(l == r) add(1, 1, MAX, l), cnt[l] ++;
    }

    for(auto [l, r] : arr){
        bool q = true; 
        if(l == r){
            // cout << "CNT => " << cnt[l] << endl;
            q = (cnt[l] > 1);
        } else {
            q = query(1, 1, MAX, l, r);
        }

        if(q) cout << "0";
        else cout << "1";
    }

    cout << endl;
}


int main(){ _
    int t; cin >> t;
    while (t --) solve();
    return 0;
} 
