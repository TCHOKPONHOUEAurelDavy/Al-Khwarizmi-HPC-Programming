def solve_2d_linearconv_pyccel( u:'float[:]', un:'float[:]', nt:'int', dt:'float', dx:'float', dy:'float', c:'float'):
 
    row, co = u.shape

    for n in range(nt):
        for i in range(row):
            for j in range(co):
                un[i , j]=u[i , j]
        for i in range(1,row):
            for j in range(1,co):
                u[i , j]= un[ i , j] - c * dt / dx * (un[i , j] - un[i-1 , j]) - c * dt / dy * (un[i , j] - un[i , j-1])                                   
    u[0, :] = 1
    u[co-1, :] = 1
    u[:, 0] = 1
    u[:, row-1] = 1             
    return 0
