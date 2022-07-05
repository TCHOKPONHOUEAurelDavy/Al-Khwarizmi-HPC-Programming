def strassen_multiply(A:'foat[:,:]', B:'float[:,:]', C:'float[:,:]', n:'int'):
    import numpy as np
    #$ omp parallel
    if n & 1 != 0  or n < 128:
        #$ omp section
        C[:] = np.matmul(A, B)
        #$ omp end section
    else:
        n2 = n // 2
        
        #$ omp sections nowait
        #$ omp section
        A11 = A[ 0:n2, 0:n2 ]
        A21 = A[ n2:n, 0:n2 ]
        A12 = A[ 0:n2, n2:n ]
        A22 = A[ n2:n, n2:n ]
        #$ omp end section
        #$ omp section
        B11 = B[ 0:n2, 0:n2 ]
        B21 = B[ n2:n, 0:n2 ]
        B12 = B[ 0:n2, n2:n ]
        B22 = B[ n2:n, n2:n ]
        #$ omp end section
        
        #$ omp section
        Q1 = np.empty((n2, n2), dtype=np.double)
        Q2 = np.empty((n2, n2), dtype=np.double)
        Q3 = np.empty((n2, n2), dtype=np.double)
        Q4 = np.empty((n2, n2), dtype=np.double)
        Q5 = np.empty((n2, n2), dtype=np.double)
        Q6 = np.empty((n2, n2), dtype=np.double)
        Q7 = np.empty((n2, n2), dtype=np.double)
        #$ omp end section
        #$ omp end sections
        
        #$ omp sections nowait
        #$ omp section
        strassen_multiply(A11+A22, B11+B22, Q1, n2)
        #$ omp end section
        #$ omp section
        strassen_multiply(A21+A22, B11, Q2, n2)
        #$ omp end section
        #$ omp section
        strassen_multiply(A11, B12-B22, Q3, n2)
        #$ omp end section
        #$ omp section
        strassen_multiply(A22, -B11+B21, Q4, n2) 
        #$ omp end section
        #$ omp section
        strassen_multiply(A11+A12, B22, Q5, n2)
        #$ omp end section
        #$ omp section
        strassen_multiply(-A11+A21, B11+B12, Q6, n2)
        #$ omp end section
        #$ omp section
        strassen_multiply(A12-A22, B21+B22, Q7, n2)
        #$ omp end section
        #$ omp end sections
        
        #$ omp sections nowait
        #$ omp section
        C[   :n2,   :n2 ] = Q1+Q4-Q5+Q7
        #$ omp end section
        #$ omp section
        C[ n2: n,   :n2 ] = Q2+Q4
        #$ omp end section
        #$ omp section
        C[   :n2, n2:n  ] = Q3+Q5
        #$ omp end section
        #$ omp section
        C[ n2:n , n2:n  ] = Q1+Q3-Q2+Q6
        #$ omp end section
        #$ omp end sections
        
    #omp end parallel
