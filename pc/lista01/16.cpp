#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    map<string, int> conts;
    string temp;
    while(cin >> temp) conts[temp] ++;

    cout << conts.size() << endl;
    return 0;
}