#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n;
vector<vector<double>> prob;

struct Node { 
    bitset<300> mask;
    int idx;
};
vector<pair<Node, Node>> partidas;
vector<double> prob_now;

// return mask that we are working
bitset<300> dp(int v){

    if(v < n) {
        bitset<300> mask(0); mask[v] = 1;
        // cout << __LINE__ << " " << v << " -> " << 1.0 << endl;
        return mask;
    }
    
    int idx_now = v - n;
    auto [left, right] = partidas[idx_now];
    // cout << v << "=+=" << left.idx << ", " << right.idx << endl;

    left.mask = dp(left.idx);       
    right.mask = dp(right.idx);

    // cout << left.mask[0] << " " << right.mask[0] << endl;

    if(left.mask[0] == 1 or right.mask[0] == 1){
        auto &cur_mask = (right.mask[0] ? left.mask : right.mask);
        double sum = 0.0;
        for(int i = 0; i < 300; i++){
            if(cur_mask[i] == 1){
                sum += prob_now[i] * prob[0][i];
            }
        }
        prob_now[0] = prob_now[0] * sum;
        // cout << __LINE__ << " " << v << " -> " << prob_now[0] << endl;
        return bitset<300>(1);
    }
    else {

        map<int, double> vals;
        double prob_come = 0.0;
        for(int i = 0; i < 300; i++){
            if(left.mask[i] == 0) continue;
            for(int j = 0; j < 300; j++){
                if(right.mask[j] == 0 or i == j) continue;
                prob_come += prob[i][j] * prob_now[j];
            }
            vals[i] = prob_come;
            // prob_now[i] *= prob_come;
            prob_come = 0.0;
        }

        for(int i = 0; i < 300; i++){
            if(right.mask[i] == 0) continue;
            for(int j = 0; j < 300; j++){
                if(left.mask[j] == 0 or i == j) continue;
                prob_come += prob[i][j] * prob_now[j];                    
            }
            vals[i] = prob_come;
            prob_come = 0.0;
        }

        bitset<300> res(0);
        for(auto [key, val] : vals){
            prob_now[key] *= val;
            res[key] = 1;
        }
        // cout << __LINE__ << " " << v << " => ";
        // for(auto [key, val] : vals) cout << "(" << key << ") - " << prob_now[key] << ", ";
        // cout << endl;

        return res;
    }
}

void solve(){
    prob.assign(n, vector<double>(n));
    prob_now.assign(n, 1.0);                // Prob inicial eh 1

    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> prob[i][j];
        }
    }

    // Cuidado na hora de acessar as posições
    partidas.assign(n-1,{});

    set<int> comp;
    for(auto& [fr, sn] : partidas){
        int a, b; cin >> a >> b;
        a --, b--;
        fr.idx = a, sn.idx = b;
        comp.insert(a), comp.insert(b);
    }
    int res = 0;
    for(int i = n; i < 2*n-1; i++) if(comp.count(i) == 0){
        res = i; break;
    }

    dp(res); // Necessario chamar para a partida mais acima
    cout << prob_now[0] << endl;

    // for(auto el : prob_now) cout << el << " ";
    // cout << endl;

    // int i = n + 1;
    // for(auto el : partidas) cout << i ++ << " " << el.first.idx << " " << el.second.idx << "\n";

}

int main(){_
    cout << setprecision(6) << fixed;
    while(cin >> n and n != 0) solve();

    return 0;
}