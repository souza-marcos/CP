#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _

    int n, x; cin >> n >> x;

    int sum = 0, temp;
    while(n --) {
        cin >> temp;
        if(temp <= x) sum += temp; 
    }
    cout << sum << endl;

    return 0;
} 
