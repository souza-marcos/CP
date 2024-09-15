#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

// A Merge Sort Tree :O

const int MAX = 3e5 + 10;
vector<int> seg[MAX << 2];
vector<int> arr;

void build(int p, int l, int r){
    if(l == r) {
        seg[p] = vector<int>(1, arr[l]); 
        return;
    }
    int m = (l + r)/2;

    build(p << 1, l, m), build(p <<  1 | 1, m + 1, r);
    auto &left = seg[p << 1], &right = seg[p << 1 | 1]; 

    seg[p] = vector<int>(sz(left)+ sz(right));
    merge(left.begin(), left.end(), right.begin(), right.end(), seg[p].begin());
}

int count_greater(int x, vector<int>& arr){
    // for(auto el: arr) cout << el << " ";
    // cout << endl;

    auto lb = lower_bound(arr.begin(), arr.end(), x);
    return sz(arr) - (lb - arr.begin());
}

int query(int p, int l, int r, int lq, int rq, int x){
    if(rq < l or r < lq) return 0;
    if(lq <= l and r <= rq) return count_greater(x, seg[p]);

    int m = (l + r)/2;
    return query(p << 1, l, m, lq, rq, x) + query(p << 1 | 1, m + 1, r, lq, rq, x);
}

void print(int p, int l, int r){
    if(l == r) { 
        cout << l << "-> " << seg[p][0] << endl;
        return;
    }

    int m = (l + r)/2;
    print(p << 1, l, m), print(p << 1 | 1, m + 1, r);
    
    cout << l << ", " << r << "-> ";
    for(int &el: seg[p]) cout << el << " ";
    cout << endl;
}

int main(){ _
    int y, n; cin >> y >> n;
    arr.resize(y);
    for(int& el: arr) cin >> el;
    
    build(1, 0, y-1);

    int ini, x, qtd;
    while(n --){
        cin >> ini >> x >> qtd;
        if(arr[ini-1] >= x) {
            cout << 0 << endl;
            continue;
        }
        cout << query(1, 0, y-1, ini, ini + qtd-1, x) << endl;
    }
    return 0;
} 
