@types('float[:,:]','float[:,:]','float[:,:]','int','int')
def matrix_prod(A, B, C, N, M):


    #$ omp parallel private (i,j) 
    print("bonjour")
    #$ omp for collapse(2)
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)
    

    #$ omp for collapse(2)  
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

    #$ omp for collapse(2)   
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
  

    #$ omp barrier
    #$ omp for    
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]

    #$ omp end parallel
    return 0
