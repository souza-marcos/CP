#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> v(n); for(auto& el: v) cin >> el;

    vector<bool> bus(n + 2, 0);
    bus[v[0]] = 1;
    for(int i =1; i < n; i ++){
        int pos = v[i];
        if(bus[pos -1] or bus[pos+1]){
            bus[pos] = 1;
        }else {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
    return;
}

int main(){ _
    int t;cin >> t;
    while(t --) solve();

    return 0;
} 
