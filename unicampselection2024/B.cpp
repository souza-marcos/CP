#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _
    int m; cin >> m;
    string t; cin >> t;

    reverse(t.begin(), t.end());
    int val = (2*(t[0]-'0') + 1 );
    int carry = val/10;
    t[0] = val%10 + '0';
    for(int i = 1; i < sz(t); i ++){
        int val = 2*(t[i] - '0')+carry;
        t[i] = val%10 + '0', carry = val/10;
    }
    if(carry > 0) t.push_back(carry + '0');
    reverse(t.begin(), t.end());
    cout << t << endl;

} 
