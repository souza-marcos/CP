#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

int n, m, v; 
vector<int> arr(n);

void solve(){
    cin >> n >> m >> v;
    arr.resize(n);
    
    vector<int> pref(n + 1, 0);
    vector<int> suff(n + 1, 0);
    vector<ll> val_pref(n + 1, 0);

    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        pref[i + 1] = pref[i] + (sum >= v);
        if(sum >= v) sum = 0;

        val_pref[i + 1] = val_pref[i] + arr[i];
    }

    sum = 0;
    suff[n] = 0;
    for(int i = n-1; i >=0; i --){
        sum += arr[i];
        suff[i] = suff[i + 1] + (sum >= v);
        if(sum >= v) sum = 0;   
    }

    // for(auto el: arr) cout << el << " ";
    // cout << endl;

    // for(auto el: pref) cout << el << " ";
    // cout << endl;

    // for(auto el: suff) cout << el << " ";
    // cout << endl;


    ll maxv = -LINF;
    for(int i = 0; i < n; i ++){
        int t = pref[i];

        auto it = lower_bound(suff.rbegin(), suff.rend(), m-t);
        int j = (n - (it - suff.rbegin()));
        // cout << "IT pos " << j << " => " << *it << endl;
        // cout << "I: " << i << ", T: " << t <<  ", R: " << r << " " <<val_pref[(n-r)] - val_pref[i] << endl;    

        ll val = -LINF;
        if(suff[j] >= (m-t)){
            // int idx = r
            
            if(j > i) val = val_pref[j] - val_pref[i];
            else if(j == i) val = 0;
        }

        // cout << " => " << val << endl;
        maxv = max(val, maxv);
    }

    cout << max(-1LL, maxv) << endl;
}

int main(){ _
    int t; cin >> t;
    while (t --) solve();
    return 0;
} 
