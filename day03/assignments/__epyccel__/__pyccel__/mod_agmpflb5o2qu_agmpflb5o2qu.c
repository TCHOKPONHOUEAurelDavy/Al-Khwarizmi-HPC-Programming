#include "mod_agmpflb5o2qu_agmpflb5o2qu.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nt)
{
    int64_t row;
    int64_t col;
    t_ndarray pn = {.shape = NULL};
    int64_t q;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    row = p.shape[0];
    col = p.shape[1];
    pn = array_create(2, (int64_t[]){p.shape[0], p.shape[1]}, nd_double);
    #pragma omp parallel
    {
        #pragma omp for
        for (q = 0; q < nt; q += 1)
        {
            for (i_0002 = 0; i_0002 < p.shape[0]; i_0002 += 1)
            {
                for (i_0003 = 0; i_0003 < p.shape[1]; i_0003 += 1)
                {
                    GET_ELEMENT(pn, nd_double, (int64_t)i_0002, (int64_t)i_0003) = GET_ELEMENT(p, nd_double, (int64_t)i_0002, (int64_t)i_0003);
                }
            }
            for (i = 1; i < row - 1; i += 1)
            {
                for (j = 1; j < col - 1; j += 1)
                {
                    GET_ELEMENT(p, nd_double, (int64_t)i, (int64_t)j) = ((GET_ELEMENT(pn, nd_double, (int64_t)i + 1, (int64_t)j) + GET_ELEMENT(pn, nd_double, (int64_t)i - 1, (int64_t)j)) * pow(dy, 2.0) + (GET_ELEMENT(pn, nd_double, (int64_t)i, (int64_t)j + 1) + GET_ELEMENT(pn, nd_double, (int64_t)i, (int64_t)j - 1)) * pow(dx, 2.0)) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) - pow(dx, 2.0) * pow(dy, 2.0) / (2 * (pow(dx, 2.0) + pow(dy, 2.0))) * GET_ELEMENT(b, nd_double, (int64_t)i, (int64_t)j);
                }
            }
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 1) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)p.shape[1] - 2);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)0, (int64_t)i_0001) = GET_ELEMENT(p, nd_double, (int64_t)1, (int64_t)i_0001);
        }
        for (i_0001 = 0; i_0001 < p.shape[0]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)0) = GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)1);
        }
        for (i_0001 = 0; i_0001 < p.shape[1]; i_0001 += 1)
        {
            GET_ELEMENT(p, nd_double, (int64_t)p.shape[0] - 1, (int64_t)i_0001) = 0;
        }
    }
    free_array(pn);
    return 0;
}
/*........................................*/

