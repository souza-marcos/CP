#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    int fac = k % 4;
    if(n & 1) {
        if(fac == 3 or fac == 0) cout << "YES";
        else cout << "NO";
    }
    else{
        if(fac == 1 or fac == 0) cout << "YES";
        else cout << "NO";
    }
    cout << endl;
}

int main(){ _
    
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
