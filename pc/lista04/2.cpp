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
const int lim = 2e6 + 10;
vector<int> factor(lim + 1, 1), mult(lim + 1); 
vector<int> res(lim + 1);

void crivo(){
    for(int i = 1; i <= lim; i++) factor[i] = i, mult[i] = 1;

    for(int i = 2; i <= lim; i++){
        if (factor[i] == i){
            for(int j = 2 * i; j <= lim; j += i) {
                factor[j] = i, mult[j] = 1;
                if((j/i) % i == 0) mult[j] = mult[j/i] + 1;
            }
        }
    }
}

int n;
int last = 1;

void solve(){
    if(n <= last) { cout << res[n] << endl; return;}
    
    for(int i = last + 1; i <= n; i++){
        if(factor[i] != i){
            int root = sqrt(i);
            if(root * root != i) { // qtd par de divs
                res[i] = res[i-1];
                continue;
            }
            int divs = 0;
            for(int j = 1; j * j < i; j++) if(i%j==0) divs++;
            divs <<= 1; divs++;
            
            res[i] = res[i-1] + (factor[divs] == divs);
        }
        else res[i] = res[i-1] + 1;
    }
    last = n;
    cout << res[n] << endl;
}

int main(){ _
    res[0] = res[1]= 0;
    crivo();
    while(cin >> n) solve();
    return 0;
} 
