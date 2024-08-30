#include<bits/stdc++.h>
using namespace std;
auto z_funcion(string s)
{   //0 1 2 3 4 5 6
    //a a b c a a b
    //0 1 0 0 3 1 0
    int n = s.size();
    vector<int>z(n, 0);
    int l = 0, r = 0;
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
    auto v = z_funcion(s);
    for (auto i : v) cout << i << " "; cout << endl;
}
int main()
{
    solve();
}
