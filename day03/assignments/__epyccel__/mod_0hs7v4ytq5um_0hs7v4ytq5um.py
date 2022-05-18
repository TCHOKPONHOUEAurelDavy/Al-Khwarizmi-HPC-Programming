@types('int','float[:,:]', 'float[:,:]','float','int','int','float','float','float[:,:]','int','float')
def cavity_flow_pure(nt, u, v, dt, nx, ny, dx, dy, p, rho, nu):
    import numpy as np
    un = np.empty_like(u)
    vn = np.empty_like(v)
    c= np.zeros((ny, nx))
    pn = np.empty_like(p)
    row, col=p.shape
     
    #omp parallel
    #$ omp for
    for n in range(nt):
        un[:,:] = u[:,:]
        vn[:,:] = v[:,:]
        
        c[1:-1, 1:-1] = (rho * (1 / dt * 
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / 
                     (2 * dx) + (v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy)) -
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / (2 * dx))**2 -
                      2 * ((u[2:, 1:-1] - u[0:-2, 1:-1]) / (2 * dy) *
                           (v[1:-1, 2:] - v[1:-1, 0:-2]) / (2 * dx))-
                          ((v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy))**2))
        
        b=c

        
       
        for q in range(nt):
            pn[: , :] = p[: , :]
            for i in range(1,row-1):
                for j in range(1,col-1):

                        p[i, j] = (((pn[i+1, j] + pn[i-1, j]) * dy**2 + 
                                          (pn[i, j+1] + pn[i, j-1]) * dx**2) /
                                          (2 * (dx**2 + dy**2)) -
                                          dx**2 * dy**2 / (2 * (dx**2 + dy**2)) * 
                                          b[i,j])


        p[:, -1] = p[:, -2] # dp/dx = 0 at x = 2
        p[0, :] = p[1, :]   # dp/dy = 0 at y = 0
        p[:, 0] = p[:, 1]   # dp/dx = 0 at x = 0
        p[-1, :] = 0        # p = 0 at y = 2
        
        
        u[1:-1, 1:-1] = (un[1:-1, 1:-1]-
                         un[1:-1, 1:-1] * dt / dx *
                        (un[1:-1, 1:-1] - un[1:-1, 0:-2]) -
                         vn[1:-1, 1:-1] * dt / dy *
                        (un[1:-1, 1:-1] - un[0:-2, 1:-1]) -
                         dt / (2 * rho * dx) * (p[1:-1, 2:] - p[1:-1, 0:-2]) +
                         nu * (dt / dx**2 *
                        (un[1:-1, 2:] - 2 * un[1:-1, 1:-1] + un[1:-1, 0:-2]) +
                         dt / dy**2 *
                        (un[2:, 1:-1] - 2 * un[1:-1, 1:-1] + un[0:-2, 1:-1])))

        v[1:-1,1:-1] = (vn[1:-1, 1:-1] -
                        un[1:-1, 1:-1] * dt / dx *
                       (vn[1:-1, 1:-1] - vn[1:-1, 0:-2]) -
                        vn[1:-1, 1:-1] * dt / dy *
                       (vn[1:-1, 1:-1] - vn[0:-2, 1:-1]) -
                        dt / (2 * rho * dy) * (p[2:, 1:-1] - p[0:-2, 1:-1]) +
                        nu * (dt / dx**2 *
                       (vn[1:-1, 2:] - 2 * vn[1:-1, 1:-1] + vn[1:-1, 0:-2]) +
                        dt / dy**2 *
                       (vn[2:, 1:-1] - 2 * vn[1:-1, 1:-1] + vn[0:-2, 1:-1])))
        #$ omp sections nowait
        #$ omp section
        u[0, :]  = 0
        u[:, 0]  = 0
        u[:, -1] = 0
        u[-1, :] = 1  
        #$ omp end section
        #$ omp section
        v[0, :]  = 0
        v[-1, :] = 0
        v[:, 0]  = 0
        v[:, -1] = 0
        #$ omp end section
        #$ omp end sections
        
    #$ omp end for
        
    #$ omp end parallel
        
    return u, v, p
