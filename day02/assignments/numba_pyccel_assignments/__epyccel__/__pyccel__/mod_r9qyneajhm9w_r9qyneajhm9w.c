#include "mod_r9qyneajhm9w_r9qyneajhm9w.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_2d_diff_pyccel(t_ndarray u, t_ndarray un, int64_t nt, double dt, double dx, double dy, double nu)
{
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    row = u.shape[0];
    col = u.shape[1];
    /*#Assign initial conditions*/
    /*set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2*/
    for (i_0001 = 0; i_0001 < (int64_t)(1 / dy + 1) - (int64_t)(0.5 / dy); i_0001 += 1)
    {
        for (i_0002 = 0; i_0002 < (int64_t)(1 / dx + 1) - (int64_t)(0.5 / dx); i_0002 += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i_0001 + (int64_t)(0.5 / dy), (int64_t)i_0002 + (int64_t)(0.5 / dx)) = 2;
        }
    }
    for (n = 0; n < nt; n += 1)
    {
        for (i = 0; i < row; i += 1)
        {
            for (j = 0; j < col; j += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j);
            }
        }
        for (i = 1; i < row - 1; i += 1)
        {
            for (j = 1; j < col - 1; j += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i, (int64_t)j) = GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i + 1, (int64_t)j) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(un, nd_double, (int64_t)i - 1, (int64_t)j)) + nu * dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j) + GET_ELEMENT(un, nd_double, (int64_t)i, (int64_t)j - 1));
            }
        }
    }
    return 0;
}
/*........................................*/

