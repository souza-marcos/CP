#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _
    int n, q, x; string s; string c;
    cin >> n >> q >> s;

    int cnt = 0;
    for(int i = 0; i < n;){
        if(s[i] < 'A' or s[i] > 'C') {
            i ++; continue ;
        }
        
        if(i + 2 < n and s.substr(i, 3) == "ABC"){
            cnt ++;
            i += 3;
        } else i ++;
    }

    auto printcnt = [&](){
        // cout << cnt << " " << s << endl;    
        cout << cnt << endl;
    };
    auto check = [&](int der){
        for(int i = max(0, x-2); i <= min(x,n-3);){
            if(s.substr(i, 3) == "ABC") cnt += der, i += 3;
            else i ++;
        }    
    };

    while(q --){
        cin >> x >> c; x--;
        if(s[x] == c[0]) {
            printcnt();
            continue;
        }

        check(-1);
        s[x]= c[0];
        check(+1);
        printcnt();
    }

    return 0;
} 
