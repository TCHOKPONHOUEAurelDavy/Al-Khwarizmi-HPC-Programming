@types('float[:,:]', 'float[:,:]','float[:,:]', 'float[:,:]', 'int', 'float','float', 'float','float')
def solve_2d_nonlinearconv_pure(u, un, v, vn, nt, dt, dx, dy, c):
     
    #$ omp parallel
    
    #$ omp sections nowait
    #$ omp section
    u[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    #$ omp end section
    
    #$ omp section 
    v[int(.5 / dy):int(1 / dy + 1), int(.5 / dx):int(1 / dx + 1)] = 2
    #$ omp end section
    
    #$ omp section
    row, col = u.shape
    #$ omp end section
    #$ omp end sections
    
    
    #$ omp for 
    for n in range(nt):
        un[: , :]=u[: , :]
        vn[: , :]=v[: , :]
        #$ omp for 
        for i in range(1,row):
            for j in range(1,col):
                u[i , j]= un[ i , j] - un[ i , j] * dt / dx * (un[i , j] - un[i-1 , j]) - vn[ i , j] * dt / dy * (un[i , j] - un[i , j-1]) 
                v[i , j]= vn[ i , j] - un[ i , j] * dt / dx * (vn[i , j] - vn[i-1 , j]) - vn[ i , j] * dt / dy * (vn[i , j] - vn[i , j-1])
        #$ omp end for 
    #$ omp end for
    
    #$ omp sections nowait
    #$ omp section    
    u[0, :] = 1
    u[col-1, :] = 1
    u[:, 0] = 1
    u[:, row-1] = 1  
    #$ omp end section 
    #$ omp section 
    v[0, :] = 1
    v[col-1, :] = 1
    v[:, 0] = 1
    v[:, row-1] = 1  
    #$ omp end section 
    #$ omp end sections
    
    #$ omp end parallel
    return 0
