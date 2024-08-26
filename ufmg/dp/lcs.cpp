#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
string s, t;

int memo[3010][3010];
string res;
void recupera(int i, int j){
    if(i >= s.size() or j >= t.size()) return;
    if(s[i]==t[j]){
        res.push_back(s[i]);
        return recupera(i + 1, j + 1);
    }

    if(memo[i + 1][j] > memo[i][j + 1]) return recupera(i + 1, j);
    return recupera(i, j + 1);
}

void lcs_size(){

    for(int i = s.size() -1; i >= 0; i --){
        for(int j = t.size() -1; j >= 0; j--){
            if(s[i] == t[j]) memo[i][j] = 1 + memo[i + 1][j + 1];
            else memo[i][j] = max(memo[i + 1][j], memo[i][j + 1]); 
        }
    }

    recupera(0,0);
    cout << res << endl;
    // cout << memo[0][0] << endl;

    // for(int i = 0; i < s.size(); i ++){
    //     for(int j = 0; j < t.size(); j++){
    //         cout << memo[i][j] << " ";
    //     }cout << endl;
    // }

    // string res;
    // int i = 0, j = 0;
    // while(i < s.size() and j < t.size()){                   // Enquanto não estivermos no caso base
    //     if(s[i] == t[j]) { res.push_back(s[i]); i++, j++; }
    //     else if(memo[i + 1][j] >= memo[i][j + 1]) i++;
    //     else j++;
    // }
    // cout << res << endl;

}

int main(){ _
    cin >> s >> t;
    lcs_size();
    return 0;
} 
