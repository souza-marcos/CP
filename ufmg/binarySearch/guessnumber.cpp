#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    // Cuidado quando manipula o +1 no m. eh preferivel adicionar na condicao

    ios_base::sync_with_stdio(0);
    int l = 0, r = 1e6 + 1;
    string n;

    while(l + 1 < r){
        int m = (l + r)/2;
        cout << m << endl;
        cout << flush;
        cin >> n;

        if(n == "<"){
            r = m;
        } 
        else {
            l = m;
        }
    }
    cout << "! "<< l << endl;
    cout << flush;

    return 0;
} 
