#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, time; cin >> n >> time;
    
    ll last = 0;
    while(n --){
        ll a; cin >> a;
        last = max(a, last) + time;
        cout << last << endl;
    }

    return 0;
} 
