#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n; cin >> n;
    vector<int> v(n); for(int& el: v) cin >> el;
    multiset<int> mp;
    vector<int> ans; int k; cin >> k;
    for(int i = 0; i < k; i ++) mp.insert(v[i]);
    ans.push_back(*mp.rbegin());
    for(int i = k; i < n; i ++){    
        mp.erase(v[i - k]);
        mp.insert(v[i]);
        ans.push_back(*mp.rbegin());
    }

    for(auto el: ans) cout << el << " ";
    cout << endl;

    return 0;
} 
