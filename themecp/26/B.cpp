#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


void solve(){
    int n, k; cin >> n >> k;
    
    vector<ll> powa; ll cur = 1;
    while(cur <= INF) powa.push_back(cur), cur *= k;
    vector<int> a(n); for(auto& el : a) cin >> el;

    powa.push_back(LINF);

    int m; cin >> m;
    vector<int> b(m); for(auto& el : b) cin >> el;

    vector<pair<ll, ll>> posta, postb;
    for(auto el : a) {
        int i = 0;
        while(el%powa[i]==0) i++;
        i--;

        int key=el/powa[i], value = powa[i];
        if(sz(posta) and posta.back().first == key)
            posta.back().second += value;
        else posta.push_back({key, value});
    }

    for(auto el : b) {
        int i = 0;
        while(el%powa[i]==0) i++;
        i --;

        int key=el/powa[i], value = powa[i];
        if(sz(postb) and postb.back().first == key)
            postb.back().second += value;
        else postb.push_back({key, value});
    }

    int i = 0, j = 0;
    while(i < sz(posta) and j < sz(postb)){
        auto &[keya, vala] = posta[i];
        auto &[keyb, valb] = postb[j];

        if(keya != keyb or valb > vala) {
            cout << "No\n";
            return;
        }

        if(valb == vala) i++, j++;
        else i ++;
    }

    if(i == sz(posta) and j == sz(postb)) 
        cout << "Yes\n";
    else cout << "No\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
