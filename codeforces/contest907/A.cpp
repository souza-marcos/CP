#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){

    int n; cin >> n;
    int cont = 1, temp;
    bool possible = true;

    vector<int> arr(n);
    for(auto &el : arr) cin >> el;
    for(int i = 0; i < n - 1; i++){  
        if(i + 1 == cont){
            cont = cont << 1;
            continue;
        }
        if(arr[i] > arr[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main(){ _

    int t; cin >> t;
    while(t--) solve();


    return 0;
} 
