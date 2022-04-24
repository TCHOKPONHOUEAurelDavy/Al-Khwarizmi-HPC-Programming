@types('int','int','int','int','int')
def matrix_prod(A, B, C, N, M):

#$ omp parallel private (i,j) num_threads(4)
#$ omp parallel private (i,j) shared(A)
    for i in range( M ):
        for j in range( N ):
            A[ i, j ] = (i + 1) + (j + 1)

#$ omp parallel private (i,j) shared(B)    
    for i in range( N ):
        for j in range( M ):
            B[ i, j ] = (i + 1) - (j + 1)

#$ omp parallel private (i,j) shared(C)    
    for i in range( M ):
        for j in range( M ):
            C[ i, j ] = 0
    # ...

    # Matrix Production
#$ omp barrier
#$ omp parallel private (i,j) shared(C)     
    for i in range( M ):
        for j in range( M ):
            for k in range( N ):
                C[ i, j ] += A[ i, k ] * B[ k, j ]

#$ omp end parallel 
    return C
