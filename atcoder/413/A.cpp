#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
   
int main(){ _

    int n, m; cin >> n >> m;
    while(n--){
        int a; cin >> a;
        m -= a;
    }
    if(m >= 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
} 
