#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _
    int n, x; cin >> n >> x;
    vector<ll> arr(n); for(auto& el : arr) cin >> el;

    vector<ll> fr, sn;
    for(int i = 0; i < (1 << (n/2)); i ++){
        ll val = 0;
        for(int j = 0; j < n/2; j ++)
            if(i & (1 << j)) val += arr[j];
        fr.push_back(val);
    }

    for(int i = 0; i < (1 << (n - n/2)); i ++){
        ll val = 0;
        for(int j = 0; j < n-n/2; j ++)
            if(i & (1 << j)) val += arr[j + n/2];
        sn.push_back(val);
    }

    sort(fr.begin(), fr.end()), sort(sn.begin(), sn.end());

    ll tot = 0;
    for(auto el: fr){
        tot += upper_bound(sn.begin(), sn.end(), x-el) - lower_bound(sn.begin(), sn.end(), x-el);
    }
    cout << tot << endl;
    return 0;
} 
