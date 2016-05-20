#include <string>
#include <map>
#include <list>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

int add(int i, int j)
{
    return i + j;
}


// Alternative for typedef
using MiMap = std::map<int, std::string>;

MiMap map_from_lists(const std::list<int> &keys, const std::list<std::string> &values)
{
    MiMap res, foo;
    auto key = keys.begin();
    auto value = values.begin();

    for ( ; key != keys.end() and value != values.end(); ++key, ++value )
        res[*key] = *value;

    return res;
}


class Pet {
public:
    Pet(const std::string &name) : name{name} { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const { return name; }

private:
    std::string name;
};


namespace py = pybind11;

PYBIND11_PLUGIN(example) {
    py::module m("example", "pybind11 example plugin");

    m.def("add", &add, "A function which adds two numbers");
    m.def("map_from_lists", &map_from_lists, "Create a dict from two lists");

    py::class_<Pet>(m, "Pet", "Class to manage Pets")
            .def(py::init<const std::string &>())
            .def("setName", &Pet::setName)
            .def("getName", &Pet::getName)
            .def_property("name", &Pet::getName, &Pet::setName);

    return m.ptr();
}

// Compile with
// g++ -fvisibility=hidden -s -fPIC -O3 -shared -std=c++14 `python-config --cflags --ldflags`
// example_pybind11.cpp -o example.so
// or with clang
// clang++ -fvisibility=hidden -s -fPIC -O3 -shared -std=c++14 `python-config --cflags --ldflags`
// example_pybind11.cpp -o example.so

