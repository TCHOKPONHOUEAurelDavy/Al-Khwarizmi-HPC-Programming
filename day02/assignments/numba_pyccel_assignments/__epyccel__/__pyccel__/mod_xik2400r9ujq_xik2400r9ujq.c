#include "mod_xik2400r9ujq_xik2400r9ujq.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


/*........................................*/
/*____________________*/
/*                     */
/*_____________________*/
int64_t solve_2d_nonlinearconv_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c)
{
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    /*##Assign initial conditions*/
    /*#set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2*/
    for (i_0001 = 0; i_0001 < (int64_t)(1 / dy + 1) - (int64_t)(0.5 / dy); i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < (int64_t)(1 / dx + 1) - (int64_t)(0.5 / dx); i_0002 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i_0001 + (int64_t)(0.5 / dy), (int64_t)i_0002 + (int64_t)(0.5 / dx)) = 2;
        }
    }
    /*#set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2*/
    for (i_0001 = 0; i_0001 < (int64_t)(1 / dy + 1) - (int64_t)(0.5 / dy); i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < (int64_t)(1 / dx + 1) - (int64_t)(0.5 / dx); i_0002 += 1)
        {
            GET_ELEMENT(v, nd_double, (int64_t)i_0001 + (int64_t)(0.5 / dy), (int64_t)i_0002 + (int64_t)(0.5 / dx)) = 2;
        }
    }
    row = u.shape[0];
    col = u.shape[1];
    for (n = 0; n < nt; n += 1)
    {
        for (i = 0; i < row; i += 1)
        {
            for (j = 0; j < col; j += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j);
                GET_ELEMENT(vn, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(v, nd_double, (int64_t)i, (int64_t)j);
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
    return 0;
}
/*........................................*/

