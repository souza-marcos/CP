#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n); 
    set<int> colors;
    for(auto& el : arr) cin >> el, el --, colors.insert(el);
    vector<int> pref(n), suff(n);

    pref[0] = arr[0];
    for(int i = 1; i < n; i ++)
        pref[i] = max(pref[i-1], arr[i]);

    suff[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i --)
        suff[i] = max(suff[i+1], arr[i]);
    
    // Quero pegar o maior pref e suff que possui todos menores que x

    vector<int> res(k, 0);
    for(auto c : colors){
        auto it1 = lower_bound(pref.begin(), pref.end(), c) - pref.begin();
        auto it2 = n - 1 - (lower_bound(suff.rbegin(), suff.rend(), c) - suff.rbegin());
        res[c] = 2 * (it2 - it1 + 1);
    }

    for(auto el : res) cout << el << " ";
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
