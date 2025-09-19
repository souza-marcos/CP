#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n; ll k; cin >> n >> k;
    vector<ll> arr(n); 
    for(auto& el : arr) cin >> el;

    map<ll, pair<int, int>> sums; // sums of pair 0 .. i-1
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < i-1; j ++){
            ll cur = arr[i-1] + arr[j];
            sums[cur] = {i-1, j};
        }

        for(int j = i + 1; j < n; j ++){
            ll cur = arr[i] + arr[j];

            ll looking = k - cur;
            if(sums.count(looking)){
                auto [k, l] = sums[looking];
                cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << endl;
                exit(0);
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
