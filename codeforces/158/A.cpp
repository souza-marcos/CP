#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){
    int n, x; cin >> n >> x;

    int last = 0, max_p = -1;

    int temp, aux;
    while(n --){
        cin >> temp;
        aux = temp;
        temp -= last; last = aux;
        max_p = max(max_p, temp);
    }
    cout << max(max_p, (x - aux)*2) << endl;
}

int main(){ _

    int t; cin>> t;
    while(t --) solve();

    return 0;
} 
