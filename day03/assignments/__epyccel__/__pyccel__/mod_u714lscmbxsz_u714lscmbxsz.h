#ifndef MOD_U714LSCMBXSZ_U714LSCMBXSZ_H
#define MOD_U714LSCMBXSZ_U714LSCMBXSZ_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nt);
#endif // MOD_U714LSCMBXSZ_U714LSCMBXSZ_H
