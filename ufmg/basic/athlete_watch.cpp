#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int r, f, c;
    cin >> r >> f >> c;
    if(f > 3*r or c < 95) cout << "diminuir\n";
    else if(f < 2*r and c>97) cout << "aumentar\n";
    else cout << "manter\n";

    return 0;
} 
