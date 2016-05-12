typedef unsigned long long int ULL;

ULL pow(ULL a, ULL x, ULL n) // a ^ x % n
{
	ULL res = 1;
	while(x) {
		if(x & 1) res = res * a % n;
		a = a * a % n;
		x >>= 1;
	}
	return res;
}