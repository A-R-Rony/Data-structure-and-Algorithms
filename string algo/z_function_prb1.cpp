#include<bits/stdc++.h>
using namespace std;
#define en "\n"
auto z_funcion(string s)
{   //0 1 2 3 4 5 6
    //a a b c a a b
    //0 1 0 0 3 1 0
    int n = s.size();
    vector<int>z(n, 0);
    int l = 0, r = 0;
    z[0] = n;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve()
{
    string s;
    cin >> s;
    auto z = z_funcion(s);
    int n = s.size();
    // for (int i = 0; i < n; i++) cout << z[i] << " "; cout << en;

    vector<bool> ok(n + 1, 0);
    int an = 0;
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] + i == s.size()) {
            ok[z[i]] = 1;
            an++;
        }
    }
    cout << an << en;
    vector<int>cn(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        cn[z[i]]++;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        cn[i] += cn[i + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (ok[i] == 1) {
            cout << i << " " << cn[i] << en;
        }
    }


}
int main()
{
    solve();
}
// https://codeforces.com/contest/432/problem/D
