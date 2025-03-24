#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    string s; cin >> s;

    string zero;
    for(int i = 0; i < sz(s); i ++) zero.append("0");
    int cnt = 0;
    while(s != zero){
        // get t;
        int i = 0, j = sz(s) - 1;
        while(s[i] == '0') i ++;
        while(s[j] == '0') j --;
        
        bool one = false;
        while(i <= j){
            if(one and s[i] == '0'){
                s[i] = '1';
                one = false;
            }
            else if(!one and s[i] == '1'){
                s[i] = '0';
                one = true;
            }
            i ++;
        }
        cnt ++;
    }

    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
