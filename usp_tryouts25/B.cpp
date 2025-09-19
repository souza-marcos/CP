#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (ll)x.size()


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// para declarar:
// ord_set<ll> s;
// coisas do set normal funcionam:
// for (auto i : s) cout << i << endl;
// cout << s.size() << endl;
// k-esimo maior elemento O(log|s|):
// k=0: menor elemento
// cout << *s.find_by_order(k) << endl;
// quantos sao menores do que k O(log|s|):
// cout << s.order_of_key(k) << endl;

// Para fazer um multiset, tem que
// usar ord_set<pair<ll, ll>> com o
// segundo parametro sendo algo para diferenciar
// os ementos iguais.
// s.order_of_key({k, -INF}) vai retornar o
// numero de elementos < k

void brute(vector<pair<ll,ll>> &ans,vector<pair<ll,ll>> &v, pair<ll,ll> act, ll i) {
    if(i==v.size()) ans.push_back(act);
    else {
        brute(ans,v,act,i+1);
        act.ff+=v[i].ff;
        act.ss+=v[i].ss;
        brute(ans,v,act,i+1);
    }
}

int main() { _
    ll n,a1,a2,d1,d2;
    cin >> n;

    vector<pair<ll,ll>> v1(n/2),v2(n-n/2);

    for(auto &[a,b]:v1) cin >> a >> b;
    for(auto &[a,b]:v2) cin >> a >> b;
    cin >> a1 >> d1 >> a2 >> d2;

    vector<pair<ll,ll>> va1,va2;
    pair<ll,ll> p = {0,0};

    brute(va1,v1,p,0);
    brute(va2,v2,p,0);

    sort(va1.begin(),va1.end());
    sort(va2.begin(),va2.end());

    ll ans=0;
    ord_set<pair<ll,ll>> s;

    ll ins=0,rem=0,lx=0;

    for(ll i=va1.size()-1;i>=0;i--) {
        while(ins<va2.size() and va2[ins].ff+va1[i].ff<=a2) {
            s.insert({va2[ins].ss,lx++});
            ins++;
        }

        while(rem<ins and va1[i].ff+va2[rem].ff<a1) {
            auto it = s.lower_bound({va2[rem].ss,-1});
            s.erase(it);
            rem++;
        }

        ll qmaior = s.order_of_key({d2-va1[i].ss+1,-1});
        ll qmenor = s.order_of_key({d1-va1[i].ss,-1});

        ans += qmaior-qmenor;
    }


    cout << ans << '\n';
}