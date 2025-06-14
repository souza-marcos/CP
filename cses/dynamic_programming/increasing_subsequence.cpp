#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n; cin >> n;
    vector<int> dp; // min val to the left to get the idx val 
 
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if(it == dp.end())
            dp.push_back(a);
        else (*it) = min(*it, a); 
    }

    cout << sz(dp) << endl;
}
