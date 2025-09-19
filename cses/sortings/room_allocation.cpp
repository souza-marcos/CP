#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    vector<tuple<int, int, int>> customers(n); // end - start - idx
    int i = 0;
    for(auto& [a, b, idx] : customers) cin >> a >> b, idx = i ++;

    sort(customers.begin(), customers.end());
    vector<int> res(n); // The group the customer is
    set<pair<int, int>> ms; // val_end, idx_last_val

    i = 0;
    for(auto [a, b, idx] : customers){
        auto it = ms.lower_bound({-a, INF});
        if(it == ms.end()){ // not found a group, create a new one
            res[idx] = i ++;
            ms.insert({-b, idx});
        } else{
            res[idx] = res[(*it).second];
            ms.erase(it);
            ms.insert({-b, idx});
        }
    }

    cout << i << endl;
    for(auto el : res) 
        cout << el + 1 << " ";
    cout << endl;
    return 0;       
}
