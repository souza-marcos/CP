#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a < b and b < c) cout << "STAIR\n";
    else if(a < b and c < b) cout << "PEAK\n";
    else cout << "NONE\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
