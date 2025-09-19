#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){

    int l1, b1, l2, b2, l3, b3; cin >> l1>> b1>> l2>> b2>> l3>> b3;

    if(b3 + b2 == b1){
        if(l2 == l3){
            // baixo (cima esquerda) (cima direita)
            if(l1 + l2 == b1){
                cout << "Yes\n";
                return;
            }
        }
    }

    if(l3 + l2 == l1){
        if(b2 == b3){
            if(b1 + b2 == l1){
                cout<<"Yes\n";
                return;
            }
        }
    }


    if(l1 == l2 and l2 == l3){
        // lado lado lado
        if(b1 + b2 + b3 == l1){
            cout << "Yes\n";
            return;
        }
    }

    if(b1 == b2 and b2 == b3){
        // cima cima cima
        if(l1 + l2 + l3 == b1){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
