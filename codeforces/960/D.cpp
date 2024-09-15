#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
// Nao consegui, tive que ver o editorial

void solve(){
    int n; cin >> n;
    vector<int> v(n); 
    for(auto& el : v) cin >> el;
    
    int cnt = 0;
    bool col1 = false, col2 = false;
    for(int i = 0; i < n; i++){
        
        if(col1){
            col1 = false;
            if(v[i] <= 2) continue;
            cnt ++;
            if(v[i] <= 4) col2 = true;
        }
        else if(col2){
            col2 = false;
            if(v[i] == 0) continue;
            cnt ++;
            if(v[i] <= 4) col1 = true;
        }
        else{
            if(v[i] == 0) continue;
            cnt ++;
            if(v[i] <= 2) col1 = true;
        }

    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
