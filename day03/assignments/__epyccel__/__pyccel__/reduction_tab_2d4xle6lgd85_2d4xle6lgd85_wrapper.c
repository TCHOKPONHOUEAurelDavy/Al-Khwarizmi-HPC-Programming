#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void bind_c_initialize_table(int64_t n0_tab, int64_t n1_tab, int64_t n2_tab, double *tab, int64_t nmolec, int64_t n, int64_t nmol);
void bind_c_reduction(int64_t n0_tab, int64_t n1_tab, int64_t n2_tab, double *tab, int64_t n0_tab1, double *tab1, int64_t n0_tab2, double *tab2, int64_t nmolec, int64_t nmol, int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *initialize_table_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray tab = {.shape = NULL};
    int64_t nmolec;
    int64_t n;
    int64_t nmol;
    PyArrayObject *tab_tmp;
    PyObject *nmolec_tmp;
    PyObject *n_tmp;
    PyObject *nmol_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "tab",
        "nmolec",
        "n",
        "nmol",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO", kwlist, &PyArray_Type, &tab_tmp, &nmolec_tmp, &n_tmp, &nmol_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(tab_tmp, NPY_DOUBLE, 3, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        tab = pyarray_to_ndarray(tab_tmp);
    }
    if (PyIs_NativeInt(nmolec_tmp))
    {
        nmolec = PyInt64_to_Int64(nmolec_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
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
    if (PyIs_NativeInt(nmol_tmp))
    {
        nmol = PyInt64_to_Int64(nmol_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    bind_c_initialize_table(nd_ndim(&tab, 0), nd_ndim(&tab, 1), nd_ndim(&tab, 2), nd_data(&tab), nmolec, n, nmol);
    result = Py_BuildValue("");
    free_pointer(tab);
    return result;
}
/*........................................*/

/*........................................*/
PyObject *reduction_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray tab = {.shape = NULL};
    t_ndarray tab1 = {.shape = NULL};
    t_ndarray tab2 = {.shape = NULL};
    int64_t nmolec;
    int64_t nmol;
    int64_t n;
    PyArrayObject *tab_tmp;
    PyArrayObject *tab1_tmp;
    PyArrayObject *tab2_tmp;
    PyObject *nmolec_tmp;
    PyObject *nmol_tmp;
    PyObject *n_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "tab",
        "tab1",
        "tab2",
        "nmolec",
        "nmol",
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!OOO", kwlist, &PyArray_Type, &tab_tmp, &PyArray_Type, &tab1_tmp, &PyArray_Type, &tab2_tmp, &nmolec_tmp, &nmol_tmp, &n_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(tab_tmp, NPY_DOUBLE, 3, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        tab = pyarray_to_ndarray(tab_tmp);
    }
    if (!pyarray_check(tab1_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        tab1 = pyarray_to_ndarray(tab1_tmp);
    }
    if (!pyarray_check(tab2_tmp, NPY_DOUBLE, 1, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        tab2 = pyarray_to_ndarray(tab2_tmp);
    }
    if (PyIs_NativeInt(nmolec_tmp))
    {
        nmolec = PyInt64_to_Int64(nmolec_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(nmol_tmp))
    {
        nmol = PyInt64_to_Int64(nmol_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
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
    bind_c_reduction(nd_ndim(&tab, 0), nd_ndim(&tab, 1), nd_ndim(&tab, 2), nd_data(&tab), nd_ndim(&tab1, 0), nd_data(&tab1), nd_ndim(&tab2, 0), nd_data(&tab2), nmolec, nmol, n);
    result = Py_BuildValue("");
    free_pointer(tab);
    free_pointer(tab1);
    free_pointer(tab2);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef reduction_tab_2d4xle6lgd85_2d4xle6lgd85_methods[] = {
    {
        "initialize_table",
        (PyCFunction)initialize_table_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "reduction",
        (PyCFunction)reduction_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot reduction_tab_2d4xle6lgd85_2d4xle6lgd85_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef reduction_tab_2d4xle6lgd85_2d4xle6lgd85_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "reduction_tab_2d4xle6lgd85_2d4xle6lgd85",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    reduction_tab_2d4xle6lgd85_2d4xle6lgd85_methods,
    reduction_tab_2d4xle6lgd85_2d4xle6lgd85_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_reduction_tab_2d4xle6lgd85_2d4xle6lgd85(void)
{
    import_array();
    return PyModuleDef_Init(&reduction_tab_2d4xle6lgd85_2d4xle6lgd85_module);
}
