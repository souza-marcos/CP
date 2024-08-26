#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> v;
int n, a, b; 

bool valid(ll qtd){
    ll x = a - b;
    ll cont = 0;
    for(int el: v){
        if(el > qtd*b) cont += ceil((el - qtd*b)/(double)x);
        if(cont > qtd) return false;
    }
    return true;
}

int main(){ _
    cin >> n >> a >> b;
    v.assign(n, {}); for(auto& el: v)cin >> el;

    ll l = 0, r = 1e10;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(!valid(m)) l = m;
        else r = m;
    }
    cout << r << endl;
    return 0;
} 
