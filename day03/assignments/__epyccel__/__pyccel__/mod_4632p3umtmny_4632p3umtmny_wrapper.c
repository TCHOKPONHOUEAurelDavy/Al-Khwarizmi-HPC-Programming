#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


int bind_c_jacobi(int64_t n0_a, int64_t n1_a, double *a, int64_t n0_b, double *b, int64_t n0_x, double *x, int64_t n, double eps, double *stand, int64_t *iteration);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *jacobi_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray a = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    t_ndarray x = {.shape = NULL};
    int64_t n;
    double eps;
    double stand;
    int64_t iteration;
    PyArrayObject *a_tmp;
    PyArrayObject *b_tmp;
    PyArrayObject *x_tmp;
    PyObject *n_tmp;
    PyObject *eps_tmp;
    PyObject *stand_tmp;
    PyObject *iteration_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "a",
        "b",
        "x",
        "n",
        "eps",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!OO", kwlist, &PyArray_Type, &a_tmp, &PyArray_Type, &b_tmp, &PyArray_Type, &x_tmp, &n_tmp, &eps_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(a_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        a = pyarray_to_ndarray(a_tmp);
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (!pyarray_check(x_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        x = pyarray_to_ndarray(x_tmp);
    }
    if (PyIs_NativeInt(n_tmp))
    {
        n = PyInt64_to_Int64(n_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(eps_tmp))
    {
        eps = PyDouble_to_Double(eps_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    bind_c_jacobi(nd_ndim(&a, 0), nd_ndim(&a, 1), nd_data(&a), nd_ndim(&b, 0), nd_data(&b), nd_ndim(&x, 0), nd_data(&x), n, eps, &stand, &iteration);
    stand_tmp = Double_to_PyDouble(&stand);
    iteration_tmp = Int64_to_PyLong(&iteration);
    result = Py_BuildValue("OO", stand_tmp, iteration_tmp);
    Py_DECREF(stand_tmp);
    Py_DECREF(iteration_tmp);
    free_pointer(a);
    free_pointer(b);
    free_pointer(x);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_4632p3umtmny_4632p3umtmny_methods[] = {
    {
        "jacobi",
        (PyCFunction)jacobi_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_4632p3umtmny_4632p3umtmny_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_4632p3umtmny_4632p3umtmny_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_4632p3umtmny_4632p3umtmny",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_4632p3umtmny_4632p3umtmny_methods,
    mod_4632p3umtmny_4632p3umtmny_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_4632p3umtmny_4632p3umtmny(void)
{
    import_array();
    return PyModuleDef_Init(&mod_4632p3umtmny_4632p3umtmny_module);
}
