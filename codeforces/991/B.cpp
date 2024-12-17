#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n; cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(ll& el : arr) cin >> el, sum += el;

    if(sum % n != 0){
        cout << "NO\n";
        return;
    }

    ll mean = sum / n;

    auto calc = [mean, n](vector<ll> arr) -> bool{
        for(int i = 1; i < n-1; i ++){
            if(arr[i-1] > mean){
                arr[i+1] += (arr[i-1]-mean);
                arr[i-1] = mean;
            } else if(arr[i-1] < mean){
                arr[i+1] -= (mean - arr[i-1]);
                arr[i-1] = mean;
            }
        }

        for(auto el: arr) if(el != mean) return false;
        return true;
    };
    bool ok = calc(arr);
    if(!ok) cout << "NO\n";
    else  cout << "YES\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
