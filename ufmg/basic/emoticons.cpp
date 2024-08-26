#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    string m;
    getline(cin, m);

    int cont = 0;
    for(int i = 0; i + 2 < m.size(); i++){
        if(m[i] == ':' and m[i+1] == '-'){
            if(m[i+2] == ')') cont ++;
            if(m[i+2] == '(') cont --; 
        }
    }

    cout << (cont == 0?"neutro":(cont > 0?"divertido":"chateado")) << endl;

    return 0;
} 
