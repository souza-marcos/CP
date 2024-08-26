#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_
    string s;
    cin >> s;

    int n = s.size();
    int mi[n + 1], ma[n + 1];

    mi[0] = 0;
    ma[n] = 0;
    for(int i = 1; i< n + 1; i++) mi[i] = mi[i-1] + (islower(s[i-1])?1:0);
    for(int i = n-1; i >= 0; i--) ma[i] = ma[i + 1] + (isupper(s[i])?1:0);

    int minv = INF;

    // for(int i = 0; i < n + 1; i++) cout << mi[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n + 1; i++) cout << ma[i] << " ";
    // cout << endl;

    int a; a = 0;
    for(int i = 0; i < n; i++){
        a += (islower(s[i])?1:0);
        minv = min(minv, mi[i] + ma[i + 1]);
    }

    cout << minv << endl;

    return 0;
}