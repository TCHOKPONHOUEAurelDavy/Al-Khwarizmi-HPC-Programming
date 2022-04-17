#include "mod_73zzaugg5cxm_73zzaugg5cxm.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_1d_burger_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double nu)
{
    int64_t n;
    int64_t i;
    for (n = 0; n < nt; n += 1)
    {
        for (i = 0; i < nx; i += 1)
        {
            GET_ELEMENT(un, nd_double, (int64_t)i) = GET_ELEMENT(u, nd_double, (int64_t)i);
        }
        for (i = 1; i < nx - 1; i += 1)
        {
            GET_ELEMENT(u, nd_double, (int64_t)i) = GET_ELEMENT(un, nd_double, (int64_t)i) - GET_ELEMENT(un, nd_double, (int64_t)i) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i) - GET_ELEMENT(un, nd_double, (int64_t)i - 1)) + nu * dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i) + GET_ELEMENT(un, nd_double, (int64_t)i - 1));
        }
    }
    return 0;
}
/*........................................*/

