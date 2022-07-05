#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"
#include <stdint.h>


void bind_c_build_up_b_numba(int64_t n0_b, int64_t n1_b, double *b, double rho, double dt, int64_t n0_u, int64_t n1_u, double *u, int64_t n0_v, int64_t n1_v, double *v, double dx, double dy);
void bind_c_pressure_poisson_numba(int64_t n0_p, int64_t n1_p, double *p, double dx, double dy, int64_t n0_b, int64_t n1_b, double *b, int64_t nit, int64_t nt);
void bind_c_cavity_flow_numba(int64_t n0_u, int64_t n1_u, double *u, int64_t n0_v, int64_t n1_v, double *v, double dt, int64_t nx, int64_t ny, double dx, double dy, int64_t n0_p, int64_t n1_p, double *p, double rho, double nu, int64_t nit, int64_t nt);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *build_up_b_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray b = {.shape = NULL};
    double rho;
    double dt;
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dx;
    double dy;
    PyArrayObject *b_tmp;
    PyObject *rho_tmp;
    PyObject *dt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "b",
        "rho",
        "dt",
        "u",
        "v",
        "dx",
        "dy",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!O!OO", kwlist, &PyArray_Type, &b_tmp, &rho_tmp, &dt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dx_tmp, &dy_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeFloat(rho_tmp))
    {
        rho = PyDouble_to_Double(rho_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        v = pyarray_to_ndarray(v_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    bind_c_build_up_b_numba(nd_ndim(&b, 0), nd_ndim(&b, 1), nd_data(&b), rho, dt, nd_ndim(&u, 0), nd_ndim(&u, 1), nd_data(&u), nd_ndim(&v, 0), nd_ndim(&v, 1), nd_data(&v), dx, dy);
    result = Py_BuildValue("");
    free_pointer(b);
    free_pointer(u);
    free_pointer(v);
    return result;
}
/*........................................*/

/*........................................*/
PyObject *pressure_poisson_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    double dx;
    double dy;
    t_ndarray b = {.shape = NULL};
    int64_t nit;
    int64_t nt;
    PyArrayObject *p_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *b_tmp;
    PyObject *nit_tmp;
    PyObject *nt_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "dx",
        "dy",
        "b",
        "nit",
        "nt",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!OO", kwlist, &PyArray_Type, &p_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &b_tmp, &nit_tmp, &nt_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    bind_c_pressure_poisson_numba(nd_ndim(&p, 0), nd_ndim(&p, 1), nd_data(&p), dx, dy, nd_ndim(&b, 0), nd_ndim(&b, 1), nd_data(&b), nit, nt);
    result = Py_BuildValue("");
    free_pointer(p);
    free_pointer(b);
    return result;
}
/*........................................*/

/*........................................*/
PyObject *cavity_flow_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dt;
    int64_t nx;
    int64_t ny;
    double dx;
    double dy;
    t_ndarray p = {.shape = NULL};
    double rho;
    double nu;
    int64_t nit;
    int64_t nt;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dt_tmp;
    PyObject *nx_tmp;
    PyObject *ny_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *p_tmp;
    PyObject *rho_tmp;
    PyObject *nu_tmp;
    PyObject *nit_tmp;
    PyObject *nt_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "u",
        "v",
        "dt",
        "nx",
        "ny",
        "dx",
        "dy",
        "p",
        "rho",
        "nu",
        "nit",
        "nt",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!OOOOOO!OOOO", kwlist, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dt_tmp, &nx_tmp, &ny_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &p_tmp, &rho_tmp, &nu_tmp, &nit_tmp, &nt_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        v = pyarray_to_ndarray(v_tmp);
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nx_tmp))
    {
        nx = PyInt64_to_Int64(nx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(ny_tmp))
    {
        ny = PyInt64_to_Int64(ny_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (PyIs_NativeFloat(rho_tmp))
    {
        rho = PyDouble_to_Double(rho_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(nu_tmp))
    {
        nu = PyDouble_to_Double(nu_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    bind_c_cavity_flow_numba(nd_ndim(&u, 0), nd_ndim(&u, 1), nd_data(&u), nd_ndim(&v, 0), nd_ndim(&v, 1), nd_data(&v), dt, nx, ny, dx, dy, nd_ndim(&p, 0), nd_ndim(&p, 1), nd_data(&p), rho, nu, nit, nt);
    result = Py_BuildValue("");
    free_pointer(u);
    free_pointer(v);
    free_pointer(p);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef naviestock_y6l02zf17aei_y6l02zf17aei_methods[] = {
    {
        "build_up_b_numba",
        (PyCFunction)build_up_b_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "pressure_poisson_numba",
        (PyCFunction)pressure_poisson_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "cavity_flow_numba",
        (PyCFunction)cavity_flow_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot naviestock_y6l02zf17aei_y6l02zf17aei_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef naviestock_y6l02zf17aei_y6l02zf17aei_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "naviestock_y6l02zf17aei_y6l02zf17aei",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    naviestock_y6l02zf17aei_y6l02zf17aei_methods,
    naviestock_y6l02zf17aei_y6l02zf17aei_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_naviestock_y6l02zf17aei_y6l02zf17aei(void)
{
    import_array();
    return PyModuleDef_Init(&naviestock_y6l02zf17aei_y6l02zf17aei_module);
}
