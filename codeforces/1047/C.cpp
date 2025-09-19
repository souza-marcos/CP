#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){

    ll a, b; cin >> a >> b;
    
    
    auto calc = [&](auto&& self, ll a, ll b) -> ll{

        if(a%2 == 0 and b % 2 == 1){
            return -1ll;
        }

        if(a%2 == 0 and b%2 == 0){
            
            if(a > 2 and b > 2) return self(self, a*(b/2), 2);
            else return a + b;
        }
        if(a%2 == 1 and b%2 == 1){

            if(a < 1) return  a + b;
            else{
                a = a * b;
                b = 1;
                return a + b;
            }
        }

        if(a % 2 == 1 and b% 2== 0){
            if((b/2)%2 == 1) return -1;
            else {
                if(a <= b) {
                    a = 2 * a;
                    b = b/2;
                    return self(self, a, b);
                }else{
                    a = a * (b/2);
                    b = 2;
                    return a + b;
                }
            }
        }
    };
    cout << calc(calc, a, b) << endl;

}


int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
