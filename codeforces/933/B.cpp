#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& el: arr) cin >> el;

    for(int i = 1; i < n - 1; i++){
        if(arr[i] < 2 * arr[i - 1] or arr[i + 1] < arr[i - 1]){
            cout << "NO" << endl;
            return;
        }
        else{
            arr[i] -= 2 * arr[i - 1];
            arr[i + 1] -= arr[i - 1];
            arr[i - 1] = 0;
        }
    }

    if(arr[n - 2] != 0 or arr[n - 1] != 0) cout << "NO" <<endl;
    else cout << "YES" << endl;

}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
