#include "example.h"

#include <pybind11/pybind11.h>
#include "pybind11_abseil/status_casters.h"

PYBIND11_MODULE(example_bindings, m) {
  // Import the pybind11_abseil status casters to automatically convert absl::Status.
  pybind11::google::ImportStatusModule();
  m.def("example", &example, "A function that might return a NOT_FOUND error.");
}
