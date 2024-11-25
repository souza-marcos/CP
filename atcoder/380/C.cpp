#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0, qtd = 0, in = 0;
    bool ok = false;
    for(int i = 0; i < n; i ++){
        if(in == 0 and s[i] == '1') in = 1, cnt ++;
        else if(in == 1 and s[i] == '0') in = 0;

        if(in == 0 and cnt == k-1){ qtd ++; continue; } 
        cout << s[i];
        if(in == 0 and cnt >= k  and !ok){
            ok = true;
            while(qtd --) cout << '0';
        }
    }
    if(!ok)
        while(qtd --) cout << '0'; 
    
    cout << endl;
}   
