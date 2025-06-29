# ==============================================================================
# file: BUILD
# The updated BUILD file for your pybind_runtime_error repository that uses
# the rules_pywrap to fix the linking issues.
# ==============================================================================

load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_python//python:defs.bzl", "py_test")

# 1. Load the new rules from the `rules_pywrap` directory you added.
#    We also load the standard cc_library and py_test.
load("//rules_pywrap:pywrap.impl.bzl", "pybind_extension", "pywrap_library")

package(default_visibility = [
    "//visibility:public",
])

platform(
    name = "linux_x86_64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64",
        "@bazel_tools//tools/cpp:clang",
    ],
)

# The core cc_library with the business logic remains unchanged.
cc_library(
    name = "example",
    srcs = ["example.cc"],
    hdrs = ["example.h"],
    copts = [
        "-g",
        "-fexceptions",
        "-frtti",
    ],
    deps = [
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
    ],
)

# 2. Define the pybind extension using the new `pybind_extension` rule.
#    This rule, from `pywrap.bzl`, acts as an information provider for the
#    pywrap_library rule. It does not build a final .so file itself.
#    Note that we no longer need the manual `linkopts` or `linkstatic` attributes,
#    as the new rules handle the linking strategy correctly.
pybind_extension(
    name = "example_bindings",
    srcs = ["example_bindings.cc"],
    deps = [
        ":example",
        "@pybind11_abseil//pybind11_abseil:status_casters",
    ],
)

# 3. Use `pywrap_library` to process the extension.
#    This is the core of the fix. This rule takes the `python_extension`
#    target and orchestrates the N+1 library build, ensuring that all C++
#    code shares a single common library and avoids ODR violations.
pywrap_library(
    name = "wrapped_bindings",
    deps = [":example_bindings"],
)

# 4. Update the py_test to depend on the `pywrap_library` target.
#    This ensures the test gets the correctly built and packaged .so files
#    in its runfiles, allowing the Python interpreter to import them correctly.
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
