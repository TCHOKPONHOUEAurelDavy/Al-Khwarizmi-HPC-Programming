#ifndef MOD_YV25X67S6JUK_YV25X67S6JUK_H
#define MOD_YV25X67S6JUK_YV25X67S6JUK_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv_pure(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c);
#endif // MOD_YV25X67S6JUK_YV25X67S6JUK_H
