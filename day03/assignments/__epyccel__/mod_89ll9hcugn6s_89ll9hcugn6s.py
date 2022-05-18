@types('float[:,:]','float','float','float[:,:]')
def pressure_poisson_numba(p, dx, dy, b):
    row, col=p.shape
    
    pn = np.empty_like(p)
    
    #$ omp for parallel
    for q in range(nit):
        pn = p.copy()
        for i in range(1,row-1):
            for j in range(1,col-1):
    
                    p[i, j] = (((pn[i+1, j] + pn[i-1, j]) * dy**2 + 
                                      (pn[i, j+1] + pn[i, j-1]) * dx**2) /
                                      (2 * (dx**2 + dy**2)) -
                                      dx**2 * dy**2 / (2 * (dx**2 + dy**2)) * 
                                      b[i,j])

    #$ omp end parallel
    p[:, -1] = p[:, -2] # dp/dx = 0 at x = 2
    p[0, :] = p[1, :]   # dp/dy = 0 at y = 0
    p[:, 0] = p[:, 1]   # dp/dx = 0 at x = 0
    p[-1, :] = 0        # p = 0 at y = 2
    
    return 0
