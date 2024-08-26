#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _
    ll a, b; cin >> a >> b;

    if(a == b) { cout << 0 << endl; return 0; } 
    ll res = a ^ b;
    int cnt = 64 - __builtin_clzll(res);
    cout << (1ll << cnt) - 1ll << endl;
    // for(int i = 63; i > 0; i --){
    //     ll bit = (1LL << i);
    //     if((bit & a) == (bit & b)) continue;
    //     cout << (bit << 1ll) - 1ll << endl;
    //     break;
    // }
    
    return 0;
} 
