#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    
    int x; cin >> x;
    vector<int> ans;
    vector<int> rep(32);
    for(int i = 0; i < 30; i++)
        rep[i] = ((x >> i) & 1);

    for(int j = 0; j < 32; j ++){

        for(int i = 30; i > 0; i--){
            if(rep[i] == 1 and rep[i-1] == 1){
                rep[i + 1] = 1;
                rep[i] = 0;
                rep[i-1]=-1;
            }
            if(rep[i] == 1 and rep[i-1] == -1){
                rep[i] = 0;
                rep[i-1]=1;
            }
            if(rep[i] == -1 and rep[i-1] == 1){
                rep[i] = 0;
                rep[i-1]=-1;
            }
        }
    }

    for(int i = 31; i >= 0; i --)
    {
        if(rep[i]){
            cout << i + 1 << endl;
            for(int j = 0; j <= i; j++){
                cout << rep[j] << " ";
            }
            cout << endl;
            return;
        }
    }



}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
