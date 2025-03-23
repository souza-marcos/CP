#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _

    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto& el: a) cin >> el;
    for(auto& el: b) cin >> el;
    
    sort(a.begin(), a.end());
    ll d = 0;
    for(int i =0; i < n-1; i ++){
        d = __gcd(d, a[n-1] - a[i]);
    }

    for(auto el: b){
        cout << __gcd(d, a[n-1] + el) << " ";
    }
    cout << endl;

    return 0;
} 
