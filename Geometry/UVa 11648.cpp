//Easy using direct formula (as below). 
//Else use divide and conquer technique by assuming some ratio m at which the dividing line divides the two non parallel lines

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
