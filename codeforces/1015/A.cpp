#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    if(n%2 == 0){
        cout << -1 << endl;
    } else {
        cout << n << endl;
        for(int i = 1; i < n; i ++) cout << i <<  " ";
        cout << endl;
    }

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
