#include <Python.h>
#include <iostream>
#include "Component.h"

using std::endl;
using std::cerr;

int main(int argc, char **argv) {
    wchar_t *program = Py_DecodeLocale(argv[0], nullptr);

    PyImport_AppendInittab("component", PyInit_Component);

    Py_SetProgramName(program);

    Py_Initialize();

    PyObject *testComponentModule = PyImport_ImportModule("testComponent");
    PyObject *testComponentType = PyObject_GetAttrString(testComponentModule, "TestComponent");
    PyObject *testComponent = _PyObject_CallNoArg(testComponentType);

    PyObject *startHandler = PyObject_GetAttrString(testComponent, "start");
    PyObject *updateHandler = PyObject_GetAttrString(testComponent, "update");
    PyObject *renderHandler = PyObject_GetAttrString(testComponent, "render");
    PyObject *endHandler = PyObject_GetAttrString(testComponent, "end");

    _PyObject_CallNoArg(startHandler);

    PyObject *updateArgs = PyTuple_New(1);
    PyTuple_SetItem(updateArgs, 0, PyFloat_FromDouble(2.2));
    PyObject_Call(updateHandler, updateArgs, PyDict_New());

    _PyObject_CallNoArg(renderHandler);

    _PyObject_CallNoArg(endHandler);

    Py_Finalize();

    return 0;
}
