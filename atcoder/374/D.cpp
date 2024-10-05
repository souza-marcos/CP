#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


const double EPS = 1e-12;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

bool eq(double a, double b){
    return abs(a - b) <= EPS;
}

struct pt {
	double x, y;
	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	pt operator + (const pt& p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt& p) const { return pt(x-p.x, y-p.y); }
	pt operator * (double c) const { return pt(x*c, y*c); }
	pt operator / (double c) const { return pt(x/c, y/c); }


    bool operator<(const pt& other) const {
        if(!eq(x, other.x)) return x < other.x;
        if(!eq(y, other.y)) return y < other.y;
        return false;
    }

    bool operator==(const pt other){
        return (eq(x, other.x) and eq(y, other.y));
    }
};

double dot(pt p, pt q) { return p.x*q.x+p.y*q.y; }
double dist(pt p, pt q) { return sqrt(dot(p-q, p-q)); }

int n;
double v_emit, v_nonemit;
vector<pair<pt, pt>> arr;
const int MAXN = 7;
double memo[MAXN][2];

int main(){ _
    cout << fixed << setprecision(9);
    cin >> n >> v_nonemit >> v_emit;

    arr.resize(n);
    for(auto &[p, q]: arr){
        cin >> p.x >> p.y >> q.x >> q.y;
    }

    sort(arr.begin(), arr.end());

    double minv = 1e18;
    do{
        // Dist from 0, 0 to pt[0]
        pt last = {0, 0};
        memo[0][0] = dist(last, arr[0].first)/v_nonemit 
                   + dist(arr[0].first, arr[0].second)/v_emit;

        memo[0][1] = dist(last, arr[0].second)/v_nonemit 
                   + dist(arr[0].second, arr[0].first)/v_emit;
        for(int i = 1; i < n; i ++){  
            memo[i][0] = min(memo[i-1][0] + 
                        dist(arr[i-1].second, arr[i].first)/v_nonemit + 
                        dist(arr[i].first, arr[i].second)/v_emit,
                
                        memo[i-1][1] + 
                        dist(arr[i-1].first, arr[i].first)/v_nonemit +
                        dist(arr[i].first, arr[i].second)/v_emit
            );

            memo[i][1] = min(memo[i-1][0] + 
                        dist(arr[i-1].second, arr[i].second)/v_nonemit + 
                        dist(arr[i].second, arr[i].first)/v_emit,
                
                        memo[i-1][1] + 
                        dist(arr[i-1].first, arr[i].second)/v_nonemit +
                        dist(arr[i].second, arr[i].first)/v_emit
            );

        }
        minv = min(minv, memo[n-1][0]);
        minv = min(minv, memo[n-1][1]);
    }while(next_permutation(arr.begin(), arr.end()));

    cout << minv << endl;

    return 0;
} 
