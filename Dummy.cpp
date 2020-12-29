#include "Dummy.h"

typedef struct {
    PyObject_HEAD
    double a;
    double b;
    PyObject *message;
} DummyObject;

static void Dummy_dealloc(DummyObject *self)
{
    Py_XDECREF(self->message);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject * Dummy_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    DummyObject *self;
    self = (DummyObject *) type->tp_alloc(type, 0);
    if (nullptr == self) {
        return nullptr;
    }

    self->message = PyUnicode_FromString("");
    if (nullptr == self->message) {
        Py_DECREF(self);

        return nullptr;
    }

    self->a = 0.0;
    self->b = 0.0;

    return (PyObject *) self;
}

static int Dummy_init(DummyObject *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"a", "b", "message", NULL};
    PyObject *message = nullptr, *temp;

    double a = 0.0;
    double b = 0.0;
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ddO", kwlist, &a, &b, &message)) {
        return -1;
    }
    self->a = a;
    self->b = b;

    if (message) {
        temp = self->message;
        Py_INCREF(message);
        self->message = message;
        Py_XDECREF(temp);
    }

    return 0;
}

static PyMemberDef Dummy_members[] = {
        {"a", T_DOUBLE, offsetof(DummyObject, a), 0, "The first number"},
        {"b", T_DOUBLE, offsetof(DummyObject, b), 0, "The last number"},
        {"message", T_OBJECT_EX, offsetof(DummyObject, message), 0, "The message"},
        {nullptr}
};

static PyObject * Dummy_get_string(DummyObject *self, PyObject *Py_UNUSED(ignored))
{
    if (nullptr == self->message) {
        PyErr_SetString(PyExc_AttributeError, "message");

        return nullptr;
    }

    return PyUnicode_FromFormat("message is \"%S\"", self->message);
}

static PyMethodDef Dummy_methods[] = {
        {"get_string", (PyCFunction) Dummy_get_string, METH_NOARGS, "Get a string with everything in it"},
        {nullptr},
};

static PyTypeObject DummyType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "dummy.Dummy",
    sizeof(DummyObject),
    0,
    (destructor) Dummy_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    "Dummy Objects",
    0,
    0,
    0,
    0,
    0,
    0,
    Dummy_methods,
    Dummy_members,
    0,
    0,
    0,
    0,
    0,
    0,
    (initproc) Dummy_init,
    0,
    Dummy_new,
};

static PyModuleDef dummy_module = {
        PyModuleDef_HEAD_INIT,
        "Module for the Dummy class",
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