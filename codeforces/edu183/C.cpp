#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int> arr(n), pref(n);

    map<int, int> mp;
    for(int i = 0; i < n; i ++){
        arr[i] = (s[i] == 'a' ? +1: -1);
        pref[i] = (i > 0? pref[i-1] : 0) + arr[i]; 
    }

    if(pref[n-1] == 0){
        cout << 0 << endl;
        return;
    }
    int quero = pref[n-1];
    int sum = 0;
    mp[0] = 0;

    
    int mi = INF;
    for(int i = 0; i < n; i ++){
        sum += arr[i];
        int x = sum - quero;
        if(mp.count(x)){
            // cout << quero << " " << sum <<  " " << x << " ";
            // cout << mp[x] << " " << i + 1 << endl;
            mi = min(mi, i-mp[x]+1);
        }

        mp[sum] = i+1;
    }
    cout << (mi == n? -1: mi)  << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 


// maybe