#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
vector<int> fib(46);

void solve(){


}   


int main(){ _
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 46; i ++) fib[i] = fib[i-1] + fib[i-2];
    for(auto el: fib) cout << el << " ";
    cout << endl;
    
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
