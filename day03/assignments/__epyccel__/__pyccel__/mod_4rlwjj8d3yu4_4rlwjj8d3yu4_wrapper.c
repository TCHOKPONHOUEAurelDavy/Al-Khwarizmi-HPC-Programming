#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void bind_c_strassen_multiply(int64_t n0_A, int64_t n1_A, double *A, int64_t n0_B, int64_t n1_B, double *B, int64_t n0_C, int64_t n1_C, double *C, int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *strassen_multiply_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray A = {.shape = NULL};
    t_ndarray B = {.shape = NULL};
    t_ndarray C = {.shape = NULL};
    int64_t n;
    PyArrayObject *A_tmp;
    PyArrayObject *B_tmp;
    PyArrayObject *C_tmp;
    PyObject *n_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "A",
        "B",
        "C",
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!O!O", kwlist, &PyArray_Type, &A_tmp, &PyArray_Type, &B_tmp, &PyArray_Type, &C_tmp, &n_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(A_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        A = pyarray_to_ndarray(A_tmp);
    }
    if (!pyarray_check(B_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        B = pyarray_to_ndarray(B_tmp);
    }
    if (!pyarray_check(C_tmp, NPY_DOUBLE, 2, NPY_ARRAY_C_CONTIGUOUS))
    {
        return NULL;
    }
    else
    {
        C = pyarray_to_ndarray(C_tmp);
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
    bind_c_strassen_multiply(nd_ndim(&A, 0), nd_ndim(&A, 1), nd_data(&A), nd_ndim(&B, 0), nd_ndim(&B, 1), nd_data(&B), nd_ndim(&C, 0), nd_ndim(&C, 1), nd_data(&C), n);
    result = Py_BuildValue("");
    free_pointer(A);
    free_pointer(B);
    free_pointer(C);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_4rlwjj8d3yu4_4rlwjj8d3yu4_methods[] = {
    {
        "strassen_multiply",
        (PyCFunction)strassen_multiply_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_4rlwjj8d3yu4_4rlwjj8d3yu4_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_4rlwjj8d3yu4_4rlwjj8d3yu4_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_4rlwjj8d3yu4_4rlwjj8d3yu4",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_4rlwjj8d3yu4_4rlwjj8d3yu4_methods,
    mod_4rlwjj8d3yu4_4rlwjj8d3yu4_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_4rlwjj8d3yu4_4rlwjj8d3yu4(void)
{
    import_array();
    return PyModuleDef_Init(&mod_4rlwjj8d3yu4_4rlwjj8d3yu4_module);
}
