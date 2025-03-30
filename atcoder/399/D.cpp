#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n; cin>> n;
    vector<vector<int>> idx(n+1);
    vector<int> arr(2*n);
    for(int i = 0; i < 2*n; i ++){
        cin >> arr[i];
        idx[arr[i]].push_back(i);
    }

    set<pair<int, int>> used;
    ll cnt = 0;
    for(auto el : idx){
        if(sz(el) < 2) continue;
        int first = el[0], second = el[1];
        
        if(second-first <= 1) continue;

        auto adj = idx[arr[second-1]];
        if(abs(adj[0]-first) == 1 and abs(adj[1]-second) == 1 
            and (adj[1] - adj[0]) >1){
            if(used.count({arr[second-1], arr[second]}) == 0) {
                cnt ++;
                used.insert({{arr[second-1], arr[second]}, {arr[second], arr[second-1]}});
            }
        } else if(abs(adj[1]-first) == 1 and abs(adj[0]-second) == 1 
            and (adj[1] - adj[0]) >1){
            if(used.count({arr[second-1], arr[second]}) == 0) {
                cnt ++;
                used.insert({{arr[second-1], arr[second]}, {arr[second], arr[second-1]}});
            }
        }

    }   
    cout << cnt << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
