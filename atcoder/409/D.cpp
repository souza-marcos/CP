#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int t; cin >> t;
    while(t --) {
        int n; cin >> n;
        string s; cin >> s;
        if(n == 1) cout << s << endl;
        else{
            char ch = '$'; bool cabou = false, comecou = false; 
            for(int i = 0 ; i <n-1; i++){

                if(ch == '$' and s[i] > s[i+1]){
                    ch = s[i];
                    comecou = true;
                }
                else if(ch != '$' and ch < s[i+1]){
                    s[i] = ch;
                    ch = '$';
                    cabou = true;
                    break;
                }
                
                if(ch != '$') s[i] = s[i+1];
            }
            if(comecou and !cabou) s[n-1] = ch;
            cout << s << endl;
        }
    }

    return 0;
} 
