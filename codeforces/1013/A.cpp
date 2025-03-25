#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    vector<int> cnt(10);
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    for(int i = 0; i < n; i ++){
        cnt[arr[i]] ++;

        if(cnt[0] >= 3 and cnt[1] > 0 and cnt[2] >= 2 and cnt[3] > 0 and cnt[5] > 0)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
 
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
