#ifndef MOD_BUMTEYMFLA2F_BUMTEYMFLA2F_H
#define MOD_BUMTEYMFLA2F_BUMTEYMFLA2F_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t solve_2d_nonlinearconv_pure(t_ndarray u, t_ndarray un, t_ndarray v, t_ndarray vn, int64_t nt, double dt, double dx, double dy, double c);
#endif // MOD_BUMTEYMFLA2F_BUMTEYMFLA2F_H
