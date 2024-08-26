#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

int main(){_

    ll n; cin >> n;
    ll cont = 0, n_initial = n; 
    for(ll i = 2; i * i <= n_initial; i++){
        if(n % i != 0) continue;
        while(n % i == 0) n /= i; 
        cont ++;
    }

    if(n > 1) cont ++;
    ll ans = 1LL << cont; // 2^n - n(tamanho 1) - 1(tamanho 0)
    ans -= (cont + 1);
    cout << ans << endl;

    return 0;
}