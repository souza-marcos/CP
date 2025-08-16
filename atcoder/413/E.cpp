#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const int MAX = 1048576 + 10;
vector<int> arr;
int seg[MAX];

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];
    int m = (l + r)/2;
    return seg[p] = min(build(p << 1, l, m), build(p<<1 | 1, m + 1, r));
}

vector<int> res;

void rec(int p, int l, int r){
    if(l == r) {
        res.push_back(seg[p]);
        return;
    }
    int m = (l + r)/2;
    if(seg[p<<1] < seg[p<<1|1]){
        rec(p<<1, l, m);
        rec(p<<1|1, m + 1, r);
    }else{
        rec(p<<1|1, m + 1, r);   
        rec(p<<1, l, m);
    }
}


void solve(){
    int n; cin >> n;
    arr.resize(1 << n);
    for(int& el : arr) cin >> el;
    build(1, 0, (1<<n)-1);
    res.clear();
    rec(1, 0, (1<<n)-1);
    for(auto el: res) cout << el << " ";
    cout << endl;
}


int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
