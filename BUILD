# ==============================================================================
# file: BUILD
# This is the final, corrected BUILD file. It correctly uses the advanced
# filtering mechanism of pywrap_library to create a dedicated common shared
# library for the abseil status casters. This is the definitive solution to
# resolve both the internal build errors and the runtime ODR violation.
# ==============================================================================

load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_python//python:defs.bzl", "py_test")
load("//rules_pywrap:pywrap.impl.bzl", "python_extension", "pywrap_library")

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

# STEP 1: Define a "filter" library.
# This cc_library exists for the sole purpose of capturing the problematic
# dependency. The pywrap_library rule will use this target as a key to
# identify exactly which linker inputs must be forced into a dedicated
# common library.
cc_library(
    name = "absl_status_filter_lib",
    deps = ["@pybind11_abseil//pybind11_abseil:status_casters"],
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

python_extension(
    name = "example_bindings",
    srcs = ["example_bindings.cc"],
    deps = [
        ":example",
        # The dependency must still be listed here for the code to compile,
        # but the linking is now precisely controlled by the pywrap_library.
        "@pybind11_abseil//pybind11_abseil:status_casters",
    ],
)

# STEP 2: Use the filter to create a DEDICATED common library.
pywrap_library(
    name = "wrapped_bindings",
    common_lib_filters = {
        "pybind_absl_common": ":absl_status_filter_lib",
    },
    deps = [":example_bindings"],
)

py_test(
    name = "example_test",
    srcs = ["example_test.py"],
    imports = ["."],
    python_version = "PY3",
    srcs_version = "PY3",
    deps = [
        ":wrapped_bindings",
        "@pybind11_abseil//pybind11_abseil:import_status_module",
    ],
)
