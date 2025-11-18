#include <stdio.h>
#include <math.h>

#define XMAX 800
#define YMAX 600

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);
double srcd(struct point pt);
struct point addpoint(struct point p1, struct point p2);

int main(void){
    double dist;
    struct point pt = makepoint(3, 4);
    struct point pt1 = makepoint(1, 1);
    struct point res = addpoint(pt, pt1);
    dist = srcd(pt);
    printf("Tu punto (%d,%d) distancia al origen: %.2f\n", pt.x, pt.y, dist);
    printf("Suma (%d,%d) + (1,1) = (%d,%d)\n", pt.x, pt.y, res.x, res.y);
    return 0;
}

/* makepoint: crea un punto con las componentes x, y */
struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

/* srcd: devuelve la distancia del punto al origen */
double srcd(struct point pt){
    return sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
}

struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: regresa 1 si p está en r, 0 si no lo está */
int ptinrect(struct point p, struct rect r){
    return p.x >= r.pt1.x && p.x <= r.pt2.x
            && p.y >= r.pt1.y && p.y <= r.pt2.y;
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
/* canonrect: pone en forma canónica las coordenadas de un rectángulo */
struct rect caconrect(struct rect r){
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}