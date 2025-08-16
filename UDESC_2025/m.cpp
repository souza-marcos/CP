#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define ss second 
#define ff first 
#define sz(x) (int)x.size()

int32_t main() { _
	
    ll a, b, n; cin >> n >> a >> b;
    vector<pair<int, int>> arr; // altura - pos
    int cur = 0;
    for(int i = 0; i < n; i ++){
        int el;
        cin >> el; 
        cur += el;
        arr.push_back({cur, i});
    }
    int k; cin >> k; k--;
    int h = arr[k].first + b;
    sort(arr.rbegin(), arr.rend());
    int ha_res = h - a;
    int i = 0;
    while(i < n and arr[i].second == k) i++;
    if(i < n and arr[i].first >= ha_res){
        cout << "SIM\n";
        cout << arr[i].second + 1 << endl;
    }
    else cout << "NAO\n";

    // cout << "ha " << ha_res << endl;
    // for(auto [a, b]: arr) cout << a << " " << b << "\n";


}