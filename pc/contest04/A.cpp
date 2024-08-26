#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;

    
    int j = 0, k = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] > b[i]) j ++;
        if(a[i] < b[i]) k ++;
    }

    if(j == k) cout << "EQUAL\n";
    else if(j > k) cout << "RED\n";
    else cout << "BLUE\n";
}


int main(){_

    int t; cin >> t;
    while(t --) solve();

    return 0;
}