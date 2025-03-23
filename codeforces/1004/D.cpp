#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

ll query(int i, int j){
    cout << "? " << i << " " << j << endl;  
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

void res(char o) {
    cout << "! " << o << endl;
    cout.flush();
}

void solve(){

    int n; cin >> n;

    vector<int> arr(n), cnt(n + 1); for(auto& el: arr) cin >> el, cnt[el] ++; 
    
    int one = -1, last = -1;

    for(int i = 1; i <= n; i ++){
        if(arr[i-1] == 1) one = i;
        if(arr[i-1] == n) last= i;    

        if(cnt[i]==0){
            int nxt = ((i + 1) % n) + 1;
            ll dist = query(i, nxt);
            if(dist == 0) res('A');
            else res('B');
            return;
        }
    }

    ll distA = query(one, last), distB = query(last, one);

    if(distA == distB and distA >= n-1) 
        res('B');
    else 
        res('A');
}


int32_t main(){ 
    int t; cin >> t;
    while(t--) solve();
}