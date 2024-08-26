#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int w, h, n;

bool valid(ll larg){
    return n <= (larg/w) * (larg/h);
}

int main(){ _
    cin >> w >> h >> n;

    ll l = 0, r = 1;

    while(!valid(r)) r *= 2;

    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
} 
