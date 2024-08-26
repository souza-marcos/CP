#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, x, y;

bool valid(ll sec){
    if(min(x, y) > sec) return false;
    sec -= min(x, y);
    return ((sec/x + sec/y + 1) >= n);
}

int main(){ _
    cin >> n >> x >> y;
    
    ll l = 0, r = n * min(x, y);
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    } 
    cout << r << endl;
    return 0;
} 
