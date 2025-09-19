#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

void solve(){
    int n, s, x; cin >> n >> s >> x;
    map<int, vector<int>> sum_pos;
    
    int ptr_equal=-1;
    int sum = 0, cnt = 0;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    
    sum_pos[0].push_back(-1);
    for(int i = 0; i < n; i ++){
        sum += arr[i];
        sum_pos[sum].push_back(i);
        if(arr[i] > x) {
            ptr_equal=i;
        }
        else {
            // pref[i] - pref[j] = s
            // pref[j] = pref[i] - s
            while(ptr_equal < n-1 and arr[ptr_equal+1] != x) 
                ptr_equal++;

            int target = sum - s;
            auto& row = sum_pos[target];
            int tam_e = sz(row) - (lower_bound(row.begin(), row.end(), ptr_equal) - row.begin());
            cnt += tam_e;
        }
    }
    cout << cnt << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
