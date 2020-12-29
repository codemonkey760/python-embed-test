#include "Dummy.h"

static PyObject* dummy_print(PyObject *self, PyObject *args)
{
    char const *arg;

    if (!PyArg_ParseTuple(args, "s", &arg)) {
        return nullptr;
    }

    cout << arg << endl;

    return PyUnicode_FromString("Bye");
}

static PyMethodDef DummyMethods[] = {
        {"print", dummy_print, METH_VARARGS, "Print a string to stdout"},
        {nullptr, nullptr, 0, nullptr}
};

struct PyModuleDef dummy_module = {
        PyModuleDef_HEAD_INIT,
        "dummy",
        nullptr,
        -1,
        DummyMethods
};

PyMODINIT_FUNC PyInit_dummy() {
    return PyModule_Create(&dummy_module);
}