int climbStairs(int n) {
	int a[n+1];
	a[1] = 1;
	a[2] = 2;
	int i = 3;
	while(i<=n) {
		a[i] = a[i-1] + a[i-2];
		i++;
	}
	return a[n];
}