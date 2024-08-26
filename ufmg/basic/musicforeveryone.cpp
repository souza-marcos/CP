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

    int main(){ _
        int n, m, cur_song; cin >> n >> m >> cur_song; cur_song --;

        vector<tuple<int,int, int>> users(n); // hate, id, love
        vector<bool> listen(m, false);
        
        int user = 0;
        for(auto& [hate, id, love]: users){
            cin >> love >> hate; 
            id = user++;
            love --; hate --;
        }

        sort(users.begin(), users.end());

        int cont = 0;
        while(true){
            auto it = lower_bound(users.begin(), users.end(), make_tuple(cur_song, 0, 0));

            if(it == users.end()) break;

            auto [hate, id, love] = (*it);
            if(hate != cur_song) break;

            // cout << cur_song + 1 << " - " << hate + 1 << " " << id << " " << love + 1<< endl;
            

            if(listen[love]){
                cont = -1; break;
            }
            listen[love] = true;
            cont += 1;
            cur_song = love;
        }

        cout << cont << endl;
        return 0;
    } 
