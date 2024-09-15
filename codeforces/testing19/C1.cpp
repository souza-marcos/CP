#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    string s; cin >> s;
    for(int i = 1; i < ceil(sz(s)/2.0) ; i ++){
        if(s.substr(0, sz(s)- i) == s.substr(i, sz(s) - i)){
            cout << "YES\n" << s.substr(0, sz(s) - i) << endl;
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
} 
