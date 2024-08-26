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

vector<int> pos;
vector<ll> numbers;

void solve(){
    ll n; cin >> n;
    pos.clear();
    numbers.clear();
    
    for(int i = 0; i < 64; i++){
        if(n & (1LL << i)) pos.push_back(i);
    }

    numbers.push_back(n);
    for(auto el: pos){
        ll val = ~(1LL << el) & n;
        if(val != 0) numbers.push_back(val);      
    }

    sort(numbers.begin(), numbers.end());
    cout << sz(numbers) << endl;
    for(auto el: numbers){
        cout << el << " ";
    }
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
