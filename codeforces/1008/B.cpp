#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;

    vector<int> res(n);
    if(k%2 == 0){
        for(int i = 0; i <= n-3; i ++)res[i] = n-1;
        res[n-2]=n;
        res[n-1]=n-1;
    }else{
        for(int i = 0; i <= n-2; i ++)res[i] = n;
        res[n-1]=n-1;
    }
    for(auto el : res) cout << el << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
