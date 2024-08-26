#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n, temp; cin >> n;
    if(n == 1) {cout << 1 << endl; return 0;}

    cin >> temp;
    int last = temp, cont = 1;
    ll sum = 0;
    for(int i = 1; i < n; i++){
        cin >> temp;
        if(temp == last) ++cont;
        else{
            sum += 2 * ((cont/2.0) * ((cont + 1)/2.0)); 
            cont = 1;   
        }
        last = temp;
    }
    sum += 2 * ((cont/2.0) * ((cont + 1)/2.0)); 
    cout << sum << endl;

    return 0;
} 
