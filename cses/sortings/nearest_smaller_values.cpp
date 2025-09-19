#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n; cin >> n;
    vector<int> arr(n); for(int & el : arr) cin >> el;

    vector<pair<int, int>> st; // val - idx
    st.push_back({0,-1});
    int i = 0;
    for(int el : arr){
        while(st.back().first >= el) 
            st.pop_back();
        cout << st.back().second + 1 << " ";
        st.push_back({el, i});
        i ++;
    }
    cout << endl;
    return 0;       
}
