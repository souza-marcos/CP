#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define int ll
#define endl '\n'
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll lcm(ll a, ll b){
    return a/__gcd(a, b) * b;
}

int32_t main(){ _
    int n; cin >> n;
    vector<ll> arr(n);
    ll looking = 1;
    for(ll& el : arr) cin >> el, looking = lcm(el, looking);

    sort(arr.begin(), arr.end());
    ll falta = -1;
    for(ll& el : arr){
        auto it = lower_bound(arr.begin(), arr.end(), looking/el);
        if(it == arr.end() or *it != looking/el) {
            if(falta != -1){
                cout << "*\n";
                exit(0);
            }
            else falta = looking/el;
        }
    }
 
	



    if(falta == -1) cout << "*\n", exit(0);
 
 
 
 
    cout << looking << " " << falta << endl;
}