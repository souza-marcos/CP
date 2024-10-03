#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int a, b, c; cin >> a >> b >> c;
    int ab = max(a, b), bc = max(b, c), ac = max(a,c);
    cout << max(0, bc-a+1) << " " << max(0, ac-b+1) << " " << max(0, ab-c + 1) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
