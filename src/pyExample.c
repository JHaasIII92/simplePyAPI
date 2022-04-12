#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>


PyObject *pycAdd(PyObject *self, PyObject *args);
PyObject *pyPassFunc(PyObject *self, PyObject *args);

PyMODINIT_FUNC PyInit_examplAPI(void);

static PyObject *ExampleAPIError;


static PyMethodDef example_methods[] = 
{
    {"pycAdd", pycAdd, METH_VARARGS},
    {"pyPassFunc", pyPassFunc, METH_VARARGS},
    {NULL, NULL, 0, NULL}        /* Sentinel */ 
};

static struct PyModuleDef moduledef = 
{
        PyModuleDef_HEAD_INIT,         //Always initialize this member to PyModuleDef_HEAD_INIT
        "exampleAPI",
        "A Python interface for testing",
        -1,
        example_methods
};



PyMODINIT_FUNC PyInit_exampleAPI(void) {
    PyObject *m;

    m = PyModule_Create(&moduledef);
    if (m == NULL)
        return NULL;
    
    ExampleAPIError = PyErr_NewException("exampleAPI.error", NULL, NULL);
    Py_XINCREF(ExampleAPIError);
    if (PyModule_AddObject(m, "error", ExampleAPIError) < 0) {
        Py_XDECREF(ExampleAPIError);
        Py_CLEAR(ExampleAPIError);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}


PyObject *pycAdd(PyObject *self, PyObject *args)
{
    double  result;
    double       a;
    double       b;

    if (!PyArg_ParseTuple(args, "dd", &a, &b))
    {
        return NULL;
    }
    char str[] = "This is coming from the C programing Language!";
    puts(str);
    result = a + b;

    return Py_BuildValue("d",result);
}



PyObject *pyPassFunc(PyObject *self, PyObject *args)
{
    PyObject *arglist = NULL;
    PyObject *result = NULL;
    void     *passFunc = NULL;
    void     *passData = NULL;

    if (!PyArg_ParseTuple(args, "OO", 
        &passFunc,
        &passData))
        {
            return NULL;
        }

    char str[] = "This is from C!";
    arglist = Py_BuildValue("(sO)",str, passData);
    result = PyEval_CallObject(passFunc, arglist);

    return Py_BuildValue("O", result);
}

