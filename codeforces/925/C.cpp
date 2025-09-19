#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll 

void solve(){
    int n; cin >> n;
    vector<int> arr(n); for(int i = 0; i < n; i ++) cin >> arr[i];

    
    auto side = [&]() -> int {
        int i = 0;
        while(i < sz(arr) and arr[i] == arr[0]) 
            i ++;
        return i;
    };

    if(arr[0] != arr.back()){
        int v1 = sz(arr) - side();
        reverse(arr.begin(), arr.end());
        int v2 = sz(arr) - side();
        cout << min(v1, v2) << endl;
    }else{
        int i = side();
        reverse(arr.begin(), arr.end());
        int j = sz(arr) - side()-1;
        cout << max(0, j-i+1) << endl;
    }


}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
