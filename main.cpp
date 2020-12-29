#include <Python.h>
#include <iostream>
#include "Dummy.h"

using std::endl;
using std::cerr;

int main(int argc, char **argv) {
    wchar_t *program = Py_DecodeLocale(argv[0], nullptr);

    PyImport_AppendInittab("dummy", PyInit_dummy);

    Py_SetProgramName(program);

    Py_Initialize();

    PyObject *module = PyImport_ImportModule("test2");
    cout << "module is " << ((nullptr != module) ? "not " : "") << "null" << endl;

    PyObject *testerCtor = PyObject_GetAttrString(module, "Tester");
    cout << "testerCtor is " << ((nullptr != testerCtor) ? "not " : "") << "null" << endl;
    cout << "PyCallable_Check(testerCtor) = " << PyCallable_Check(testerCtor) << endl;

    PyObject *testerInstance = _PyObject_CallNoArg(testerCtor);
    cout << "testerInstance is " << ((nullptr != testerInstance) ? "not " : "") << "null" << endl;
    cout << "testerInstance is a \"" << Py_TYPE(testerInstance)->tp_name << "\"" << endl;

    PyObject *testerA = PyObject_GetAttrString(testerInstance, "a");
    cout << ((nullptr != testerA) ? "tester instance has an \"a\" attribute" : "no \"a\" was found") << endl;
    cout << "tester.a is a \"" << Py_TYPE(testerA)->tp_name << "\"" << endl;
    cout << "tester.a = " << PyLong_AsLong(testerA) << endl;

    PyObject *testerB = PyObject_GetAttrString(testerInstance, "b");
    cout << ((nullptr != testerB) ? "tester instance has an \"b\" attribute" : "no \"b\" was found") << endl;
    cout << "tester.b is a \"" << Py_TYPE(testerB)->tp_name << "\"" << endl;
    cout << "tester.b = " << PyLong_AsLong(testerB) << endl;

    PyObject *testerC = PyObject_GetAttrString(testerInstance, "c");
    cout << ((nullptr != testerC) ? "tester instance has an \"c\" attribute" : "no \"c\" was found") << endl;
    cout << "tester.c is a \"" << Py_TYPE(testerC)->tp_name << "\"" << endl;
    cout << "tester.c = \"" << PyUnicode_AsUTF8(testerC) << "\"" << endl;

    PyObject *testerTotal = PyObject_GetAttrString(testerInstance, "total");
    cout << ((nullptr != testerTotal) ? "tester instance has a \"total\" attribute" : "no \"total\" was found") << endl;
    cout << "tester.total is a \"" << Py_TYPE(testerTotal)->tp_name << "\"" << endl;
    cout << "PyCallable_Check(testerTotal) = " << PyCallable_Check(testerTotal) << endl;

    PyObject *testerTotalRet = _PyObject_CallNoArg(testerTotal);
    cout << "the return from testerTotal() is " << ((nullptr != testerTotalRet) ? "not " : "") << "null" << endl;
    cout << "testerTotalRet is a " << Py_TYPE(testerTotalRet)->tp_name << endl;
    cout << "testerTotalRet = " << PyLong_AsLong(testerTotalRet) << endl;

    Py_Finalize();

    return 0;
}
