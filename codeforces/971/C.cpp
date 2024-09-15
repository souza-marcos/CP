#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int x, y, k; cin >> x >> y >> k;
    int st_x = ceil(x/(double)k), st_y = ceil(y/(double)k);
    int ans = 0;
    if(st_x <= st_y){
        st_y -= st_x, ans+= st_x, st_x = 0;
    }else st_x -= st_y, ans += st_y, st_y = 0;
    ans <<= 1;
    
    if(st_x > 0) ans += 2 * st_x -1;
    if(st_y > 0) ans += 2 * st_y;
    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
