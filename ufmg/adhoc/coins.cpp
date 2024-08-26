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
    ll n, k; cin >> n >> k;
    if(n % 2 == 0){
        cout << "YES" << endl;
        return;
    }

    if(k % 2 == 0) cout << "NO" << endl;
    else if(n == k) cout << "YES" << endl;
    else if(n - k < 2) cout << "NO" << endl;
    else cout << "YES" << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
