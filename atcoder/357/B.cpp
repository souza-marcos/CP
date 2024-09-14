#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    string s; cin >> s;
    int l =0, u = 0;
    for(char c: s){
        if(c <= 'Z') u++;
        else l++;
    }
    if(u > l)
        for(char c: s) cout << (char)toupper(c) << "";
    else
        for(char c: s) cout << (char)tolower(c) << "";
    
    cout << endl;
    return 0;
} 
