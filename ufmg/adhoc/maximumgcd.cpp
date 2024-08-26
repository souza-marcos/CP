#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


#define endl '\n'


void solve(){
    int n; cin >> n;

    if(n <= 3) cout << 1 << endl;
    else cout << n / 2 << endl;
    
}

int main(){ _
    int t; cin >> t;
    while (t --) solve();
    
    return 0;
} 
