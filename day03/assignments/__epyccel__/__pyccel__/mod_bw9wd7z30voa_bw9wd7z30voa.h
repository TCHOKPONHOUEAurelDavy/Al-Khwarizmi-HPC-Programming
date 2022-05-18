#ifndef MOD_BW9WD7Z30VOA_BW9WD7Z30VOA_H
#define MOD_BW9WD7Z30VOA_BW9WD7Z30VOA_H

#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"


int64_t cavity_flow_pure(int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu);
#endif // MOD_BW9WD7Z30VOA_BW9WD7Z30VOA_H
