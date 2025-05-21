#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    multiset<int> st;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        st.insert(-a);
    }
    for(int i = 0; i < m; i ++){
        int a; cin >> a;
        auto it = st.lower_bound(-a);
        if(it == st.end()){
            cout << -1 << endl;
        }
        else{
            cout << -(*it) << endl;
            st.erase(it);
        }
    }
    
    return 0;
} 
