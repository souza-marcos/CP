#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int x, y; cin >> x >> y;

    for(int i = 1; i < 50; i ++) cout << (x ^ i) << " ";
    cout << endl;
    for(int i = 1; i < 50; i ++) cout << (y ^ i) << " ";
    cout << endl;

}

int main(){ _
    solve();
    // int t; cin >> t;
    // while(t --) solve();
    return 0;
} 
