#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> arr(n);
    set<int> index;
    for(int i = 0; i < n ; i ++){
        auto &[l, r, v] = arr[i];
        cin >> l >> r >> v;
        index.insert(l), index.insert(r);
    }

    map<int, int> mp;
    vector<int> inverted;
    int i= 0;
    for(auto el: index) mp[el] = i ++, inverted.push_back(el);

    vector<ll> proc(sz(mp) + 1), pref(sz(mp) + 1);
    for(auto [l, r, v] : arr){
        proc[mp[l]] += v, proc[mp[r]] -= v;
    }

    // iterate through all events and 
    pref[0]=0; // Before 0-index its 0
    vector<ll> diff(sz(proc) + 1); diff[0] = 0;
    for(int i = 1; i < sz(proc); i ++){
        diff[i] = diff[i-1] + proc[i-1];
        pref[i] = pref[i-1] + diff[i] * (inverted[i]-inverted[i-1]);
    }

    // for(auto el: diff) cout << el << " ";
    // cout << endl;
    
    // for(auto el: pref) cout << el << " ";
    // cout << endl;
    // for(auto el : inverted) cout << el << " ";
    // cout << endl;

    while(q --){

        int l, r; cin >> l >> r;
        auto lb = lower_bound(inverted.begin(), inverted.end(), l);
        auto rb = lower_bound(inverted.begin(), inverted.end(), r); 

        ll left = 0, right = 0;
        int il = lb - inverted.begin(); 
        int ir = rb - inverted.begin();

        if(*lb > l){
            if(il == 0) left = pref[0];
            else left = pref[il-1] + diff[il] * (l-*(--lb));
        } else left = pref[il];
        
        if(*rb > r){
            if(ir == 0) right = pref[0];
            else right = pref[ir-1] + diff[ir] *(r - *(--rb)); 
        } else right = pref[ir];

        cout << right - left << endl;
    }
    return 0;
} 
