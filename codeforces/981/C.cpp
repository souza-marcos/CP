#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n); for(int& el : a) cin >> el;
    vector<pair<int, int>> b(n/2);

    for(int i = 0; i < n/2; i ++){
        b[i] = {a[i], a[n-i-1]};
    }

    for(int i = 1; i < n/2; i ++){
        if(b[i].first == b[i-1].first
        or b[i].second == b[i-1].second) 
            swap(b[i].first, b[i].second);
    }

    int cnt = 0;
    for(int i = 0; i < n/2; i ++){
        if(b[i].first == b[i-1].first) cnt ++;
        if(b[i].second == b[i-1].second) cnt++;
    }
    if(n&1) cnt += (b[n/2 -1].first == a[n/2]) + (b[n/2 -1].second == a[n/2]); 
    else cnt += (b[n/2 -1].first == b[n/2 - 1].second);

    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
