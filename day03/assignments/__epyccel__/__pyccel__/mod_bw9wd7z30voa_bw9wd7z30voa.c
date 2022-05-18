#include "mod_bw9wd7z30voa_bw9wd7z30voa.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include <math.h>


/*........................................*/
int64_t cavity_flow_pure(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu)
{
    t_ndarray un = {.shape = NULL};
    t_ndarray vn = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    t_ndarray pn = {.shape = NULL};
    int64_t row;
    int64_t col;
    int64_t n;
    int64_t q;
    int64_t i;
    int64_t j;
    int64_t i_0001;
    int64_t i_0002;
    int64_t i_0003;
    int64_t i_0004;
    un = array_create(2, (int64_t[]){u.shape[0], u.shape[1]}, nd_double);
    vn = array_create(2, (int64_t[]){v.shape[0], v.shape[1]}, nd_double);
    b = array_create(2, (int64_t[]){ny, nx}, nd_double);
    array_fill((double)0.0, b);
    pn = array_create(2, (int64_t[]){p.shape[0], p.shape[1]}, nd_double);
    row = p.shape[0];
    col = p.shape[1];
    /*omp parallel*/
    #pragma omp for
    for (n = 0; n < nt; n += 1)
    {
        for (i_0001 = 0; i_0001 < u.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < u.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        for (i_0001 = 0; i_0001 < v.shape[0]; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < v.shape[1]; i_0002 += 1)
            {
                GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002) = GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002);
            }
        }
        for (i_0001 = 0; i_0001 < b.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < b.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(b, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = rho * (1 / dt * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx) + (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)) - pow(((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)), 2.0) - 2 * ((GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy) * (GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) / (2 * dx)) - pow(((GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) / (2 * dy)), 2.0));
            }
        }
        #pragma omp for
        for (q = 0; q < nt; q += 1)
        {
            for (i_0003 = 0; i_0003 < p.shape[0]; i_0003 += 1)
            {
                for (i_0004 = 0; i_0004 < p.shape[1]; i_0004 += 1)
                {
                    GET_ELEMENT(pn, nd_double, (int64_t)i_0003, (int64_t)i_0004) = GET_ELEMENT(p, nd_double, (int64_t)i_0003, (int64_t)i_0004);
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
        for (i_0001 = 0; i_0001 < u.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < u.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(u, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dx * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dy * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) - dt / (2 * rho * dx) * (GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + dt / pow(dy, 2.0) * (GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - 2 * GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(un, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)));
            }
        }
        for (i_0001 = 0; i_0001 < v.shape[0] - 1 - 1; i_0001 += 1)
        {
            for (i_0002 = 0; i_0002 < v.shape[1] - 1 - 1; i_0002 += 1)
            {
                GET_ELEMENT(v, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) = GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(un, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dx * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) * dt / dy * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) - GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) - dt / (2 * rho * dy) * (GET_ELEMENT(p, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - GET_ELEMENT(p, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)) + nu * (dt / pow(dx, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 2) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002)) + dt / pow(dy, 2.0) * (GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 2, (int64_t)i_0002 + 1) - 2 * GET_ELEMENT(vn, nd_double, (int64_t)i_0001 + 1, (int64_t)i_0002 + 1) + GET_ELEMENT(vn, nd_double, (int64_t)i_0001, (int64_t)i_0002 + 1)));
            }
        }
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < u.shape[1]; i_0001 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)0, (int64_t)i_0001) = 0;
                }
                for (i_0001 = 0; i_0001 < u.shape[0]; i_0001 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)0) = 0;
                    GET_ELEMENT(u, nd_double, (int64_t)i_0001, (int64_t)u.shape[1] - 1) = 0;
                }
                for (i_0001 = 0; i_0001 < u.shape[1]; i_0001 += 1)
                {
                    GET_ELEMENT(u, nd_double, (int64_t)u.shape[0] - 1, (int64_t)i_0001) = 1;
                }
            }
            #pragma omp section
            {
                for (i_0001 = 0; i_0001 < v.shape[1]; i_0001 += 1)
                {
                    GET_ELEMENT(v, nd_double, (int64_t)0, (int64_t)i_0001) = 0;
                    GET_ELEMENT(v, nd_double, (int64_t)v.shape[0] - 1, (int64_t)i_0001) = 0;
                }
                for (i_0001 = 0; i_0001 < v.shape[0]; i_0001 += 1)
                {
                    GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)0) = 0;
                    GET_ELEMENT(v, nd_double, (int64_t)i_0001, (int64_t)v.shape[1] - 1) = 0;
                }
            }
        }
    }
}
free_array(un);
free_array(vn);
free_array(b);
free_array(pn);
return 0;
}
/*........................................*/

