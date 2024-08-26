#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

int main(){ _

    int t; cin >> t;
    while(t --) {
        int n, p, k; cin >> n >> p >> k;
        while(n % p == 0) n /= p;
        int h = ceil(n / (double)p);
        int rest = p - n%p;
        n = n + rest; k -= rest;
    }

    return 0;
} 
