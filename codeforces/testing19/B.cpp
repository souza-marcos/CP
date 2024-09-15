#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    vector<bool> v(3, true);
    int a; cin >> a; a--; v[a] = false;
    cin >> a; a--; v[a] = false;
    for(int i = 0; i < 3; i ++) if(v[i]) cout << i + 1 << endl;
    return 0;
} 
