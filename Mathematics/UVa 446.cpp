//An easy problem

#include<bits/stdc++.h>
using namespace std;

void toBin(int x, char s[]) {
    memset(s, '0', 15);
    int ind = 11;
    while (x) {
        if (x & 1) s[ind] = '1';
        x /= 2, ind--;
    }
    s[12] = '\0';
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, b, add, TC;
    scanf("%d", &TC);
    char A[15], B[15], c;
    while (TC--) {
        scanf("%s %c %s", A, &c, B);
        sscanf(A, "%x", &a);
        sscanf(B, "%x", &b);
        if(c == '+') add = 1;
        else add = 0;
        toBin(a, A), toBin(b, B);
        printf("0%s %c 0%s = ", A, add ? '+' : '-', B);
        if (add) printf("%d\n", a + b);
        else printf("%d\n", a - b);
    }
    return 0;
}
