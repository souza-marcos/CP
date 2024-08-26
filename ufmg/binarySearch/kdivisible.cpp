#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while(t --){
        int n, k; cin >> n >> k;

        ll l = 0, r = 1e10;
        while(l<r){
            ll m = (l+r)/2;
            if((m - m/n) >= k){
                r = m;
            } 
            else l = m + 1;
        }
        cout << l << endl;

    }

    return 0;
} 
