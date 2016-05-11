long long int pow(long long int a, long long  int u, long long int n)
{
    long long int res = 1;
    while(u){
        if(u & 1){
            res = res * a % n;
        }
        a = a * a % n;
        u >>= 1;
    }
    return res;
}

bool isprime(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    int u = n - 1, t = 0;
    while (u % 2 == 0) {u >>= 1; t++;}
    int sprp[3] = {2, 7, 61};
    for (int k=0; k<3; ++k)
    {
        int a = sprp[k] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        long long x = pow(a, u, n);
        if (x == 1 || x == n-1) continue;
        for (int i = 0; i < t-1; i++)
        {
            x = (long long int)x * x % n;
            if (x == 1) return false;
            if (x == n-1) break;
        }
        if (x == n-1) continue;
        return false;
    }
    return true;
}
