#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
   
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n); // is not friend
    vector<int> minid(n, 0);


    for(int i =0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // sort all nv
    for(auto &el: g){   
        sort(el.begin(), el.end());
        // for(auto it : el) cout << it << " ";
        // cout << endl;
    } 
    // cout << "----\n";
    ll cnt = 0;
    for(int j = 0, i = 0; j < n; j ++){
        if(sz(g[j]) > 0 and minid[j] < sz(g[j])){
            int first = g[j][minid[j]];
            while(first < j){
                i = max(i, first + 1);
                minid[j] ++;
                if(minid[j] == sz(g[j])) break;
                first = g[j][minid[j]];
            }
        }
        // cout << i << " " << j << endl;
        cnt += j-i+1;
    }
    cout << cnt << endl;

}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
