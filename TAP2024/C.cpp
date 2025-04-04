#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct pt3 {
    double x,y,z;
}

typedef double ld;
const ld DINF = 1e18;
const ld eps = 1e-9;
 
#define sq(x) ((x)*(x))
 
bool eq(ld a, ld b) {
        return abs(a - b) <= eps;
}
 
struct pt3 { // ponto
        ld x, y, z;
        pt3(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) {}
        bool operator < (const pt3 p) const {
                if (!eq(x, p.x)) return x < p.x;
                if (!eq(y, p.y)) return y < p.y;
                if (!eq(z, p.z)) return z < p.z;
                return 0;
        }
        bool operator == (const pt3 p) const {
                return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
        }
        pt3 operator + (const pt3 p) const { return pt3(x+p.x, y+p.y, z+p.z); }
        pt3 operator - (const pt3 p) const { return pt3(x-p.x, y-p.y, z-p.z); }
        pt3 operator * (const ld c) const { return pt3(x*c  , y*c  , z*c  ); }
        pt3 operator / (const ld c) const { return pt3(x/c  , y/c  , z/c  ); }
        ld operator * (const pt3 p) const { return x*p.x + y*p.y + z*p.z; }
        pt3 operator ^ (const pt3 p) const { return pt3(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }
        friend istream& operator >> (istream& in, pt3& p) {
                return in >> p.x >> p.y >> p.z;
        }
};
 
struct line3 { // reta
        pt3 p, q;
        line3() {}
        line3(pt3 p_, pt3 q_) : p(p_), q(q_) {}
        friend istream& operator >> (istream& in, line3& r) {
                return in >> r.p >> r.q;
        }
};
 
struct plane { // plano
        array<pt3, 3> p;  // pontos que definem o plano
        array<ld, 4> eq; // equacao do plano
        plane() {}
        plane(pt3 p_, pt3 q_, pt3 r_) : p({p_, q_, r_}) { build(); }
 
        friend istream& operator >> (istream& in, plane& P) {
                return in >> P.p[0] >> P.p[1] >> P.p[2];
                P.build();
        }
        void build() {
                pt3 dir = (p[1] - p[0]) ^ (p[2] - p[0]);
                eq = {dir.x, dir.y, dir.z, dir*p[0]*(-1)};
        }
};

enum RETCODE {BOTH, ONE, PARAL, CONCOR};
pair<RETCODE, pt3> intersect(plane P, line3 r) {
    ld d1 = sdist(r.p, P);
    ld d2 = sdist(r.q, P);
    if (eq(d1, 0) and eq(d2, 0))
                return pair(BOTH, r.p);
    if (eq(d1, 0))
                return pair(ONE, r.p);
    if (eq(d2, 0))
                return pair(ONE, r.q);
    if ((d1 > 0 and d2 > 0) or (d1 < 0 and d2 < 0)) {
        if (eq(d1-d2, 0)) return pair(PARAL, pt3());
        return pair(CONCOR, pt3());
    }
    ld frac = d1 / (d1 - d2);
    pt3 res = r.p + ((r.q - r.p) * frac);
    return pair(ONE, res);
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
// se o seg de r intersecta o seg de s
bool interseg(line r, line s) {
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int32_t main() { _
    plane pl(pt3(0,0),pt3(0,1),pt3(1,0));

    int n;
    cin >> n;
    pt3 p, sun;
    cin >> p.x >> p.y >> p.z;
    cin >> sun.x >> sun.y >> sun.z;
    
    vector<pair<double,double>> v(n);
    for(auto &i:v) cin >> i.x >> i.ss;


    line3 ll(sun,p);
    auto it = intersect(pl,ll);
    // pt proj = 
    for(int i=0;i<n;i++) {
    }
}