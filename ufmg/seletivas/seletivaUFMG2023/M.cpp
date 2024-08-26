#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

const int MAX = 1e4 + 1;
int a, b;
int main(){ _
    cin >> a >> b;

    int cont = 0;
    while(b > a) { 
        if(b%2) b ++, cont ++;
        else b /= 2, cont ++; 
    }
    cout << cont  + (a-b) << endl;

    return 0;
} 
