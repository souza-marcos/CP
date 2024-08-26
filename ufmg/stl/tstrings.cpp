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

bool isPoss(char a, char b, char c){
    if(a != b){
        if(c == a || c == b) return true;
        return false;
    }
    else{
       if(c == a && c == b) return true;
       return false;
    }
}

int main(){ _

    int n; cin >> n;
    string p[3];
    while(n-- > 0){
        
        bool pos = true;
        cin >> p[0] >> p[1] >> p[2];
        for(int i=0; i < p[0].size(); i++){
            if(!isPoss(p[0][i],p[1][i],p[2][i])){
                cout << "NO\n";
                pos = false;
                break;
            }
        }
        if(pos) cout << "YES\n"; 

    }


    return 0;
} 
