#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(auto &el : arr) cin >> el;

    int cont = 0; string key = "vika";

    for(int j = 0; j < m; j ++){
        if(cont == 4) break;
        for(int i = 0; i < n; i ++){
            if(arr[i][j] == key[cont]){
                cont ++; break;
            }
        }
    }
    cout << (cont == 4? "YES":"NO") << endl;

}

int main(){ _

    int t; cin >> t;
    while (t--)    
        solve();


    return 0;
} 
