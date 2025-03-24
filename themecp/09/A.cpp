#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, c, d; cin >> n >> c >> d;
    multiset<int> ms;
    vector<int> arr(n * n); 
    for(auto& el: arr) cin >> el, ms.insert(el);
    
    int fr = *(ms.begin());
    for(int i = 0; i < n; i ++){
        if(i > 0) fr += c;

        int cur = fr;
        for(int j = 0; j < n; j ++){
            if(j > 0) cur += d;
            
            if(ms.count(cur) == 0){
                cout << "NO\n";
                return;
            }
            ms.erase(ms.find(cur));
        }
    }

    cout << "YES\n";


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
