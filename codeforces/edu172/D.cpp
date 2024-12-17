#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n);
    int i = 0;
    for(auto&[l, r, id] : arr) cin >> l >> r, id = i ++;

    sort(arr.begin(), arr.end(), [&](auto l, auto r){
        if(get<0>(l) < get<0>(r)) return true;
        return get<1>(l) > get<1>(r);
    });

    set<pair<int , int>> segs;
    for(int i = 0; i < n; i ++){
        
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();    
    return 0;
} 
