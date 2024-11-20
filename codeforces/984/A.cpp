#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> arr(n); for(int& el: arr) cin >> el;

    for(int i = 0; i < n-1; i ++){
        int val =abs(arr[i + 1] - arr[i]) ;
        if(val != 5 and val != 7){
            cout <<"NO\n";
            return;
        }
    }
    cout << "YES\n";

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
