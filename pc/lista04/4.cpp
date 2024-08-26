#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int lim = 1e6 + 1;
vector<int> primos;
vector<bool> ehprimo(lim, 1);

void crivo(){
    
    ehprimo[0] = ehprimo[1] = 0;
    int i = 0;
    for(; i * i < lim; i++){
        if(ehprimo[i]){
            for(int j = i*i; j < lim; j+=i)
                ehprimo[j] = false;
            primos.push_back(i);
        }
    }
    for(;i<lim; i++) if(ehprimo[i]) primos.push_back(i);

}

int mdc(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int d = mdc(b, a%b, x1, y1);
    x=y1, y = x1 - y1 *(a/b);
    return d;
}

int inv(int a, int p){
    int x, y;
    int g = mdc(a, p, x, y);
    assert(g == 1);
    x= (x%p + p) %p;
    return x;
}

ll fexp(ll base, ll n, ll p){
    base %= p;
    ll ans = 1;
    while(n){
        if(n & 1) ans = (ans * base)% p;
        base = (base * base) % p;
        n >>= 1;
    }
    return ans;
}


int main(){ _
    crivo();
    int n, e, c; cin >> n >> e >> c;
    ll p = 0, q = 0;
    for(auto el: primos){
        if(n % el == 0){
            p = el, q = n/el;
        }
    }
    assert(p != 0);
    
    ll phi = (p-1) * (q-1);
    int d = inv(e, phi); 
    ll res = fexp(c, d, n);
    
    cout << res << endl; 
    return 0;
} 
