#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    sort(v.begin(), v.end());

    //for(auto& x: v) cout << x << " ";
    //cout << endl;

    int ans = 0, bi, bj, bk;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a = v[i], b = v[j];

            for(int k = 0; k < n; k++){
                if(k < 0 or k >= n) continue;
                int c = v[k];
                int res = a*a+b*b+c*c-a*b-a*c-b*c;
                if(ans < res) ans = res, bi = i, bj = j, bk = k;
            }
        }
    }    

    cout << ans << endl;
    // cout << ans << " " << bi << " " << bj << " " << bk << endl;
}