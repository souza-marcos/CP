#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n, m; cin >> n >> m;
    map<int, int> cnt;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int a; cin >> a;
            cnt[a] ++;
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int a; cin >> a;
            cnt[a] --;
        }
    }

    for(auto [k ,val] : cnt) if(val != 0){
        cout << "NO\n"; return ;
    }
    cout << "YES\n";
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
