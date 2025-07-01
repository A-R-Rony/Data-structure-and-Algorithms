bool prime[MAXN];
void sieve()
{
    v.pb(2);
    for(int i=3;i*i<MAXN;i+=2)
    {
        if(prime[i] == false){
             for(int j=i*i;j<MAXN;j+= 2*i)
                prime[j] = true;
        }
    }
    for(int i=3;i<MAXN;i+= 2) if(prime[i] == false) v.pb(i);
}
