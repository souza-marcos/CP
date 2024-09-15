#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n, k; cin >> n >> k;
    if(k >= n - 1) cout << 1 << endl;
    else cout << n << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
