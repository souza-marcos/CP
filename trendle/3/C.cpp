#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int n; cin >> n;
    int d = 0;
    vector<int> arr(n); 
    
    int cnt = 0;
    for(auto& el : arr) 
        cin >> el, d = __gcd(d, el), cnt += (el == 1ll);
    
    if(d != 1) {
        cout << -1 << endl;
        exit(0);
    }
    
    int mind = INF;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j++){
            if(__gcd(arr[i], arr[j]) == 1) {
                mind = min(mind, j-i);
                break;
            }
        }
    }
    if(mind == INF) mind = 1;

    cout << n + mind -1 - cnt << endl;


} 
