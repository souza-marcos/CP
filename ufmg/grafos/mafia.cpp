#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n; cin >> n;
    vector<int> arr(n); for(auto& el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    auto check = [&](ll m) -> bool {
        ll cnt = 0;
        for(int el : arr){
            cnt += m - el;
            if(cnt >= m) return true;
        }
        return false;
    };

    ll l = arr.back()-1, r = 1e15;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(check(m)) r = m;
        else l = m;   
    }
    cout << r << endl;

    return 0;
} 
