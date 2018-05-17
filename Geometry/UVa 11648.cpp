//Easy using direct formula (as below). 
//Else use divide and conquer technique by assuming some ratio m at which the dividing line divides the two non parallel lines
//and then compare the area, to find the appropriate value (the commented solution)

#include<bits/stdc++.h>
using namespace std;

int main () {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, tc = 1;
    scanf("%d", &n);
    while (n--) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &c, &d, &b);
        double e = sqrt((a * a + c * c) / 2.0);
        double m = (a - e) / (a - c);
        printf("Land #%d: %.6lf %.6lf\n", tc++, m * d, m * b);
    }
    return 0;
}

/*
#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;

int tc = 1, n;
double a, b, c, d, m;
const double PI = acos(-1);

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf", &a, &c, &d, &b);
        double s = (b + d + a - c) / 2.0, A = sqrt(s * (s - b) * (s - d) * (s - a + c));
        double sinalpha = 2 * A / (a - c) / d, sinbeta = 2 * A / b / (a - c), alpha = asin(sinalpha), beta = asin(
                sinbeta);
        if((a - c) * (a - c) + d * d < b * b)   alpha = PI - alpha;
        if((a - c) * (a - c) + b * b < d * d)   beta = PI - beta;
        A = (a + c) * d * sinalpha / 2.0;
        double l = 0, h = 1;
        while (true) {
            m = (l + h) / 2;
            double temp = (2 * a - m * d * cos(alpha) - m * b * cos(beta)) * m * d * sinalpha / 2.0;
            if (abs(2 * temp - A) < eps)    break;
            else if (2 * temp > A) h = m;
            else l = m;
        }
        printf("Land #%d: %.6lf %.6lf\n", tc++, m * d, m * b);
    }
    return 0;
}*/
