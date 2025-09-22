#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    int i = 0;
    for(auto& [el, idx] : a) cin >> el, idx = i ++; 
    for(int& el : b) cin >> el;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int shift = n-x;
    int cnt = 0;
    vector<int> res(n);
    for(int i = 0; i < n; i ++){
        int next = (i+shift) % n;
        cnt += a[next].first > b[i];
        res[a[next].second] = b[i];
    }

    if(cnt != x){
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for(auto el : res) cout << el << " ";
        cout << endl;
    }
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
