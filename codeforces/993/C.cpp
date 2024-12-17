#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


int main(){ _
    int t; cin >> t;
    while(t --){
        int m, a, b, c; cin >> m >> a >> b >> c;

        int cnt = 0;
        int res1 = min(m, a), res2 = min(m, b);
        cnt += res1 + res2;
        res1 = m - res1;
        res2 = m - res2;
        int res3 = min(c, res1+res2);
        cnt += res3;
        cout << cnt << endl;
    }

    return 0;
} 
