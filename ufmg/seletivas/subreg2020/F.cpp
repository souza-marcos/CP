#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int games[2], points[2]; // left - right
int main(){ _
    string s; cin >> s;
    bool atual = 0; 
    for(int j = 0; j < sz(s); j++){
        char c = s[j];
        if(c == 'Q'){
            if(j + 1 == sz(s)){
                cout << games[0] << (games[0] == 2? " (winner) ": " ") << "- " << games[1] << (games[1] == 2? " (winner)":"") << endl;
                continue;
            }
            cout << games[0] << " (" << points[0] << (atual?"":"*") << ") - "
            <<  games[1] << " (" << points[1] << (atual?"*":"") << ")\n";
            continue;
        }
        
        points[(c == 'S'? atual: !atual)] ++;
        for(int i = 0; i < 2; i++){
            if((points[i] >= 10) or (points[i] >= 5 and points[i] >= points[!i] +2)){
                games[i] ++;
                points[0] = points[1] = 0;
                break;
            }
        }

        if(c == 'R') atual = !atual;
    }
    return 0;
} 
