#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4 + 10;
int n, k;
int ropes[MAX];

bool valid(double lenro){
    
    int cont = 0;
    for(int i = 0; i < n; i++){
        cont += (ropes[i] / lenro);
        if(cont >= k) return true;
    }
    return false;
}

int main(){ _

    cout << fixed << setprecision(10);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> ropes[i];

    double l = 0, r = 1e7 + 10;
    while(r - l > 1e-8){
        double m = (l + r)/2.0;
        if(valid(m)) l = m;
        else r = m;
    }

    cout << l << endl;

    return 0;
} 
