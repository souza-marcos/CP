#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MAXC = 1000000;
const int64 LCG_MOD = 1000000007LL;
const int64 OUT_MOD = 998244353LL;

#define int int64

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int Q1;
    int64 Q2;
    if(!(cin >> n >> Q1 >> Q2)) return 0;
    deque<pair<int,int64>> dq; // (color, len)
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];

    // build initial runs
    for(int i=0;i<n;){
        int j=i;
        while(j<n && A[j]==A[i]) ++j;
        dq.emplace_back(A[i], j - i);
        i = j;
    }

    vector<int64> cnt(MAXC+5, 0);
    int distinct = 0;
    int64 T = 0;

    // initialize counts from initial runs
    for(auto &p: dq){
        cnt[p.first] += p.second;
        T += p.second;
    }

    // build initial heap and distinct correctly (BUG fix)
    priority_queue<pair<int64,int>> pq; // (count, color)
    for(int c=1;c<=MAXC;c++){
        if(cnt[c]>0){
            distinct++;
            pq.emplace(cnt[c], c);
        }
    }

    auto inc_cnt = [&](int c, int64 delta){
        int64 old = cnt[c];
        int64 now = old + delta;
        if(old==0 && now>0) ++distinct;
        if(old>0 && now==0) --distinct;
        cnt[c] = now;
    };

    auto get_max = [&]()->int64{
        while(!pq.empty()){
            auto top = pq.top();
            int color = top.second;
            int64 val = top.first;
            if(cnt[color] != val) pq.pop();
            else return val;
        }
        return 0;
    };

    auto make_answer = [&]()->int64{
        if(distinct < 3) return 0;
        int64 M = get_max();
        int64 R = T - M;
        if(M < R) return T;
        else return 2*R - 1;
    };

    vector<int64> answersQ1;
    answersQ1.reserve(Q1);

    auto push_left = [&](int color, int64 k){
        if(!dq.empty() && dq.front().first == color){
            dq.front().second += k;
        } else {
            dq.emplace_front(color, k);
        }
        inc_cnt(color, k);
        pq.emplace(cnt[color], color);
        T += k;
    };
    auto push_right = [&](int color, int64 k){
        if(!dq.empty() && dq.back().first == color){
            dq.back().second += k;
        } else {
            dq.emplace_back(color, k);
        }
        inc_cnt(color, k);
        pq.emplace(cnt[color], color);
        T += k;
    };
    auto pop_left = [&](int64 k){
        while(k>0 && !dq.empty()){
            auto &fr = dq.front();
            int color = fr.first;
            int64 take = min(k, fr.second);
            fr.second -= take;
            inc_cnt(color, -take);
            pq.emplace(cnt[color], color);
            T -= take;
            k -= take;
            if(fr.second == 0) dq.pop_front();
        }
    };
    auto pop_right = [&](int64 k){
        while(k>0 && !dq.empty()){
            auto &bk = dq.back();
            int color = bk.first;
            int64 take = min(k, bk.second);
            bk.second -= take;
            inc_cnt(color, -take);
            pq.emplace(cnt[color], color);
            T -= take;
            k -= take;
            if(bk.second == 0) dq.pop_back();
        }
    };

    // process Q1 explicit ops
    for(int i=0;i<Q1;i++){
        int t;
        cin >> t;
        if(t==1 || t==2){
            int64 k; int c;
            cin >> k >> c;
            if(t==1) push_left(c, k);
            else push_right(c, k);
        } else {
            int64 k; cin >> k;
            if(t==3) pop_left(k);
            else pop_right(k);
        }
        answersQ1.push_back(make_answer());
    }

    // read LCG spec
    int64 a,d; cin >> a >> d;
    int64 X0; cin >> X0;
    int p; cin >> p;
    vector<int> B(p);
    for(int i=0;i<p;i++) cin >> B[i];

    // output Q1 answers first line
    for(size_t i=0;i<answersQ1.size();++i){
        cout << answersQ1[i] << (i+1==answersQ1.size()?'\n':' ');
    }
    if(answersQ1.empty()) cout << '\n';

    // process Q2 generator
    int64 cur = X0;
    auto nextX = [&]()->int64{
        int64 ret = cur;
        cur = ( (a * cur) + d ) % LCG_MOD;
        return ret;
    };

    uint64_t xorsum = 0;
    for(int64 i=1;i<=Q2;i++){
        int t = (int)(nextX() % 4) + 1;
        if(t==1 || t==2){
            int64 k = nextX() + 1;
            int idx = (int)(nextX() % p);
            int c = B[idx];
            if(t==1) push_left(c, k);
            else push_right(c, k);
        } else {
            int64 sz = T;
            int64 k = 0;
            if(sz>0) k = nextX() % (sz + 1);
            else k = 0;
            if(t==3) pop_left(k);
            else pop_right(k);
        }
        int64 res = make_answer();
        int64 term = ( ( (i % OUT_MOD) * (res % OUT_MOD) ) % OUT_MOD );
        xorsum ^= (uint64_t)term;
    }

    cout << xorsum << "\n";
    return 0;
}
