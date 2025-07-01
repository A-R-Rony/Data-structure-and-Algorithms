eulvoid Euler_phi_logn()
{
    for (int i = 1; i < MAXN; i++)
        phi[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MAXN; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
