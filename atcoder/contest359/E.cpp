#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<int> h(n);
    for(auto& el: h) cin >> el;


    stack<pair<int, int>> st; 
    st.push({INF, 0});
    ll land = 0;
    int i = 1;

    ll cnt = 1;
    for(auto cur_elev: h){
        ll last_idx = i;
        while(st.top().first < cur_elev){
            // cout << "ENT\n";
            auto [fr, idx] = st.top(); st.pop();
            cnt += (cur_elev - land) * (last_idx - idx);
            last_idx = idx; 
            land = fr;
        }
        
        auto [fr, idx] = st.top();
        cnt += (cur_elev - land) * (last_idx - idx); 
    
        cout << cnt << " ";
        st.push({cur_elev, i});
        i ++; land = 0;
    }
    cout << endl;
    return 0;
} 
