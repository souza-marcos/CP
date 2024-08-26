#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    vector<ll> v(n); for(auto& el: v) cin >> el;
    sort(v.begin(), v.end());
    ll maxv = 0;
    ll price = 0;
    for(int i = 0; i < n; i ++){
        ll val = v[i] * (n-i);
        if(val >= maxv){
            maxv = val;
            price = v[i];
        }
    }

    cout << price << " " << maxv << endl;
    return 0;
} 
