//An easy problem

#include<bits/stdc++.h>
using namespace std;

int d;
char s[50];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%s", s), s[0] != '-') {
        if (strlen(s) > 2 && s[1] == 'x') {
            sscanf(s, "%x", &d);
            printf("%d\n", d);
        } else {
            sscanf(s, "%d", &d);
            printf("0x%X\n", d);
        }
    }
    return 0;
}
