#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    int n;
    cin >> n;

    int a,b;
    cin >> a >> b;
    vector<bool> bad(a,false);
    for(int i=0;i<b;i++) {
        int x;
        cin >> x;
        bad[x] = true;
    }

    for(int i=1;i<=n;i++) {
        int m,qr=0;
        cin >> m;

        for(int j=0;j<m;j++) {
            int x;
            cin >> x;
            if(bad[x]) qr+=3;
        }

        if(qr>m) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    
}