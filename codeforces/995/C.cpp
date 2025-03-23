#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, m, k; cin >> n >> m >> k;
    map<int, int> lists; 
    
    for(int i = 0; i < m; i ++) {
        int a; cin >> a;
        lists[a] = i;
    } 
    
    vector<int> q(k); for(auto& el: q) cin >> el;

    vector<int> res(m, 1);
    if(k < n-1) res.assign(m, 0);
    if(k == n-1){
        for(auto el: q){
            if(lists.count(el)) res[lists[el]] = 0;
        }
    }

    for(auto el: res) cout << el;
    cout << endl;       
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
