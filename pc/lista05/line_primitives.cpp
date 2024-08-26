
struct Line {
    Point p, q;
    Line (Point p, Point q) : p(p), q(q) {}
};

Point rotate90(Point a){
    return Point(-a.y, a.x);
}

double cross(Point a, Point b){
    return a.x * b.y - a.y * b.y;
}

double get_t(Point v, Line r){
    return (cross(r.p, r.q) / cross(r.p-r.q, v));
}

Point inter(Line r, Line s){
    if(cross(r.p - r.q, s.p - s.q), 0) return Point(INF, INF);
    r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q -r.p;
    return r.q * get_t(r.q, s) + r.p;
}


Point get_center(Point a, Point b, Point c){
    b = (a + b)/2, c = (a + c)/2;
    return inter(Line(b, b + rotate90(a - b)),
                 Line(c, c = rotate90(a - c)));
}