#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _ 
    int n, y; cin >> n >> y;
    vector<int> v(n); for(auto& x: v) cin >> x;

    for(int i = 0; i < n-1; i++) if(v[i]+v[i+1] == y){ cout << 0 << endl; return 0;}

    cout << 1 << endl;
    return 0;
}