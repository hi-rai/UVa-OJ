//Suppose N = a^2 - b^2 = (a+b)(a-b) = xy, where a = (x+y)/2, and b = (x-y)/2.
//So, we need to factorise N, into x and y such that (x+y) and (x-y) is even. This means that x and y are both even or both odd.
//So, the number according to the case N is either multiple of four or odd respectively. Even non-multiples of 4 can't be expressed as such
//When N is a multiple of four, take x = N/2, y = 2
//When N is odd, take x = N, y = 1

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l, r, ans, a, b;
    char str[100];
    while (gets(str)) {
        if (sscanf(str, "%lld %lld", &l, &r) == 2) {
            while (l % 4 != 2) l++;
            ans = (r - l + 4) / 4;
            printf("%lld\n", ans);
        } else {
            if (l % 2) {
                a = (l + 1) / 2, b = (l - 1) / 2;
                if (l < 0) a *= -1, b *= -1;
                printf("%lld %lld\n", a, b);
            } else {
                if (l % 4) printf("Bachelor Number.\n");
                else {
                    a = (l + 4) / 4, b = (l - 4) / 4;
                    if (l < 0) a *= -1, b *= -1;
                    printf("%lld %lld\n", a, b);
                }
            }
        }
    }
    return 0;
}
