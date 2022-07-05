#ifndef MOD_AGMPFLB5O2QU_AGMPFLB5O2QU_H
#define MOD_AGMPFLB5O2QU_AGMPFLB5O2QU_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nt);
#endif // MOD_AGMPFLB5O2QU_AGMPFLB5O2QU_H
