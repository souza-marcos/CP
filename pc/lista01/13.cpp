#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int m;

void solve(){
    string s; getline(cin, s);

    int i = 0, j = 0;
    int qtd[128]; memset(qtd, 0, sizeof qtd);
    int cont = 0; // elementos diferentes
    int max_size = 0;

    while(j < s.size() and i < s.size()){
        if(qtd[s[j]] == 0) cont ++;
        qtd[s[j]] ++;
        
        while(cont > m){ // Movo left ate ser uma str possivel
            if(qtd[s[i]]==1) cont --;
            qtd[s[i]]--;
            i++;
        }
        max_size = max(max_size, j - i + 1);
        j++;
    } 
    cout << max_size << endl;
}


int main(){

    while((cin >> m).get() and m != 0) { solve();}  

    return 0;
}