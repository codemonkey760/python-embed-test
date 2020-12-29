#include <Python.h>
#include "Dummy.h"

int main(int argc, char **argv) {
    wchar_t *program = Py_DecodeLocale(argv[0], nullptr);

    PyImport_AppendInittab("dummy", PyInit_dummy);

    Py_SetProgramName(program);

    Py_Initialize();

    char const *file_name = "test.py";

    FILE *fp = fopen(file_name, "r");
    PyRun_AnyFile(fp, file_name);
    fclose(fp);
    fp = nullptr;

    Py_Finalize();

    return 0;
}
