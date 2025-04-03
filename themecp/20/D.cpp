#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    
    int n; cin >> n;
    vector<int> arr(n); 
    
    ll sum = 0;
    for(int & el: arr) cin >> el, sum += el;

    if(sum % n != 0) {
        cout << "NO\n";
        return;
    }
    sum/=n;

    auto getlow = [&](int el) -> int {
        for(int i = 0; i < 32; i ++) if((el>>i)&1) return i;
    };

    auto gethigh = [&](int el) -> int {
        for(int i = 31; i >= 0; i --) if((el>>i)&1) return i;
    };

    map<int, int> cnt;
    for(int i = 0; i < n; i ++){
        int diff=abs(arr[i] - sum);
        if(diff == 0) continue;
        
        int x = gethigh(diff), y = getlow(diff);
        int el = (1 << x) - (y==0? 0: (1 << (y-1)));
        
        cout << diff << " " << el  << " " << (1 << x) << " "  << (1 << y) << endl;
        if(diff!= el) {
            cout << "NO\n";
            return ;
        }
        cnt[x]++;
        cnt[y]--; 
    }
    bool ok = true;
    for(auto [k, val] : cnt){
        if(val != 0) ok = false;
    }
    cout << (ok? "YES\n" : "NO\n");
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
