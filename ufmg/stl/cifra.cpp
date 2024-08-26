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

int main(){ _
    string a, b = "";
    string cons = "bcdfghjklmnpqrstvxz";
    string vg = "aeiou";
    cin >> a;
    for(auto c:a){
        b += c;
        if(vg.find(c) != string::npos){
            continue;
        } 
        int min = 30; char cur = 'b';
        for(auto v: vg) {
            if(abs(c - v) < min){
                min = abs(c - v);
                cur = v;
            }
            else {
                break;
            }
        }
        b+=cur;
        int pos = cons.find(c);
        b+= ((pos == cons.length() - 1)?'z':cons[pos+1]);
    }
    cout << b << endl;

    return 0;
} 
