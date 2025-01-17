load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")
load("@rules_python//python:defs.bzl", "py_test")

package(default_visibility = [
    "//visibility:public",
])

cc_library(
    name = "example",
    srcs = ["example.cc"],
    hdrs = ["example.h"],
    deps = [
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
    ],
)

pybind_extension(
    name = "example_bindings",
    srcs = ["example_bindings.cc"],
    deps = [
        ":example",
        "@pybind11_abseil//pybind11_abseil:status_casters",
    ],
)

py_test(
    name = "example_test",
    srcs = ["example_test.py"],
    imports = ["."],
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":example_bindings",
        "@pybind11_abseil//pybind11_abseil:import_status_module",
    ],
)
