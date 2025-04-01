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
        cout << "No\n";
        return;
    }

    multiset<int> in, out;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 32; j ++){
            ll el= arr[i] + (1 << j);
            int y = 0;
            while(el > 1 and y&1 == 0){
                el >>= 1;
                y ++;
            }
            if(el == 1){

                break;
            }
        }
    }


}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
