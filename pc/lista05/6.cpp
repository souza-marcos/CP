#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
const long double eps = 1e-9; 

#define sz(x) (int)x.size()

struct Point{
    int x, y;
    Point(int x=0, int y=0): x(x), y(y){}

    Point operator-(Point other){
        return Point(x - other.x, y -other.y);
    }
};

inline int cmp(double x, double y=0){
    return ((x <= y + eps)? (x + eps < y)? -1: 0: 1);
}

double cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

int ccw(Point a, Point b, Point c){
    return cmp(cross(b - a, c - b));
}

double area_poly(vector<Point>& v){
    double area = 0.0;
    if(sz(v) < 3) return area;
    for(int i = 0; i < sz(v); i++){
        area += cross(v[i], v[(i+1)%sz(v)]);
    }
    return area/2.0;
}

Point pts[5];
vector<int> order;
double max_area = 0;

bool is_in(int el){
    for(auto elv: order) if(elv == el) return true;
    return false;
}


void search_a(){
    if(sz(order) == 4){
        // Testar se eh convexo
        
        // for(auto el: order) cout << el  + 1<< " ";
        // cout << " | ";
        
        for(int i = 0; i < 4; i ++)
            if(ccw(pts[order[i]], pts[order[(i + 1)%4]], pts[order[(i+2)%4]]) == -1) 
                return;
        

        // Caso seja, calcular a area
        vector<Point> v(4);
        for(int i = 0; i < 4; i ++) v[i] = pts[order[i]];
        double area = area_poly(v);
        // cout << area << endl;

        max_area = max(max_area, area);
        return;
    }
    
    for(int i = 0; i < 5; i++){
        if(is_in(i)) continue;
        order.push_back(i);
        search_a();
        order.pop_back();
    }
}

int main(){ _

    while(1){
        bool ok = false;
        for(int i = 0; i < 5; i++){
            cin >> pts[i].x >> pts[i].y;
            if(pts[i].x or pts[i].y) ok = true;
        }
        if(!ok) break;

        order.clear();
        max_area = 0;
        search_a();
        cout << max_area << endl;
    }

    return 0;
} 
