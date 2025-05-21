#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    ll max_interval_sum = 0;
    for(ll el: arr){
        if(el <= max_interval_sum + 1)
            max_interval_sum += el;
        else break;
    }
    cout <<  max_interval_sum + 1 << endl;
    return 0;   
} 

// 1 2 2 7 9 
// [1 2 3 4] 7  
