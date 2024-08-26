#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
ll pre[101][101][101];

int main(){ _

    int n; cin >> n;
    ll arr[n][n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            for(int k = 0; k < n; k++){
                cin >> arr[i][j][k];
            }
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            for(int k = 1; k <= n; k ++){
                pre[i][j][k] = 
                      pre[i][j-1][k]
                    + pre[i-1][j][k]
                    - pre[i-1][j-1][k]
                    + pre[i][j][k-1]
                    - pre[i][j-1][k-1]
                    - pre[i-1][j][k-1]
                    + pre[i-1][j-1][k-1]
                    + arr[i-1][j-1][k-1];
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int lx, rx, ly, ry, lz, rz; 
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll res =  pre[rx][ry][rz]
                - pre[lx-1][ry][rz]
                - pre[rx][ly-1][rz]
                + pre[lx-1][ly-1][rz]
                - pre[rx][ry][lz-1]
                + pre[lx-1][ry][lz-1]
                + pre[rx][ly-1][lz-1]
                - pre[lx-1][ly-1][lz-1];


        // ll res =  pre[ry][rx][rz]
        //         - pre[ry][lx-1][lz-1]
        //         - pre[ly-1][rx][lz-1]
        //         + pre[ly-1][lx-1][lz-1];

        cout << res << endl;
    }
    return 0;
} 
