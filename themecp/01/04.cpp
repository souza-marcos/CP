#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;

    vector<vector<int>> arr(n);
    for(auto& el: arr){
        el.resize(5);
        for(auto& it:el) cin>>it;
    } 
    int best = 0;
    for(int i = 1; i < n; i ++){
        int cnt = 0;
        for(int j = 0; j < 5; j ++){
            if(arr[best][j] < arr[i][j]) cnt ++;
        }
        if(cnt < 3) best = i;
    }
    bool ok = true;
    for(int i = 0; i < n; i ++){
        if(best == i) continue;
        int cnt = 0;
        for(int j = 0; j < 5; j ++){
            if(arr[best][j] < arr[i][j]) cnt ++;
        }
        if(cnt < 3) {ok = false; break;}
    }
    if(ok) cout << best + 1 << endl;
    else cout << -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
