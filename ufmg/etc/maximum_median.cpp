#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n; vector<int> v;
int k;

bool valid(ll guess){
    ll left = 0;
    for(int i = n/2; i < n; i ++){
        if(v[i] >= guess) break;
        left += guess - v[i];
        if(left > k) return false;
    }
    return true;
}

int main(){ _
    cin >> n >> k;
    v.resize(n);
    for(int& el: v) cin >> el;

    sort(v.begin(), v.end());
    ll l = 0, r = 2e9 + 10;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
} 
