#include "mod_5y5pp3npznp3_5y5pp3npznp3.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include <math.h>


/*........................................*/
int jacobi(t_ndarray a, t_ndarray b, t_ndarray x, int64_t n, double eps, double *stand, int64_t *iteration)
{
    t_ndarray x_courant = {.shape = NULL};
    int64_t i;
    int64_t j;
    double absmax;
    double curr;
    int64_t i_0001;
    /*print("Execution of Jacobi in parallel with", nb_tasks, "threads")*/
    /*Jacobi method resolution*/
    x_courant = array_create(1, (int64_t[]){n}, nd_double);
    (*iteration) = 0;
    while((1 != 0))
    {
        (*iteration) += 1;
        for (i = 0; i < n; i += 1)
        {
            GET_ELEMENT(x_courant, nd_double, (int64_t)i) = 0;
            for (j = 0; j < i; j += 1)
            {
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * array_slicing(x, 1, new_slice(j, j + 1, 1), new_slice(0, x.shape[1], 1));
            }
            for (j = i + 1; j < n; j += 1)
            {
                GET_ELEMENT(x_courant, nd_double, (int64_t)i) += GET_ELEMENT(a, nd_double, (int64_t)j, (int64_t)i) * array_slicing(x, 1, new_slice(j, j + 1, 1), new_slice(0, x.shape[1], 1));
            }
            GET_ELEMENT(x_courant, nd_double, (int64_t)i) = (array_slicing(b, 1, new_slice(i, i + 1, 1), new_slice(0, b.shape[1], 1)) - GET_ELEMENT(x_courant, nd_double, (int64_t)i)) / GET_ELEMENT(a, nd_double, (int64_t)i, (int64_t)i);
        }
        /*Convergence test*/
        absmax = 0.0;
        for (i = 0; i < n; i += 1)
        {
            curr = fabs(array_slicing(x, 1, new_slice(i, i + 1, 1), new_slice(0, x.shape[1], 1)) - GET_ELEMENT(x_courant, nd_double, (int64_t)i));
            if (curr > absmax)
            {
                absmax = curr;
            }
        }
        (*stand) = absmax / n;
        if ((*stand) <= eps || (*iteration) > n)
        {
            break;
        }
        /*copy x_courant into x*/
        for (i = 0; i < n; i += 1)
        {
            for (i_0001 = 0; i_0001 < x.shape[1]; i_0001 += 1)
            {
                GET_ELEMENT(x, nd_double, (int64_t)i, (int64_t)i_0001) = GET_ELEMENT(x_courant, nd_double, (int64_t)i);
            }
        }
    }
    free_array(x_courant);
    return 0;
}
/*........................................*/

