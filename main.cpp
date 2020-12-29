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
    PyObject *testerType = PyObject_GetAttrString(module, "Tester");

    if (nullptr == testerType) {
        cerr << "Could not locate constructor" << endl;

        Py_Finalize();

        exit(1);
    }
    cout << "Constructor located" << endl;

    PyObject *testerInstance = PyType_GenericNew((PyTypeObject *) testerType, nullptr, nullptr);

    cout << ((nullptr == testerInstance) ? "Instance is null" : "Instance is not null") << endl;

    PyObject *testerA = PyObject_GetAttrString(testerInstance, "a");
    cout << ((nullptr == testerA) ? "tester instance has an \"a\" attribute" : "no \"a\" was found");

    cout << "tester.a = " << PyLong_AsLong(testerA) << endl;

//    char const *file_name = "test.py";
//
//    FILE *fp = fopen(file_name, "r");
//    PyRun_AnyFile(fp, file_name);
//    fclose(fp);
//    fp = nullptr;

    Py_Finalize();

    return 0;
}
