#ifndef MOD_Y1JP0BSHBO5N_Y1JP0BSHBO5N_H
#define MOD_Y1JP0BSHBO5N_Y1JP0BSHBO5N_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_poisson_pyccel(t_ndarray p, t_ndarray pd, t_ndarray b, int64_t nx, int64_t ny, int64_t nt, double dx, double dy);
#endif // MOD_Y1JP0BSHBO5N_Y1JP0BSHBO5N_H
