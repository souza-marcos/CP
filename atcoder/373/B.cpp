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
    string s; cin >> s;
    vector<int> pos(26);
    for(int i = 0; i < 26; i ++){
        pos[s[i] - 'A'] = i;
    }
    int cnt  = 0, last = pos[0];
    for(int i = 0; i < 26; i ++){
        cnt += abs(pos[i] - last);
        last = pos[i];
    }
    cout << cnt << endl;

    return 0;
} 
