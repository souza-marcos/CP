#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        int cnt = 0;
        if(n & 1){
            n -= 9; cnt ++;
        }

        if(n >= 4){
            if(n >= 6 and (n-6) % 4 == 0){
                cnt ++, n -= 6;
            }
            int times = n/4;
            n %= 4;
            cnt += times;
        }

        if(n != 0) cout << -1 << endl;
        else cout << cnt << endl;
        // if(n&1 and n < 13){ cout << -1 << endl; continue; }
        // if(n%2 == 0 and n < 6){ cout << -1 << endl; continue; }
    }
    

    return 0;
} 
