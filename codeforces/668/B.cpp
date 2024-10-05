#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

#pragma GCC optimize("O3")
#pragma GCC target("avx2")  

void solve(){
    int n; cin >> n;
    vector<int> arr(n), lessv, grv;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        if(arr[i] < 0) lessv.push_back(i);
        else if(arr[i] > 0) grv.push_back(i);
    }

    int i = 0, j = 0;
    while(j < sz(lessv) and lessv[j] < grv[i]) j++;
    
    ll cnt = 0;
    while(i < sz(grv) and j < sz(lessv)){
        assert(lessv[j] >= grv[i]);
        // cout << "I=> " <<  grv[i]<<" " <<lessv[j]  << endl;
        ll val = min(abs(arr[grv[i]]), abs(arr[lessv[j]]));
        // cout << "VAL=> " << val << endl;
        arr[grv[i]] -= val;
        arr[lessv[j]] += val;

        if(arr[grv[i]] == 0) i ++;
        if(arr[lessv[j]]==0) j ++;
        while(j < sz(lessv) and lessv[j] < grv[i]) j++;
    }

    for(int i = 0; i < n; i ++){
        // cout << arr[i] << " ";
        if(arr[i] > 0) cnt += arr[i];
    }
    // cout << endl;
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
