#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n, m, k; cin >> n >> m >> k;
    if(abs(n - m) > k or max(n, m) < k) {
        cout << -1 << endl;
        return;
    }

    bool zero = false;

    if(n >= m) zero = true;
    for(int i = 0; i < k; i ++)
        cout << (zero? 0: 1);
    if(zero) n-=k;
    else m-=k;

    while(n > 0 and m > 0){
        
        if(zero){
            int lim = min(k, m);
            for(int i = 0; i < lim; i++)
                cout << 1, m --;
        }
        else {
            int lim = min(k, n);
            for(int i = 0; i < lim; i++)
                cout << 0, n--;
        } 
        zero = !zero;
    }  
    zero = (n > m);
    for(int i = 0; i < max(n, m); i ++)
        cout << (zero ? 0 : 1);
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
