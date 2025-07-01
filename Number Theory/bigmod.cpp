ll bigmod(ll a,ll n)
{
    ll rs = 1;
    while(n)
    {
        if(n%2 == 0){ n /= 2LL; a = a*a; a %= mod;}
        else{ n--; rs = rs * a; rs %= mod; }
    }
    return rs;
}
