#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


// Execute binary search 
// 1 ... 1 1 1 0 0 0 ...
vector<int> arr;
bool valid(int l_in, int m, int k){
    int temp = arr[l_in];
    while(l_in <= m){
        temp &= arr[l_in ++];
        if(temp >= k) return true;
    }
    return false;
}


void solve(){
    arr.clear();
    int n; cin >> n;
    arr.resize(n);
    for(auto &el: arr) cin >> el;

    int q; cin >> q;
    int l_in, k;
    while(q --){
        cin >> l_in >> k;

        // busca
        int r = n - 1, l = l_in;
        while(r > l + 1){
            ll m = (l + r)/2;
            if(valid(l_in, m, k)) l = m;
            else r = m;
        }

        if(valid(l_in, r, k)) cout << r << " ";
        else cout << -1 << " ";

    }
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
