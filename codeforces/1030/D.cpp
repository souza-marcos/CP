#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n, k; cin >> n >> k;
    vector<int> pos(n), delay(n);
    for(auto & el :pos) cin >> el;
    for(auto & el :pos) cin >> el;

    int q; cin >> q;
    while(q --){
        int p; cin >> p;
        ll sec = 0, fac = 0; // left-to-right = 0, right-to-left = 1
        vector<vector<bool>> foi(n, vector<bool>(2, 0)); 

        auto it =  lower_bound(pos.begin(), pos.end(), p);
        if(it == pos.end()) cout << "YES\n";
        else {
            int cur = it - pos.begin();

            while(foi[cur][fac] == false){
                
                sec += (pos[cur] - pos[cur+fac]

            }
        }
    }

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
