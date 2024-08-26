#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

map<string, int> peca;

int main(){_

    string dec_to_br[10] = {
        ".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..." 
    };
    for(int i = 0; i < 10; i++) peca[dec_to_br[i]] = i;

    int n;
    while(cin >> n && n > 0){
        string s; cin >> s;
        if(s == "S"){
            cin >> s;
            for(int i = 0; i < 3; i++){
                int step = i;
                for(auto el: s){
                    string cur = dec_to_br[el - '0'];
                    cout << cur[step * 2] << cur[step * 2 + 1] << " ";
                }cout << endl;  
            }
        }else{
            vector<string> in(n);
            string temp;
            for(int i = 0; i < 3; i++){
                for(auto& el: in){
                    cin >> temp;
                    el.append(temp);
                }
            }
            for(auto el: in) cout << peca[el];
            cout << endl;
        }
    }

    return 0;
}