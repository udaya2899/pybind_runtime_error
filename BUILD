load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_python//python:defs.bzl", "py_test")
load("//rules_pywrap:pywrap.impl.bzl", "pybind_extension", "pywrap_library")

package(default_visibility = [
    "//visibility:public",
])

platform(
    name = "linux_x86_64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
    ],
)

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

pywrap_library(
    name = "example_aggregated",
    deps = [
        ":example_bindings",
    ],
)

py_test(
    name = "example_test",
    srcs = ["example_test.py"],
    imports = ["."],
    deps = [
        ":example_aggregated",
        "@pybind11_abseil//pybind11_abseil:import_status_module",
    ],
)
