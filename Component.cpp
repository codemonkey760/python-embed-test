#include "Component.h"

typedef struct {
    PyObject_HEAD
} ComponentObject;

static void Component_dealloc(ComponentObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject * Component_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    return type->tp_alloc(type, 0);
}

static int Component_init(ComponentObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}

static PyMemberDef Component_members[] = {
        {nullptr}
};

static void Component_start(ComponentObject *self, PyObject *Py_UNUSED(ignored))
{
    cout << "Component Start called from c++" << endl;
}

static void Component_update(ComponentObject *self, PyObject *args)
{
    double deltaTime = 0.0;
    PyArg_ParseTuple(args, "d", &deltaTime);

    cout << "Component Update called from c++ with " << deltaTime << endl;
}

static void Component_render(ComponentObject *self, PyObject *Py_UNUSED(ignored))
{
    cout << "Component Render called from c++" << endl;
}

static void Component_end(ComponentObject *self, PyObject *Py_UNUSED(ignored))
{
    cout << "Component End called from c++" << endl;
}

static PyMethodDef Component_methods[] = {
        {"start", (PyCFunction) Component_start, METH_NOARGS, "Start event handler"},
        {"update", (PyCFunction) Component_update, METH_VARARGS, "Update event handler"},
        {"render", (PyCFunction) Component_render, METH_NOARGS, "Render event handler"},
        {"end", (PyCFunction) Component_end, METH_NOARGS, "End event handler"},
        {nullptr}
};

static PyTypeObject ComponentType = {
        PyVarObject_HEAD_INIT(nullptr, 0)
        "component.Component",
        sizeof(ComponentObject),
        0,
        (destructor) Component_dealloc,
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
        "Component Objects",
        0,
        0,
        0,
        0,
        0,
        0,
        Component_methods,
        Component_members,
        0,
        0,
        0,
        0,
        0,
        0,
        (initproc) Component_init,
        0,
        Component_new,
};

static PyModuleDef component_module = {
        PyModuleDef_HEAD_INIT,
        "Module for the Component class",
        nullptr,
        -1,
};

PyMODINIT_FUNC PyInit_Component()
{
    PyObject *module = nullptr;
    if (PyType_Ready(&ComponentType) < 0) {
        return nullptr;
    }

    module = PyModule_Create(&component_module);
    if (module == nullptr) {
        return nullptr;
    }

    Py_INCREF(&ComponentType);
    if (PyModule_AddObject(module, "Component", (PyObject *) &ComponentType) < 0) {
        Py_DECREF(&ComponentType);
        Py_DECREF(module);

        return nullptr;
    }

    return module;
}