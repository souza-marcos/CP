#include <bits/stdc++.h>

using namespace std;

const int n = 10;
vector<tuple<int, int, int>> g(n);

void kruskal(){
    sort(g.begin(), g.end());
    
    int cost = 0;
    for(auto [w, a, b]: g){
        if(find(a) != find(b)){
            uni(a, b);
            cost += w;
        }
    }

}


