#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const int MAX = 2e5 + 10;
vector<int> arr;


vector<int> seg; 
inline void build(int n){ 
    seg.assign(4*(n+10), 0);
}

int query(int p, int l, int r, int lq, int rq){
    if(rq < l or lq > r) return 0;
    if(l >= lq and r <= rq) return seg[p];
    int m = (l + r)/2;
    return max(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m + 1, r, lq, rq));
}

int update(int p, int l, int r, int idx, int x){
    if(idx < l or idx > r) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l + r)/2;
    return seg[p] = max(update(p << 1, l, m, idx, x), update(p << 1 | 1, m + 1, r, idx, x));
}


void solve(){
    int n; cin >> n;
    arr.resize(n);
    vector<int> sorted; 
    for(auto& el: arr) cin >> el, sorted.push_back(el);
    sort(sorted.begin(), sorted.end());

    build(n);


    vector<int> dp(n);

    // LIS -> Increasing
    int maxv = 1; 
    for(int i = 0; i < n; i ++){
        int pos = (lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin()) + 1;
        int best = query(1, 0, n, 0, pos-1);
        dp[i] = best + 1;
        maxv=max(maxv, best+1);
        update(1, 0, n, pos, best+1);
    }

    build(n);
    // Decreasing
    vector<int> res;
    for(int i = n-1; i >= 0; i --){
        int pos = (lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin()) + 1;
        int best = query(1, 0, n, pos+1, n);
        if(best + dp[i] == maxv) res.push_back(i);
        update(1, 0, n, pos, best+1);
    }

    cout << sz(res) << endl;
    for(auto it = res.rbegin(); it != res.rend(); ++it){
        cout << 1 + *it << " ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
