#include "mod_nob0tq1cb2nw_nob0tq1cb2nw.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


/*........................................*/
int64_t solve_1d_linearconv_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double c)
{
    int64_t n;
    int64_t i;
    for (n = 0; n < nt; n += 1)
    {
        for (i = 0; i < nx; i += 1)
        {
            GET_ELEMENT(un, nd_double, (int64_t)i) = GET_ELEMENT(u, nd_double, (int64_t)i);
        }
        for (i = 1; i < nx; i += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i) = GET_ELEMENT(un, nd_double, (int64_t)i) - c * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i) - GET_ELEMENT(un, nd_double, (int64_t)i - 1));
        }
    }
    return 0;
}
/*........................................*/

