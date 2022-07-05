#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t pressure_poisson_numba(t_ndarray p, double dx, double dy, t_ndarray b, int64_t nt);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *pressure_poisson_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    double dx;
    double dy;
    t_ndarray b = {.shape = NULL};
    int64_t nt;
    int64_t Out_0001;
    PyArrayObject *p_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *b_tmp;
    PyObject *nt_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "dx",
        "dy",
        "b",
        "nt",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!OOO!O", kwlist, &PyArray_Type, &p_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &b_tmp, &nt_tmp))
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
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
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
    Out_0001 = pressure_poisson_numba(p, dx, dy, b, nt);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(p);
    free_pointer(b);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_agmpflb5o2qu_agmpflb5o2qu_methods[] = {
    {
        "pressure_poisson_numba",
        (PyCFunction)pressure_poisson_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_agmpflb5o2qu_agmpflb5o2qu_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_agmpflb5o2qu_agmpflb5o2qu_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_agmpflb5o2qu_agmpflb5o2qu",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_agmpflb5o2qu_agmpflb5o2qu_methods,
    mod_agmpflb5o2qu_agmpflb5o2qu_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_agmpflb5o2qu_agmpflb5o2qu(void)
{
    import_array();
    return PyModuleDef_Init(&mod_agmpflb5o2qu_agmpflb5o2qu_module);
}
