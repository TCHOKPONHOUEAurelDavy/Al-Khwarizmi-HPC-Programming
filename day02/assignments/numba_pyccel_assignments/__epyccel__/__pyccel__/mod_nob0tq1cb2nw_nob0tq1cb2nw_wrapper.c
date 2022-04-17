#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t solve_1d_linearconv_pyccel(t_ndarray u, t_ndarray un, int64_t nt, int64_t nx, double dt, double dx, double c);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *solve_1d_linearconv_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray u = {.shape = NULL};
    t_ndarray un = {.shape = NULL};
    int64_t nt;
    int64_t nx;
    double dt;
    double dx;
    double c;
    int64_t Out_0001;
    PyArrayObject *u_tmp;
    PyArrayObject *un_tmp;
    PyObject *nt_tmp;
    PyObject *nx_tmp;
    PyObject *dt_tmp;
    PyObject *dx_tmp;
    PyObject *c_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "u",
        "un",
        "nt",
        "nx",
        "dt",
        "dx",
        "c",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!OOOOO", kwlist, &PyArray_Type, &u_tmp, &PyArray_Type, &un_tmp, &nt_tmp, &nx_tmp, &dt_tmp, &dx_tmp, &c_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(un_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        un = pyarray_to_ndarray(un_tmp);
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
    if (PyIs_NativeInt(nx_tmp))
    {
        nx = PyInt64_to_Int64(nx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
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
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(c_tmp))
    {
        c = PyDouble_to_Double(c_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Out_0001 = solve_1d_linearconv_pyccel(u, un, nt, nx, dt, dx, c);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(u);
    free_pointer(un);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_nob0tq1cb2nw_nob0tq1cb2nw_methods[] = {
    {
        "solve_1d_linearconv_pyccel",
        (PyCFunction)solve_1d_linearconv_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_nob0tq1cb2nw_nob0tq1cb2nw_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_nob0tq1cb2nw_nob0tq1cb2nw_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_nob0tq1cb2nw_nob0tq1cb2nw",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_nob0tq1cb2nw_nob0tq1cb2nw_methods,
    mod_nob0tq1cb2nw_nob0tq1cb2nw_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_nob0tq1cb2nw_nob0tq1cb2nw(void)
{
    import_array();
    return PyModuleDef_Init(&mod_nob0tq1cb2nw_nob0tq1cb2nw_module);
}
