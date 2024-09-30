#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _
    int t; cin >> t;
    while(t --){
        int n, k, cnt = 0, cur = 0; cin >> n >> k;
        while(n --){
            int a; cin >> a;
            if(a >= k) cur += a;
            if(a == 0 and cur > 0) cnt ++, cur --;
        }
        cout << cnt << endl;
    }

    return 0;
} 
