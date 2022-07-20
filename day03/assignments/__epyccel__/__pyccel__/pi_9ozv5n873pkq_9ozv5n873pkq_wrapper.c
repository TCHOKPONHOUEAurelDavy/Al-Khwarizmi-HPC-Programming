#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


double bind_c_f(double a);
double bind_c_pi(int64_t n, double h);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *f_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    double a;
    double Out_0001;
    PyObject *a_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "a",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &a_tmp))
    {
        return NULL;
    }
    if (PyIs_NativeFloat(a_tmp))
    {
        a = PyDouble_to_Double(a_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Out_0001 = bind_c_f(a);
    Out_0001_tmp = Double_to_PyDouble(&Out_0001);
    result = Py_BuildValue("O", Out_0001_tmp);
    Py_DECREF(Out_0001_tmp);
    return result;
}
/*........................................*/

/*........................................*/
PyObject *pi_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    double h;
    double Pi_calc;
    PyObject *n_tmp;
    PyObject *h_tmp;
    PyObject *Pi_calc_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        "h",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &n_tmp, &h_tmp))
    {
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
    if (PyIs_NativeFloat(h_tmp))
    {
        h = PyDouble_to_Double(h_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    Pi_calc = bind_c_pi(n, h);
    Pi_calc_tmp = Double_to_PyDouble(&Pi_calc);
    result = Py_BuildValue("O", Pi_calc_tmp);
    Py_DECREF(Pi_calc_tmp);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef pi_9ozv5n873pkq_9ozv5n873pkq_methods[] = {
    {
        "f",
        (PyCFunction)f_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "pi",
        (PyCFunction)pi_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot pi_9ozv5n873pkq_9ozv5n873pkq_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef pi_9ozv5n873pkq_9ozv5n873pkq_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "pi_9ozv5n873pkq_9ozv5n873pkq",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    pi_9ozv5n873pkq_9ozv5n873pkq_methods,
    pi_9ozv5n873pkq_9ozv5n873pkq_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_pi_9ozv5n873pkq_9ozv5n873pkq(void)
{
    import_array();
    return PyModuleDef_Init(&pi_9ozv5n873pkq_9ozv5n873pkq_module);
}
