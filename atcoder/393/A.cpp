#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    string s, t; cin >> s >> t;
    if(s == "fine"){
        if(t == "fine") cout << 4 << endl;
        else cout << 3 << endl;
    } else {
        if(t == "fine") cout << 2 << endl;
        else cout << 1 << endl;    
    }


    return 0;
} 
