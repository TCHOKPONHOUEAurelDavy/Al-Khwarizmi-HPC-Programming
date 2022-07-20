#ifndef MOD_TX1F6TEB6JCS_TX1F6TEB6JCS_H
#define MOD_TX1F6TEB6JCS_TX1F6TEB6JCS_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv_pure(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c);
#endif // MOD_TX1F6TEB6JCS_TX1F6TEB6JCS_H
