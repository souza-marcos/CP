#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int t; cin >> t;
    while(t --){
        int n, k; cin >> n >> k;
        int dec = 1;
        int cur = 0, uni = n, cnt= 0;
        while(cur < k){
            if(dec % 2 == 0) {
                uni --;
            }
            dec = (dec + 1) %2;
            cur += uni;
            cnt ++;
        }
        cout << cnt << endl;
    }

    return 0;
} 
