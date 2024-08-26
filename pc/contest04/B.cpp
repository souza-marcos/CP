#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_
    int n; cin>>n;
    while(n --){
        int a, b, c; cin >> a >> b >> c;
        // cout << a << " " << b << " " << c << endl;
        if((a * b) == (c+1)) cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}