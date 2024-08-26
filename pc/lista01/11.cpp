#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int t, p;
int ac[101], wa[101], tempo[101];
vector<vector<int>> team_ac;

void solve(){
    team_ac.assign(11, {});

    for(int i = 0; i < t; i ++){
        ac[i] = 0, wa[i] = 0, tempo[i] = 0;
        for(int j = 0; j < p; j++){
            int a, s; string str;
            cin >> str;
            stringstream ss(str);
            getline(ss, str, '/');
            a = stoi(str);
            getline(ss, str, '/');
            
            if (str != "-") s = stoi(str);
            else s = -1;

            if(s == -1) continue;
            ac[i] ++;
            wa[i] += a-1;
            tempo[i] += s;
            
        }
        team_ac[ac[i]].push_back(i);
    }
    
    int lb = 1, up = 4000;
    bool sai = false;
    for(int i = 0; i < 11; i++){
        sort(team_ac[i].begin(), team_ac[i].end(), [](int l, int r){
            return (tempo[l] + wa[l] * 20) <= (tempo[r] + wa[r] * 20);
        });
        for(int j = 0; j < team_ac[i].size() - 1; j++) {
 
            int l = team_ac[i][j], r = team_ac[i][j + 1];
            if(wa[l] == wa[r]) continue;

            int ep = (tempo[r]-tempo[l])/(wa[l] - wa[r]);
            if(ep > 20 or (ep == 20 and (tempo[r]-tempo[l])%(wa[l] - wa[r]) != 0)){
                up = min(up, (tempo[r]-tempo[l])%(wa[l] - wa[r])!=0?ep:ep-1);
            }
            else if(ep < 20) lb = max(lb, ep + 1);
            else lb = up = 20, sai = true;
        } 
        if(sai) break;   
    }

    cout << lb << " ";
    if(up != 4000) cout << up << endl;
    else cout << "*" << endl;
}

int main(){_
    while(cin >> t >> p and t != 0) solve();
    return 0;
}