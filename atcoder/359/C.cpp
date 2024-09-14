#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

// in extrema direita
bool in_exd(int x, int y){
    return (x + y) % 2;
}

int main(){ _
    ll inx, iny, outx, outy; cin >> inx >> iny >> outx >> outy;
    inx ++, iny ++, outx ++, outy ++;

    

    cout << abs(inx - outx) + abs(iny - outy);

    return 0;
} 
