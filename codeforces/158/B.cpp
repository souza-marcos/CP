#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    ll total = 0;
    total = arr[0] - 1;

    for(int i = 1; i < n; i++)
        if(arr[i] > arr[i - 1])
            total += (arr[i] - arr[i - 1]);
    
    cout << total << endl;
}


int main(){ _
    int t; cin >> t;

    while(t --) solve();

    return 0;
} 
