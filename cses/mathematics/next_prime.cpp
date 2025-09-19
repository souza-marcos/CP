#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6;

// The maximum gap between primes in the range 1 .. 1e12 is ~ 600.
int main(){ _ 

    int t; cin >> t;
    while( t--){
        ll n; cin >> n;
        if(n == 1) {
            cout << "2\n";
            continue;;
        }
        while(true){
            n ++;
            if(n % 2 == 0) continue;
            bool ok = true;
            for(ll i = 3; i * i <= n; i += 2){
                if(n%i == 0){
                    ok = false;
                    break;
                }   
            }
            if(ok) {
                cout << n << endl;
                break;
            }
        }

    }


    return 0;
} 
