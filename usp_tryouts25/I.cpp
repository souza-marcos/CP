#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()


typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

ld angle(pt v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int32_t main() { _
    
    int n; cin >> n;
    vector<pt> points(n);
    vector<line> segs(n);
    for(auto&[a, b] : points) cin >> a >> b;
    
    pt toalha; cin >> toalha.x >> toalha.y;

    for(int i= 0; i < n; i ++){
        segs[i] = line(points[i], points[(i+1)%n]);
    }

    vector<vector<pair<int, ld>>> g(n);

    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){

            bool ok = true;
            if(j > i + 1){
                // testar consegue ver
                auto test = line(points[i], points[j]);
                for(int k = 0; k < n; k ++) {
                    if(k == j or k == (j-1+n)%n or k == i or k == (i-1+n)%n) continue;

                    if(interseg(segs[k], test)){
                        ok = false;
                        break;
                    }
                }
                for(int k = i+1; k < j; k ++) {
                    // if(k == j or k == (j-1+n)%n or k == i or k == (i-1+n)%n) continue;
                    if(dist(points[i],points[k])-eps>dist(points[i],points[j])) continue;
                    if(!ccw(points[i],points[k],points[j])){
                        if(i==0 and j==6) cout << k << '\n';
                        ok = false;
                        break;
                    }
                }
                for(int k = (j+1)%n;k!=i;k = (k+1)%n) {
                    if(dist(points[i],points[k])-eps>dist(points[i],points[j])) continue;

                    if(ccw(points[i],points[k],points[j])){
                        ok = false;
                        break;
                    }
                }
            }
            
            if(ok){
                g[i].push_back({j, dist(points[i], points[j])});
                g[j].push_back({i, dist(points[i], points[j])});
            }

        }
    }


    g.push_back({});
    for(int i = 0; i < n; i ++){
        bool ok = true;
        // testar consegue ver
        auto test = line(points[i], toalha);
        
        for(int k = 0; k < n; k ++) {
            if(k == i or k == (i-1+n)%n) continue;

            if(interseg(segs[k], test)){
                ok = false;
                break;
            }
        }
        
        if(ok){
            g[i].push_back({n, dist(points[i], toalha)});
            g[n].push_back({i, dist(points[i], toalha)});
        }
    }

    for(int i = 0; i <= n; i ++){
        cout << i << " => ";
        for(auto[ u, w] : g[i]) cout  << u << " ";
        cout << endl;
    }


    vector<ld> dist(n+1, INF);
    auto dijkstra = [&](int s, int t) -> ld {
        dist[s] = 0;
        priority_queue<pair<ld, int>> pq;
        pq.emplace(0, s);
    
        while (pq.size()) {
            auto [ndist, u] = pq.top(); pq.pop();
            if(u == t) return dist[t];
            if (-ndist > dist[u] + eps) continue;
    
            for (auto [idx, w] : g[u]) if (dist[idx] > dist[u] + w + eps) {
                dist[idx] = dist[u] + w;
                pq.emplace(-dist[idx], idx);
            }
        }   
        return dist[t];
    };   

    ld dist_t = dijkstra(0, n);
    ld res = 2 * dist_t;
    
    cout << fixed << setprecision(9);
    cout << res << endl;
}