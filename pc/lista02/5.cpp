#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n; cin >> n;
    int v[n + 2]; v[0] = v[n + 1] = 0;
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = 1; i <= n; i++){
        int maxv = min(v[i-1], v[i+1]) + 1;
        v[i] = min(v[i], maxv);
    }
    for(int i = n; i>=1; i--){
        int maxv = min(v[i-1], v[i+1]) + 1;
        v[i] = min(v[i], maxv);
    }

    int maxv = 0;
    for(auto el: v) maxv = max(maxv, el);

    cout << maxv << endl;

    return 0;
}