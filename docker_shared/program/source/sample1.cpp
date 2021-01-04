#include<pybind11/pybind11.h>

//共有ライブラリにするので、main関数はありません。
int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(cppmod, m) {
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which adds tow numbers");
}
