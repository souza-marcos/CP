#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
   
int main(){ _

    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    for(int i = l; i < n-r; i ++) cout << s[i];
    cout << endl;

    return 0;
} 
