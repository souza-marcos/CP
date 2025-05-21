#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    ll n; cin >> n;
    ll cnt = 0;
    ll cur = 5;
    while(cur <= n){
        cnt += n/cur;
        cur *= 5;
    }
    cout << cnt << endl;
    return 0;
}
