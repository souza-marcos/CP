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
    int n; cin >> n;
    vector<ll> arr(n); 
    for(auto& el : arr) cin >> el;

    auto calc = [&](int l, int r, int mid) -> ll {
        vector<ll> smin(n), smax(n);
        smin[mid] = smax[mid] = arr[mid];
        for(int i = mid + 1; i <= r; i ++){
            smin[i] = min(smin[i-1], arr[i]);
            smax[i] = max(smax[i-1], arr[i]);
        }

        for(int i = mid - 1; i >= l; i--){
            smin[i] = min(smin[i+1], arr[i]);
            smax[i] = max(smax[i+1], arr[i]);
        }

        vector<ll> p1(n), p2(n);
        for(int i = l; i <= r; i ++){
            p1[i] = (i > 0? p1[i-1] : 0) + smin[i];
            p2[i] = (i > 0? p2[i-1] : 0) + smax[i];
        }

        // smin   crescente   - (mid) - decrescente
        // smax   decrescente - (mid) - crescente

/*
      5 9 [1] 2 3
smin  1 1  1  1 1
smax  9 9  1  2 3



*/

        ll res = 0;
        { // minimo e maximo na direita
            


        }   

    };

    auto solve = [&](auto&& self, int l, int r) -> ll {

        if(r-l+1 <= 3){
            ll res = 0;
            for(int i = l; i <= r; i ++){
                ll minv = LINF, maxv = -LINF;
                for(int j = i; j <= r; j ++){
                    minv = min(minv, arr[j]), maxv = max(maxv, arr[j]);
                    res += minv * maxv;
                }
            }
            return res;
        }

        int mid = (l + r)/2;
        return self(self, l, mid-1) + self(self, mid+1, r) + calc(l, r, mid);
    };
    cout << solve(solve, 0, n-1) << endl;
}