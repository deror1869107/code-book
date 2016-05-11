int a[MAX] = {0}, t[MAX] = {0};
int N;

inline int lower_bit(int n)
{
    return n & (-n);
}

int sum(int n)
{
    int s = 0;
    while(n > 0){
        s += t[n];
        n -= lower_bit(n);
    }
    return s;
}

void add(int n, int d)
{
    while(n <= N){
        t[n] += d;
        n += lower_bit(n);
    }
}

int query(int a, int b)
{
    return sum(b) - sum(a - 1);
}
