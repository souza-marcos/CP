#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> h(n); for(auto& el: h) cin >> el;
    stack<int> st, res;
    for(int i = n-1; i >= 0; i --){
        res.push(sz(st));
        while(!st.empty() and st.top() <= h[i]) st.pop();
        st.push(h[i]);
    }
    while(!res.empty()) cout << res.top() << " ", res.pop();
    cout << endl;
    return 0;
} 
