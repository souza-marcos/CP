#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _  
    ll n; cin >> n;
    vector<int> a(n); for(auto& el : a) cin >> el;

    vector<ll> last(n, -1), els;
    ll cnt = 0;
    for(int i = 0; i < n; i ++){
        if(last[a[i]] == -1) els.push_back(a[i]);
        cnt += (i - last[a[i]]) * (last[a[i]] + 1);
        last[a[i]] = i;
    }
    
    for(int el: els){
        cnt += (n - last[el]) * (last[el] + 1);
    }
    cout << cnt << endl;
    return 0;
} 
