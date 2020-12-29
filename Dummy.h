#ifndef UNTITLED_DUMMY_H
#define UNTITLED_DUMMY_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

PyMODINIT_FUNC PyInit_dummy();

#endif //UNTITLED_DUMMY_H
