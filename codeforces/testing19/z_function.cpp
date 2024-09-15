#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define sz(x) (int)x.size()

// Função Z (Definição): Basicamente retorna o tamanho da maior
// substring que começa no indice i que é igual
// a um prefixo da string s;
// Maior prefixo do sufixo que é igual a um prefixo de s


vector<int> naive_zfunction(string& s){
    vector<int> z(sz(s));
    for(int i = 1; i < sz(s); i ++){
        while(i + z[i] < sz(s) and s[z[i]] == s[i + z[i]])
            z[i] ++;
    }
    return z;
}

vector<int> zfunction(string& s){
    vector<int> z(sz(s));
    int l = 0, r = 0;
    for(int i = 1; i < sz(s); i ++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < sz(s) and s[z[i]] == s[i + z[i]]) 
            z[i] ++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

int main(){
    string s; cin >> s;
    auto res = naive_zfunction(s);
    for(auto el: res) cout << el << " ";
    cout << endl;

    res = zfunction(s);
    for(auto el: res) cout << el << " ";    
    cout << endl;
}