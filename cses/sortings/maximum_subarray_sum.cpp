#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    
    // se minha soma atual for menor que zero 
    // sempre compensa começar uma do inicio 
    
    int n; cin >> n;
    ll sum = 0, maxv = 0, dval = -INF;
    bool ok = false;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        sum += a;
        if(sum >= 0) ok = true;
        sum = max(0LL,  sum);
        maxv = max(maxv, sum);
        dval = max(a, dval);
    }
    cout <<(ok? maxv : dval )<< endl;
    return 0;
} 
