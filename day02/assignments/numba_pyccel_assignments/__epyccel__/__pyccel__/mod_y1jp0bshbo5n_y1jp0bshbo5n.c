#include "mod_y1jp0bshbo5n_y1jp0bshbo5n.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t solve_2d_poisson_pyccel(t_ndarray p, t_ndarray pd, t_ndarray b, int64_t nx, int64_t ny, int64_t nt, double dx, double dy)
{
    int64_t row;
    int64_t col;
    int64_t it;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    row = p.shape[0];
    col = p.shape[1];
    /*Source*/
    GET_ELEMENT(b, nd_double, (int64_t)(int64_t)((double)(ny) / 4.0), (int64_t)(int64_t)((double)(nx) / 4.0)) = 100;
    GET_ELEMENT(b, nd_double, (int64_t)(int64_t)((double)(3 * ny) / 4.0), (int64_t)(int64_t)((double)(3 * nx) / 4.0)) = -100;
    for (it = 0; it < nt; it += 1)
    {
        for (i = 0; i < nx; i += 1)
        {
            for (i_0002 = 0; i_0002 < pd.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(pd, nd_double, (int64_t)i, (int64_t)i_0002) = GET_ELEMENT(p, nd_double, (int64_t)i, (int64_t)i_0002);
            }
        }
        for (j = 2; j < row; j += 1)
        {
            for (i = 2; i < col; i += 1)
            {
                GET_ELEMENT(p, nd_double, (int64_t)j - 1, (int64_t)i - 1) = ((GET_ELEMENT(pd, nd_double, (int64_t)j - 1, (int64_t)i) + GET_ELEMENT(pd, nd_double, (int64_t)j - 1, (int64_t)i - 2)) * pow(dy, 2.0) + (GET_ELEMENT(pd, nd_double, (int64_t)j, (int64_t)i - 1) + GET_ELEMENT(pd, nd_double, (int64_t)j - 2, (int64_t)i - 1)) * pow(dx, 2.0) - GET_ELEMENT(b, nd_double, (int64_t)j - 1, (int64_t)i - 1) * pow(dx, 2.0) * pow(dy, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0)));
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0001) = 0;
            GET_ELEMENT(p, nd_double, (int64_t)ny - 1, (int64_t)i_0001) = 0;
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)0) = 0;
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)nx - 1) = 0;
        }
    }
    return 0;
}
/*........................................*/

