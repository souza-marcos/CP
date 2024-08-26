#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int lim = 1e7+10;
vector<bool> ehprimo(lim, 1);
int a, b;

void crivo(){
    ehprimo[0] = ehprimo[1] = 0;
    int i = 2;
    for(; i * i <= b; i++){
        if(ehprimo[i]){
            for(int j = i * i; j <= b; j += i)
                ehprimo[j] = 0;
        }
    }
}

int main(){ _
    cin >> a >> b;
    if(a == b) {cout << "?\n"; return 0;}
    if(a > b) swap(a, b);

    crivo();

    int f = 0, k= b-a;
    for(int i = a; i <= b; i++) f += (ehprimo[i]); 

    if(f == 0 or k == 0) { cout << "Bob\n"; return 0; }

    vector<ll> div2(f + k );
    div2[0] = div2[1] = 0;
    for(int i = 2; i < f + k; i++) 
        if(!(i&1)) div2[i] = div2[i >> 1] + 1;

    for(int i = 1; i <= f + k; i++) div2[i] += div2[i -1];

    if(div2[f + k -1] - div2[k] - div2[f-1] > 0) cout << "Bob\n";
    else cout << "Alice\n";

    return 0;
} 
