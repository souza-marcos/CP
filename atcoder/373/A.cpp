#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    string s; int cnt = 0;
    for(int i = 1; i <= 12; i++){
        cin >> s;
        if(sz(s) == i) cnt ++;
    }
    cout << cnt << endl;
    return 0;
} 
