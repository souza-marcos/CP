#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll


int32_t main(){ _
    int n = 8;
    vector<set<int>> res(n+1);
    for(int l = 1;l <= n; l ++){
        vector<int> perm(l);
        iota(perm.begin(), perm.end(), 0);
        do {
            int cnt = 0;
            for(int i = 0; i < l; i ++){
                for(int j = i+1; j < l; j ++){
                    set<int> st; st.insert(-1);
                    for(int k = i; k <= j; k ++){
                        auto it = *st.rbegin();
                        if(it > perm[k]) {
                            cnt ++;
                            break;
                        }
                        st.insert(perm[k]);       
                    }
                }
            }
            for(auto el : perm) cout << el << " ";
            cout << " : " << cnt << endl;
            
            res[l].insert(cnt);

        } while(next_permutation(perm.begin(), perm.end()));
    }

    for(int i=0; i <= n; i++ ){
        cout << sz(res[i]) << " : ";
        for(int el : res[i]) cout << el << " ";
        cout << endl;   
    }
} 

/*
 
g++ a.cpp -o main -Wall -fsanitize=address -g 
 
Lembre de mim:
 
em hipótese alguma veja os standings. Veja apenas o Dashboard.
ler a questão
entender o problema
ver os casos de teste
entender os casos de teste
entender o algoritmo naive para resolver o problema
 
(!) sempre tem uma solução (um setter que fez)
(!) Tudo que voce sabe é o suficiente para resolver
 
testar a ideia nos casos de teste e pensar em contra exemplos e casos de borda
 
(!) implementar com calma.
 
-> Se tu está garrado, sem nenhuma ideia, tente fazer chutes.
-> Faça uma BFS.
*/