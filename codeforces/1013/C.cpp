#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    if(n%2 ==0){
        cout << -1<<endl;
    }else{
        vector<int>ans;
        int cur = 0, nnew = n;
        while(nnew--){
            ans.push_back(cur);
            cur = (cur + 2)%n;
        }
        for(auto el: ans) cout << el + 1 << " ";
        cout << endl;

    }
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
