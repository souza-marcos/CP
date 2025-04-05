#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n), inv_a(n + 1), inv_b(n + 1);
    
    int i = 0;
    for(auto& el: a) cin >> el, inv_a[el] = i ++;
    i = 0;
    for(auto& el: b) cin >> el, inv_b[el] = i ++;


    int cnt=0;
    for(int i=1; i <= n; i ++){
        int pos_a = inv_a[i], pos_b = inv_b[i];
        if(pos_a == pos_b) cnt ++;
        if(a[pos_b] != b[pos_a] or cnt > 1){
            cout << -1 << endl;
            return;
        }
    }


    vector<pair<int, int>> ans;
    vector<int> done(n, false);
    int next = 1;
    for(int i = 0; i < n; i ++){
        while(next < !done[next]) n
    }

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
