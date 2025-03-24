#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n; ll s; cin >> n >> s;
    
    ll sum = 0;
    vector<ll> arr(n); for(auto& el: arr) cin >> el, sum += el;
    arr.insert(arr.end(), arr.begin(), arr.end());


    s = s % sum;

    if(s == 0) return cout << "Yes\n", 0;
    
    n = sz(arr);

    ll cur = 0, i = 0, j = 0;
    while(i < n){
        cur += arr[i]; i ++;
        while(cur > s and j < i) cur -= arr[j], j ++;
        if(cur == s) return cout << "Yes\n", 0;
    }
    if(cur == s) return cout << "Yes\n", 0;
    while(j < i) {
        cur -= arr[j]; j ++;
        if(cur == s) return cout << "Yes\n", 0;
    }
    cout << "No\n";
    return 0;
} 
