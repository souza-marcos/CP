#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    ll x; cin >> x;
    vector<int> res(31, 0);
    for(int i = 0; i < 30; i++){
        if(x%2){
            if(res[i]){ // prev = 2^i + x. And I want prev + 2^i. So prev = 2^(i+1) - 2^i 
                res[i + 1] = 1;
                res[i] = 0;
            }
            else if(i > 0){
                if(res[i - 1] == 1){// 2^(i-1) + 2^i = 2^(i+1)-2^(i-1)
                    res[i + 1] = 1;
                    res[i - 1] = -1;
                } else{
                    res[i] = 1;
                }
            } 
            else if(i == 0){
                res[i] = 1;
            }
        }
        x /= 2;
    }
    cout << 31 << endl;
    for(auto el: res) cout << el << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
