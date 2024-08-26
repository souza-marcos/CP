#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    double n; cin >> n;

    double l = 0.0, r = 1e8 +10, eps = 1e-6;

    for(int i=0; i<200; i++){   // while(r - l > eps){ PROBLEMA DE LOOPING INFINITO 
        double m = (l+r)/2;
        if(m*m >  n) r = m;
        else l = m; 
    }
    cout << (l + r)/2 << endl;

    return 0;
} 
