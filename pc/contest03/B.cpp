#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll sum = 0;
    while(n > 1){
        sum += n;
        n /= 2;
    }

    cout << sum + 1 << endl;
}

int main(){_
    int t; cin >> t;
    while(t --) solve();

    return 0;
}