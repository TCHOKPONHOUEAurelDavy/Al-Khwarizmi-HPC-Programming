#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t build_up_b_numba(t_ndarray b, double rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);

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
    int64_t Out_0001;
    PyArrayObject *b_tmp;
    PyObject *rho_tmp;
    PyObject *dt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *Out_0001_tmp;
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
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
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
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
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
    Out_0001 = build_up_b_numba(b, rho, dt, u, v, dx, dy);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    free_pointer(b);
    free_pointer(u);
    free_pointer(v);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_lrdloaarlj6v_lrdloaarlj6v_methods[] = {
    {
        "build_up_b_numba",
        (PyCFunction)build_up_b_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_lrdloaarlj6v_lrdloaarlj6v_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_lrdloaarlj6v_lrdloaarlj6v_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_lrdloaarlj6v_lrdloaarlj6v",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_lrdloaarlj6v_lrdloaarlj6v_methods,
    mod_lrdloaarlj6v_lrdloaarlj6v_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_lrdloaarlj6v_lrdloaarlj6v(void)
{
    import_array();
    return PyModuleDef_Init(&mod_lrdloaarlj6v_lrdloaarlj6v_module);
}
