#ifndef MOD_XIK2400R9UJQ_XIK2400R9UJQ_H
#define MOD_XIK2400R9UJQ_XIK2400R9UJQ_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c);
#endif // MOD_XIK2400R9UJQ_XIK2400R9UJQ_H
