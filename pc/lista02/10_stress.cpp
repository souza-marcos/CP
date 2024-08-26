#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

ll digit(int n){
    ll ans = 0;
    while(n > 1) ans += n%10, n /= 10;
    ans += n;
    return ans;
}

int main(){_

    int n; cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += digit(i);

    cout << ans;
    return 0;
}