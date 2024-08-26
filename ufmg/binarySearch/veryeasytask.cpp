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

ll n, x, y;

bool valid(ll time) {
    if(min(x, y) > time) return false;
    time -= min(x, y);
    return (n <= (time/x + time/y + 1));
}

int main(){ _

    cin >> n >> x >> y;
    ll l = 1;  //l is bad
    ll r = n * min(x, y);//r is good

    while(r > l + 1){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;

    return 0;
} 
