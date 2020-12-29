#ifndef PYTHON_EMBED_TEST_COMPONENT_H
#define PYTHON_EMBED_TEST_COMPONENT_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

#include <iostream>

using std::cout;
using std::endl;

PyMODINIT_FUNC PyInit_Component();

#endif //PYTHON_EMBED_TEST_COMPONENT_H
