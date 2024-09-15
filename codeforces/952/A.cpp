    #include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

int main(){ _
    int t; cin >> t;
    while(t --) {
        
        string s, s2; cin >> s >> s2;
        char aux = s[0];
        s[0] = s2[0];
        s2[0] = aux;
        cout << s << " " << s2 << endl;
    }


    return 0;
} 
