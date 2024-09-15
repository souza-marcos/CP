#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

ll tobin(int N)
{
    // To store the binary number
    ll B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        ll c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        // Count used to store exponent value
        cnt++;
    }
    return B_Number;
}

void solve(){
    int n; cin >> n;
    if(n == 0) { cout << "YES\n"; return; }
    for(int i = 32; i >= 2; i --){
        ll cur = tobin(i);
        // cout << cur << n << endl;
        while(n%cur == 0) n /= cur;
    }
    cout << (n==1?"YES":"NO") << endl;
}

int main(){ //_
    int t; cin >> t;
    while(t -- ) solve();
    return 0;
} 
