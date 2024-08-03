int MOD = 1e9 + 7;
int powr(int a , int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res *= a; res %= MOD;
        a *= a; a %= MOD;
        b = (b >> 1);
    }
    return res;
}
vector<int> fac , inv;
int n = 0;
void facm(int x)
{
    n = x;
    fac.resize(n + 1) , inv.resize(n + 1);
    fac[0] = 1;
    for (int i = 1 ; i <= n  ; i++)
    {
        fac[i] = (fac[i - 1] * i ) % MOD;
    }
}
void preinv()
{
    inv[n] = powr(fac[n] , MOD - 2);
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
}
int choose(int a , int b)
{
    if(a < b) return 0;
    return (((fac[a] * inv[b]) % MOD) * inv[a-b] )%MOD;
}
