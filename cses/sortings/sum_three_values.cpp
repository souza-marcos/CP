#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

// bruto duas coord e busca binaria na terceira

int32_t main(){ _ 
    int n, x; cin >> n >> x;
    vector<ll> arr(n); 
    map<ll, vector<int>> invert;
    int i = 0;
    for(ll& el : arr) cin >> el, invert[el].push_back(i++);
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i ++){
        for(int j = i + 2; j < n; j ++){
            ll sum = arr[i] + arr[j];
            ll rest = x-sum;
            if(rest < arr[i]) break;
            if(rest > arr[j]) continue;
            auto it = lower_bound(arr.begin() + i + 1, arr.begin() + j, rest);
            int pos = it - arr.begin();
            if(it == (arr.begin() + j) or (*it) != rest or pos == i or pos == j) continue;
            else {
                // cout << arr[i] << " " << arr[j] << " " << arr[pos] << endl;
                int idx_j = invert[arr[j]].back(); invert[arr[j]].pop_back();
                int idx_k = invert[arr[pos]].back(); invert[arr[pos]].pop_back();
                int idx_i = invert[arr[i]].back(); invert[arr[i]].pop_back();

                // cout << i << " " << j << " " << pos << endl;
                cout << idx_i + 1 << " " << idx_k  + 1<< " " << idx_j + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;       
}
