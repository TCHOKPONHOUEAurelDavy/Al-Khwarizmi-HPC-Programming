#ifndef MOD_DWAF5E0LV8UU_DWAF5E0LV8UU_H
#define MOD_DWAF5E0LV8UU_DWAF5E0LV8UU_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t cavity_flow_pure(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu);
#endif // MOD_DWAF5E0LV8UU_DWAF5E0LV8UU_H
