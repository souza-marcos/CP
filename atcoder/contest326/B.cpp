#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _


    int x; cin >> x;
    int h = x / 100, t = ( x%100 )/10, u = (x%100)%10;

    if(h * t < u){
        if(t < 9) t ++;
        else h ++;
    }
    if(h * t <= 9) cout << h << t << h*t << endl;
    else cout << h + 1 << "00" << endl;

    return 0;
} 
