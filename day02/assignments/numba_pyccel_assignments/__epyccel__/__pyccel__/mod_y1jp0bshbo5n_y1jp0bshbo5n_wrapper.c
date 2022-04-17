#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t solve_2d_poisson_pyccel(t_ndarray p, t_ndarray pd, t_ndarray b, int64_t nx, int64_t ny, int64_t nt, double dx, double dy);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *solve_2d_poisson_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    t_ndarray pd = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    int64_t nx;
    int64_t ny;
    int64_t nt;
    double dx;
    double dy;
    int64_t Out_0001;
    PyArrayObject *p_tmp;
    PyArrayObject *pd_tmp;
    PyArrayObject *b_tmp;
    PyObject *nx_tmp;
    PyObject *ny_tmp;
    PyObject *nt_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "pd",
        "b",
        "nx",
        "ny",
        "nt",
        "dx",
        "dy",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!OOOOO", kwlist, &PyArray_Type, &p_tmp, &PyArray_Type, &pd_tmp, &PyArray_Type, &b_tmp, &nx_tmp, &ny_tmp, &nt_tmp, &dx_tmp, &dy_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (!pyarray_check(pd_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        pd = pyarray_to_ndarray(pd_tmp);
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
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
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
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
    Out_0001 = solve_2d_poisson_pyccel(p, pd, b, nx, ny, nt, dx, dy);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(p);
    free_pointer(pd);
    free_pointer(b);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_y1jp0bshbo5n_y1jp0bshbo5n_methods[] = {
    {
        "solve_2d_poisson_pyccel",
        (PyCFunction)solve_2d_poisson_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_y1jp0bshbo5n_y1jp0bshbo5n_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_y1jp0bshbo5n_y1jp0bshbo5n_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_y1jp0bshbo5n_y1jp0bshbo5n",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_y1jp0bshbo5n_y1jp0bshbo5n_methods,
    mod_y1jp0bshbo5n_y1jp0bshbo5n_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_y1jp0bshbo5n_y1jp0bshbo5n(void)
{
    import_array();
    return PyModuleDef_Init(&mod_y1jp0bshbo5n_y1jp0bshbo5n_module);
}
