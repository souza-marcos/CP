// https://codeforces.com/contest/2032/problem/B
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    
    if(n == 1){
        cout << 1 << endl << 1 << endl;
        return;
    }
    
    
    if(k == n or k == 1) {
        cout << -1 << endl;
        return;
    }

    if(k % 2== 0){
        cout << 3 << endl;
        cout << "1 "  << k << " " << k + 1 << endl;
    }
    else {
        cout << 3 << endl;
        cout << "1 " << k-1 << " " << k + 2 << endl;
    }
}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
