
#define MAX_N 100
int memo[MAX_N];

int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (memo[n] != 0) return memo[n]; 

    memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return memo[n];
}
