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
const int lim = 1e5 + 10;
vector<int> primes;
int n;

bool isPrime(int val){
    auto it = lower_bound(primes.begin(), primes.end(), val);
    return (*it) == val;
}

void solve(){
    if(!isPrime(n)) {cout << "Nada\n"; return; }
    while(n){
        int dig = n%10;
        if(dig != 2 and dig != 3 and dig != 5 and dig != 7) { cout << "Primo\n"; return; }
        n/= 10;
    }
    cout << "Super\n";
}

void crivo(){
    vector<bool> is_prime(lim, true);
    int i = 2;
    is_prime[0] = is_prime[1] = false;
    for(; i * i <= lim; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i * i; j <= lim; j += i) is_prime[j] = false;
        }
    }
    for(; i <= lim; i++) if(is_prime[i]) primes.push_back(i);

}


int main(){ _
    crivo();
    while(cin >> n) solve();
    return 0;
} 
