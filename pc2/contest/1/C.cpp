#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){  _
    string s; cin >> s;
    int n = sz(s);

    vector<bool> ehprimo(n+1, 1);
    vector<int> primos;
    for(int i = 2; i <= n; i ++){
        if(ehprimo[i]){
            primos.push_back(i);
            for(int j = i*i; j <= n; j += i) ehprimo[j] = 0;
        }
    }
    int szo = primos.size();
    for(int i = 0; i < sz(primos); i ++){
        if(primos[i]*2 > n){
            szo = i;
            break;
        }
    }

    int need = n - (primos.size() - szo + 1);
    map<char, int> cnt;
    for(auto ch : s) cnt[ch] ++;
    vector<pair<int, char>> arr;
    
    bool ok = false;
    for(auto[fr, sn] : cnt) {
        arr.push_back({sn, fr});
        if(sn >= need) ok = true;
    }

    if(ok){
        sort(arr.begin(), arr.end());
        string res(n,' ');    
        string aux;
        for(auto [cn, ch] : arr){
            while(cn --) aux.push_back(ch);
        }
        int j = 0;
        for(int i =szo; i < sz(primos); i ++, j ++){
            res[primos[i]-1]=aux[j];
        }
        for(int i = 0; i < n; i ++){
            if(res[i]!=' ') continue;
            res[i] = aux[j];
            j ++;
        }
        cout << "YES\n";
        cout << res << endl;
    }else cout << "NO\n";
    return 0;
} 