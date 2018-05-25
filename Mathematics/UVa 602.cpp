//Take care of every detail. Keep in mind that Gregorian Rule was not followed before 1752.
//Check for test cases on uDebug (there possibly one of the days in one of the answers is wrong).
//Also note that this code can be made more efficient

#include<bits/stdc++.h>
using namespace std;

string mon[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int daysRemMonth(int y, int m, int d) {
    if(m == 2) {
        if(y % 400 == 0 || y < 1752 && y % 100 == 0)    return 29 - d;
        if(y % 100 == 0)    return 28 - d;
        if(y % 4)   return 28 - d;
        return 29 - d;
    }
    else if(m % 2 && m < 8|| m > 7 & m % 2 == 0)  return 31 - d;
    else return 30 - d;
}

int daysRemYear(int y, int m) {
    int ans = 0;
    while (m < 13) ans += daysRemMonth(y, m++, 1) + 1;
    return ans;
}

int calcDiff(int y1, int m1, int d1, int y2, int m2, int d2) {
    if(y2 == y1) {
        if(m1 == m2) return daysRemMonth(y2, m2, d2) - daysRemMonth(y1, m1, d1);
        else return daysRemYear(y2, m2 + 1) + daysRemMonth(y2, m2, d2) - daysRemYear(y1, m1 + 1) - daysRemMonth(y1, m1, d1);
    } else {
        int ans = daysRemYear(y2, m2 + 1) + daysRemMonth(y2, m2, d2);
        while((++y2) < y1) ans += daysRemYear(y2, 1);
        ans += daysRemYear(y1, 1) - daysRemYear(y1, m1 + 1) - daysRemMonth(y1, m1, d1);
        return ans;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, d, y, td, tm, ty, sw, tot, ans;
    while (cin >> m >> d >> y, m || d || y) {
        int inv;
        if(m <= 0 || m > 12)    inv = 1;
        else if (m == 2) {
            if (y % 400 == 0 || y < 1752 && y % 100 == 0) inv = d > 29;
            else if (y % 100 == 0) inv = d > 28;
            else if (y % 4 == 0) inv = d > 29;
            else inv = d > 28;
        } else if (m % 2 && m < 8 || m > 7 & m % 2 == 0) inv = d > 31;
        else inv = d > 30;
        if (y == 1752 && m == 9 && d > 2 && d < 14) inv = 1;
        if (inv) {
            cout << m << "/" << d << "/" << y << " is an invalid date.\n";
            continue;
        }
        ty = 2018, td = 25, tm = 5, sw = 0;
        if (y > ty) swap(ty, y), swap(td, d), swap(tm, m), sw = 1;
        else if (y == ty && m > tm) swap(tm, m), swap(td, d), sw = 1;
        else if (y == ty && m == tm && d > td) swap(td, d), sw = 1;
        tot = calcDiff(ty, tm, td, y, m, d);
        if (sw) {
            ans = (5 + tot) % 7;
            cout << mon[tm - 1] << " " << td << ", " << ty << " is a " << day[ans] << endl;
        } else {
            if (y < 1752) tot -= 11;
            else if (y == 1752 && m < 9) tot -= 11;
            else if (y == 1752 && m == 9 && d < 14) tot -= 11;
            tot %= 7;
            ans = 5 - tot;
            if (ans < 0) ans += 7;
            cout << mon[m - 1] << " " << d << ", " << y << " is a " << day[ans] << endl;
        }
    }
    return 0;
}
