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

int conv(string s){
        if(s == "paper") return 0;
        if(s == "rock") return 1;
        return 2;
}

int main(){ _
    int n[3];
    string temp[3];

    for(int i = 0; i< 3; i++){
            cin >> temp[i];
            n[i] = conv(temp[i]);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(n[i] == j and n[(i + 1)%3] == ((j + 1)%3) and n[(i + 2)%3] == ((j + 1)%3)) { cout << "FMS"[i] << endl; return 0; }
        }
    }

    cout << "?"<< endl;
    return 0;
}