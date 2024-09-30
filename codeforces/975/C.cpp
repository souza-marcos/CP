#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, k; cin >> n >> k;
    ll sum= 0;
    vector<ll> cards(n); for(auto& el: cards) cin >> el, sum += el;

    sort(cards.rbegin(), cards.rend());
    // Find the minimum of partitions
    
    auto canpart = [&](ll guess){
        ll h = ceil(sum/(double)guess);
        
        return true;
    };
    
    ll l = cards[0]-1, r = 1e18;
    while(l+1<r){
        ll m = (l+r)/2;
        if(canpart(m)) r=m;
        else l=m;
    }
    // TODO: Size of partition
    cout << r << endl;
}

int main(){ _
    int t; cin >> t;;
    while(t --) solve();
    return 0;
} 
