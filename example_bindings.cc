#include "example.h"

#include "pybind11_abseil/status_casters.h"
#include <iostream> // For std::cout
#include <pybind11/pybind11.h>

PYBIND11_MODULE(example_bindings, m) {
  std::cout << "Attempting to import Abseil status module for pybind11..."
            << std::endl;
  try {
    pybind11::google::ImportStatusModule();
    std::cout << "Successfully imported Abseil status module." << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception during ImportStatusModule: " << e.what()
              << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception during ImportStatusModule." << std::endl;
  }
  m.def("example", &example, "A function that might return a NOT_FOUND error.");
}