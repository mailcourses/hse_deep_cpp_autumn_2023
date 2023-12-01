#include <stdio.h>
#include <stdlib.h>

#include <Python.h>

static PyObject* cutils_mult(PyObject* self, PyObject* args)
{
    PyObject* py_lst;
    int koef;
    if (!PyArg_ParseTuple(args, "Oi", &py_lst, &koef))
    {
        printf("Failed to parse arguments");
        return NULL;
    }
    int lst_len = PyList_Size(py_lst);
    int res = 0;
    for (int i = 0; i < lst_len; ++i)
    {
        PyObject* tmp = PyList_GetItem(py_lst, i);
        res += PyLong_AsLong(tmp) * koef;
    }
    return Py_BuildValue("i", res);
}

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

PyObject* cutils_fibonacci(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n))
    {
        return NULL;
    }
    int res = fibonacci(n);
    return Py_BuildValue("i", res);
}

struct PyMethodDef cutils_method_def[] = {
    {"mult", cutils_mult, METH_VARARGS, "Iterate over array and return sum."},
    {"fibonacci", cutils_fibonacci, METH_VARARGS, "Get ith element of fibonacci sequence."},
    {NULL, NULL, 0, NULL}
};

struct PyModuleDef cutils_module_def = {
    PyModuleDef_HEAD_INIT,
    "cutils",
    "Module provides useful functions",
    -1,
    cutils_method_def
};

PyMODINIT_FUNC PyInit_cutils(void)
{
    Py_Initialize();
    return PyModule_Create(&cutils_module_def);
}
