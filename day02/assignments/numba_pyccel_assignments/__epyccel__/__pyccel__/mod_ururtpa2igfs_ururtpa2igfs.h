#ifndef MOD_URURTPA2IGFS_URURTPA2IGFS_H
#define MOD_URURTPA2IGFS_URURTPA2IGFS_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_burger_pyccel(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double nu);
#endif // MOD_URURTPA2IGFS_URURTPA2IGFS_H
