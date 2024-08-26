#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string origem, busca;

bool possible(vector<int>& v, int m){
    string aux = "";
    vector<int> auxv = v;

    sort(auxv.begin() + m, auxv.end());
    for(int i= m; i < v.size() ; i++){
        aux += origem[auxv[i] -1];
    }

    int last = 0;
    for(int i = 0; i < busca.size(); i++){
        int pos = aux.find_first_of(busca[i], last);
        if(pos == aux.npos) return false;
        last = pos + 1;
    }
    return true;    
}

int main(){ _
    cin >> origem >> busca;
    vector<int> v(origem.size());
    for(auto& el: v) cin >> el;

    int l = 0, r = origem.size();

    while (l + 1 < r)
    {
        int m = (l + r)/2;
        if(possible(v, m)) l = m;
        else r = m;
    }
    
    cout << l << endl;

    return 0;
} 
