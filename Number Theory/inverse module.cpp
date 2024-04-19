// [mod inverse of factorial in O(N)]
factinv[MAXN-1]=bigmod(fact[MAXN-1],mod-2);// inverse mod of maximum factorial 
//For MAXN=200010,
factinv[MAXN-1]= 758835755
for(ll i= MAXN - 2; i >= 0; i--){
factinv[i]=factinv[i + 1]*(i+ 1);
   factinv[i] %= mod;
}
// logic behind this is:1/n!=(n+1)/(n+1)! 
   void ModInverse()// approach:2 
    {
    inv[0] = inv[1] = 1;
    factinv[0] = factinv[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
   inv[i]=inv[mod%i]*(mod-mod/i) % mod;
   factinv[i]=(factinv[i-1]*inv[i])%mod;
    }
//logic: x%i=x- (x/i)*i
// x%i=-(x/i)*i ,mod by x
// i^(-1)= -(x/i)*(x%i)^(-1)
