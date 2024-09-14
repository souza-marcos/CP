#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, m, k; cin >> n >> m >> k;
    vector<int> ks(m, 0);
    vector<int> res(m, 0);

    for(int i = 0; i < m; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int a; cin >> a;
            a --;
            ks[i] |= (1 << a); // Adding key to set 
        }

        string s; cin >> s;
        if(s == "o") res[i] = 1;
        else res[i] = 0;
    }

    int ans = 0;
    // Iterate over all possible keys
    for(int i=0; i < (1<<n); i++){
        bool judge = true;
        for(int j=0; j<m; j++){
            int ok = __builtin_popcount(i & ks[j]);

            if(ok >= k && res[j] == 0){
                judge = false; break;
            }
            if(ok < k && res[j]){
                judge = false; break;
            }
        }
        if(judge) ans ++;
    }
    cout << ans << endl;

    return 0;
} 
