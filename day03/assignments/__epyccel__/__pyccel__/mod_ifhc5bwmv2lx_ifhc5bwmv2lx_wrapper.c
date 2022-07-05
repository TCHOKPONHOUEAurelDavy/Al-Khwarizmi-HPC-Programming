#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>


double bind_c_f(double a);

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

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_ifhc5bwmv2lx_ifhc5bwmv2lx_methods[] = {
    {
        "f",
        (PyCFunction)f_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_ifhc5bwmv2lx_ifhc5bwmv2lx_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_ifhc5bwmv2lx_ifhc5bwmv2lx_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_ifhc5bwmv2lx_ifhc5bwmv2lx",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_ifhc5bwmv2lx_ifhc5bwmv2lx_methods,
    mod_ifhc5bwmv2lx_ifhc5bwmv2lx_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_ifhc5bwmv2lx_ifhc5bwmv2lx(void)
{
    import_array();
    return PyModuleDef_Init(&mod_ifhc5bwmv2lx_ifhc5bwmv2lx_module);
}
