
from pyccel.decorators import types

@types('float[:,:]','float','float','float[:,:]','float[:,:]','float','float')
def build_up_b_numba(b, rho, dt, u, v, dx, dy):
    
    #$ omp parallel 
    b[1:-1, 1:-1] = (rho * (1 / dt * 
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / 
                     (2 * dx) + (v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy)) -
                    ((u[1:-1, 2:] - u[1:-1, 0:-2]) / (2 * dx))**2 -
                      2 * ((u[2:, 1:-1] - u[0:-2, 1:-1]) / (2 * dy) *
                           (v[1:-1, 2:] - v[1:-1, 0:-2]) / (2 * dx))-
                          ((v[2:, 1:-1] - v[0:-2, 1:-1]) / (2 * dy))**2))
    #$omp end parallel
    return 0


@types('float[:,:]','float','float','float[:,:]','int','int')
def pressure_poisson_numba(p, dx, dy, b, nit , nt):
    import numpy as np
    row, col=p.shape
    pn = np.empty_like(p)
    
    #$ omp parallel
    #$ omp for
    for q in range(nit):
        pn[:,:] = p[:,:]
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
    
    #$ omp end parallel
    return 0
        
@types('float[:,:]', 'float[:,:]','float','int','int','float','float','float[:,:]','float','float','int','int')
def cavity_flow_numba(u, v, dt, nx, ny, dx, dy, p, rho, nu, nit, nt):
    import numpy as np
    
    un = np.empty_like(u)
    vn = np.empty_like(v)
    b = np.empty((ny, nx),dtype=np.double)
     
    #$ omp parallel
    #$ omp for
    for n in range(nt):
        un[:,:]= u[:,:]
        vn[:,:]= v[:,:]
        
        build_up_b_numba(b, rho, dt, u, v, dx, dy)
        pressure_poisson_numba(p, dx, dy, b, nit, nt)
        
        
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

    #$ omp section
    u[0, :]  = 0
    u[:, 0]  = 0
    u[:, -1] = 0
    u[-1, :] = 1  
    v[0, :]  = 0
    v[-1, :] = 0
    v[:, 0]  = 0
    v[:, -1] = 0
    #$ omp end section
         
        
    #$ omp end parallel
    
       
