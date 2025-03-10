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
    vector<int> arr(n);
    vector<vector<int>> idx(101);
    int i = 0;
    for(auto&el : arr) cin >> el, idx[el].push_back(i), i ++;

    vector<int> res(n, 1);

    int ok = 0;

    for(int i = 0; i < 101; i ++) {
        if(idx[i].size() <= 1) continue;

        if(ok < 2){
            for(int j = 0; j < sz(idx[i]); j ++) res[idx[i][j]] = j%2 + 1 + ok;  
            ok ++;
        }
    }
    if(ok < 2) cout << -1 << endl;
    else {
        for(auto el : res) cout << el << " ";
        cout << endl;
    }
}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
