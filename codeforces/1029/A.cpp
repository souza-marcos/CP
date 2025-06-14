#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n, x; cin >> n >> x;
    int fr = -1, ls = -1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a == 1){
            if(fr == -1) fr = i;
            ls = i;
        }
    }
    cout << (ls - fr + 1 <= x ? "YES\n" : "NO\n");
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
