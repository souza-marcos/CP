#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int h, m; 
    string s; cin >> s;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    string time;
    if(h < 12)time = " AM";
    else time = " PM";


    if(h > 12) h -= 12;
    else if(h == 0) h = 12;
    
    cout << (h <= 9? "0":"") << h << ":" << (m <= 9? "0": "") << m << time << "\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
