#include "mod_yv25x67s6juk_yv25x67s6juk.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


/*........................................*/
int64_t solve_2d_nonlinearconv_pure(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c)
{
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    int64_t i_0004;
    #pragma omp parallel
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < (int64_t)(1 / dy + 1) - (int64_t)(0.5 / dy); i_0001 += 1)
                {
                    for (i_0002 = 0; i_0002 < (int64_t)(1 / dx + 1) - (int64_t)(0.5 / dx); i_0002 += 1)
                    {
                        GET_ELEMENT(u, nd_double, (int64_t)i_0001 + (int64_t)(0.5 / dy), (int64_t)i_0002 + (int64_t)(0.5 / dx)) = 2;
                    }
                }
            }
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < (int64_t)(1 / dy + 1) - (int64_t)(0.5 / dy); i_0001 += 1)
                {
                    for (i_0002 = 0; i_0002 < (int64_t)(1 / dx + 1) - (int64_t)(0.5 / dx); i_0002 += 1)
                    {
                        GET_ELEMENT(v, nd_double, (int64_t)i_0001 + (int64_t)(0.5 / dy), (int64_t)i_0002 + (int64_t)(0.5 / dx)) = 2;
                    }
                }
            }
            #pragma omp section
            {
                row = u.shape[0];
                col = u.shape[1];
            }
        }
        #pragma omp for
        for (n = 0; n < nt; n += 1)
        {
            for (i_0003 = 0; i_0003 < un.shape[0]; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < un.shape[1]; i_0004 += 1)
                {
                    GET_ELEMENT(un, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(u, nd_double, (int64_t)i_0003, (int64_t)i_0004);
                }
            }
            for (i_0003 = 0; i_0003 < vn.shape[0]; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < vn.shape[1]; i_0004 += 1)
                {
                    GET_ELEMENT(vn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(v, nd_double, (int64_t)i_0003, (int64_t)i_0004);
                }
            }
            for (i = 1; i < row; i += 1)
            {
                for (j = 1; j < col; j += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i - 1, (int64_t)j)) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j - 1));
                    GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(vn, nd_double, (int64_t)i - 1, (int64_t)j)) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) - GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j - 1));
                }
            }
        }
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < u.shape[1]; i_0001 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0001) = 1;
                    GET_ELEMENT(u, nd_double, (int64_t)col - 1, (int64_t)i_0001) = 1;
                }
                for (i_0001 = 0; i_0001 < u.shape[0]; i_0001 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)0) = 1;
                    GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)row - 1) = 1;
                }
            }
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < v.shape[1]; i_0001 += 1)
                {
                    GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0001) = 1;
                    GET_ELEMENT(v, nd_double, (int64_t)col - 1, (int64_t)i_0001) = 1;
                }
                for (i_0001 = 0; i_0001 < v.shape[0]; i_0001 += 1)
                {
                    GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)0) = 1;
                    GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)row - 1) = 1;
                }
            }
        }
    }
    return 0;
}
/*........................................*/

