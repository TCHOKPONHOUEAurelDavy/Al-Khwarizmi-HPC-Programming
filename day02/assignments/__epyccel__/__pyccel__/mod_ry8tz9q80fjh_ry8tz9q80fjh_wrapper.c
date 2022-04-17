#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>


int64_t factorial(int64_t n);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *factorial_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t n;
    int64_t Out_0001;
    PyObject *n_tmp;
    PyObject *Out_0001_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &n_tmp))
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
    Out_0001 = factorial(n);
    Out_0001_tmp = Int64_to_PyLong(&Out_0001);
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

static PyMethodDef mod_ry8tz9q80fjh_ry8tz9q80fjh_methods[] = {
    {
        "factorial",
        (PyCFunction)factorial_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_ry8tz9q80fjh_ry8tz9q80fjh_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_ry8tz9q80fjh_ry8tz9q80fjh_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_ry8tz9q80fjh_ry8tz9q80fjh",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_ry8tz9q80fjh_ry8tz9q80fjh_methods,
    mod_ry8tz9q80fjh_ry8tz9q80fjh_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_ry8tz9q80fjh_ry8tz9q80fjh(void)
{
    import_array();
    return PyModuleDef_Init(&mod_ry8tz9q80fjh_ry8tz9q80fjh_module);
}
