#include "Dummy.h"

typedef struct {
    PyObject_HEAD
    double a;
    double b;
} DummyObject;

static PyTypeObject DummyType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    .tp_name = "dummy.Dummy",
    .tp_basicsize = sizeof(DummyObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Dummy Objects",
    .tp_new = PyType_GenericNew,
};

static PyModuleDef dummy_module = {
        PyModuleDef_HEAD_INIT,
        "dummy",
        nullptr,
        -1,
};

PyMODINIT_FUNC PyInit_dummy()
{
    PyObject *module = nullptr;
    if (PyType_Ready(&DummyType) < 0) {
        return nullptr;
    }

    module = PyModule_Create(&dummy_module);
    if (module == nullptr) {
        return nullptr;
    }

    Py_INCREF(&DummyType);
    if (PyModule_AddObject(module, "Dummy", (PyObject *) &DummyType) < 0) {
        Py_DECREF(&DummyType);
        Py_DECREF(module);

        return nullptr;
    }

    return module;
}