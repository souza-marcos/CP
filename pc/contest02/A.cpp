#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

void solve(){
    int l1, l2, r1, r2; cin >> l1 >> r1 >> l2 >> r2; 

    int a = l1, b = l2;
    if(l1 == l2) b = r2;
    cout << a << " " << b << endl;
}

int main(){_

    int q; cin >> q;
    while(q --) solve();

    return 0;
}