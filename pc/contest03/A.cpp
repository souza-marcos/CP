#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> v(101, 0);

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v[a] ++;
    }
    for(int i = 1; i < 101; i++){
        if(v[i] > v[i-1]) { cout << "NO" << endl; return;}
    }

    cout << "YES" << endl;
}

int main(){_
    int n; cin >> n;
    while(n --) solve();
    return 0;
}