#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 

    int n, m; cin >> n >> m;
    vector<int> divs;
    for(int i = 1; i < n; i ++) if(n%i == 0) divs.push_back(i);

    vector<pair<int, int>> arr(m); 
    for(auto& el: arr) {
        int a, b; cin >> a >> b; a--, b--;
        el.first = min(a, b), el.second = max(a, b);
    }

    sort(arr.begin(), arr.end());

    // for(auto [a, b] : arr) cout << 

    bool ok = false;
    for(auto k : divs){
        ok = true;
        vector<bool> used(m, false);
        for(int i = 0; i < m; i ++){
            auto [newa, newb] = arr[i];
            newa = (newa+k)%n, newb = (newb+k)%n;
            if(newa > newb) swap(newa, newb);



            auto p = make_pair(newa, newb);

            auto it = lower_bound(arr.begin(), arr.end(), p);
            int idx = it - arr.begin();
            if(it == arr.end() or *it != p or used[idx]){
                ok = false;
                break;
            }
            used[idx] = true;
        } 
        if(ok) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
} 
