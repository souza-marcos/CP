#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n ; cin>>n;
    vector<ll> arr(n);
    
    ll sum = 0;
    for(auto& el: arr) cin >> el, sum += el;
    
    while(n > 2){
        if(arr.back() - arr.front() < arr.front() - arr.back()){
            reverse(arr.begin(), arr.end());
        }

        ll sum_aux = 0;
        for(int i=0; i < n -1; i ++){
            arr[i] = arr[i + 1] - arr[i];
            sum_aux += arr[i];
        }
        sum = max(sum, sum_aux);
        arr.pop_back();
        n --;
    }


    ll res = 0;
    if(n == 2) res = max(abs(arr[1] - arr[0]), arr[0] + arr[1]);
    else res = arr[0];

    cout << max(res, sum) << endl;

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
