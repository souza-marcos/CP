#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    auto getsqrt = [&](ll el){
        double s = sqrt(el);
        for(int i = s-3; i <= s+3; i ++){
            if(i * i > el) return i-1;
        };
        return 0;
    };

    ll n; cin >> n;
    ll cnt = 0;

    vector<int> twopowersquare;
    for(ll a = 1; a*a <= n; a <<= 1) twopowersquare.push_back(a);

    for(ll a = 1; a <= n; a <<= 1){
        cnt ++;
        cnt += getsqrt(n/a) - (lower_bound(twopowersquare.begin(), twopowersquare.end(), n/a) - twopowersquare.begin());
    }
    cout << cnt << endl;

    return 0;
} 
