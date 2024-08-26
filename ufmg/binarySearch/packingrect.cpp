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

int w, h, n;

bool isPos(ll x){
    ll mrh = x / w;
    ll mrv = x / h;
    return (n <= mrh * mrv);
}

int main(){ _

    cin >> w >> h >> n;
    ll l = 0, r = 1;

    while(!isPos(r)) r *= 2;

    while(r > l + 1){
        ll m = (l+r)/2;
        if(isPos(m)) r = m;
        else l = m;
    }

    cout << r << endl;


    return 0;
} 
