#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n, cont = 0; cin >> n;

    while(n > 1){
        if(n % 6 == 0) { cont ++; n /= 6;}
        else if(n % 3 == 0) { cont += 2; n /= 3;}
        else { cout << -1 << endl; return; }
    }
    cout << cont << endl;

}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
