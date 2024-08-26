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

int mdc(ll a, ll b){
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return mdc(b, a % b); 
}

int main(){ _

    int t; cin >>t;
    while(t--){
        ll a, b; cin >> a >> b;
        
    }

    return 0;
} 
