#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n; cin >> n;
    int minv = 0, cnt = 0;
    { // last digit is 0 
        ll aux=n;
        bool ok = 0;
        while(aux > 0){
            if(ok and (aux%10 == 5 or aux%10 == 0)){
                break; 
            }
            if(!ok and aux%10 == 0)
                ok = true, cnt --;

            cnt ++;
            aux/=10;
        }
        minv = (ok?cnt:INF);
    }
    {
        ll aux = n;
        bool ok = 0;
        cnt = 0;
        while(aux > 0){
            if(ok and (aux%10 == 7 or aux%10 == 2)){
                break; 
            }
            if(!ok and aux%10 == 5)
                ok = true, cnt --;

            cnt ++;
            aux /= 10;
        }
        minv = min(cnt, minv);
    }
    cout << minv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
