#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    map<int, int> f;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        f[a] ++;
    }


    int paircnt = 0;
    for(auto &[el, cnt]: f){
        int comp = k - el;

        if(f.count(comp)){
            if(el == comp) paircnt += cnt/2;
            if(el < comp) paircnt += min(cnt, f[comp]);
        }
    }

    cout << paircnt << endl; //<< " " << solocnt << endl;


}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
