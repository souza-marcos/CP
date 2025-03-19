#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    set<int> st; for(int i = 0; i < n; i ++){
        int a; cin >> a;
        st.insert(a);
    }

    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<int> arr;
    for(auto el : st) arr.push_back(el); //, cout << el << " ";
    // cout << endl;

    int i = 0, j = 0;
    int maxs = 1;
    while(j < sz(arr)){
        while(i < j and arr[j]-arr[i]+1 > n) i ++;
        while(j + 1 < sz(arr) and arr[j + 1]-arr[i]+1 <= n)j ++;
        maxs = max(maxs, j-i+1);
        
        // cout << i << " " << j << " " << arr[j]-arr[i] + 1 << endl;
        
        j ++;
    }
    cout << maxs << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
