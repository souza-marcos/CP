#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    
    string s; cin >> s;
    vector<pair<int, int>> arr;
    char last = '1', cnt = 1;
    for(int i = 1; i < sz(s); i ++){
        if(s[i] == last) cnt ++;
        else arr.push_back({last-'0',cnt}), cnt = 1, last = s[i];
    }
    arr.push_back({last-'0', cnt});

    vector<pair<int, int>> res;
    int x = sz(s);
    for(auto [token, val] : arr){
        if(token == 0){ x-=val; continue;}
        if(val > 1) 
            res.push_back({+1, x}),
            res.push_back({-1, x-val});
        else res.push_back({+1, x-1});
        x -= val;
    }
    cout << sz(res) << endl;
    for(auto [signal, val] : res){
        cout << (signal > 0? '+' : '-') << "2^" << val << endl;
    }
} 
