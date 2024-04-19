#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void basicIO() {
    __int128 a,b,c,d;
    a = read();
    b = read();
    c = read();
    d = read();
    if(a*d == c*b){
        cout<<"Equal\n";
    }
    else cout<<"Not Equal\n";
}

int main() {
    int n;
    cin >> n;
    while(n--)
     basicIO();
    // Your cpp code here
    return 0;
}
