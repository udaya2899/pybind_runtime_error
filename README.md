Requirements:
- [bazelisk](https://github.com/bazelbuild/bazelisk) preinstalled 
- Linux (maybe possible to add support for Mac/Windows if needed but I haven't tried).

To reproduce:
```
bazel test :example_test
```

The thing to note is, before adding hermetic cc toolchain setup, at commit `2f15ac`, when using the non-hermetic native toolchain of the host machine, it returned StatusNotOk as expected.

On adding a new hermetic toolchain using `uber/hermetic_cc_toolchains` at commit `f90080`, it returned `RuntimeError` instead of `status.StatusNotOk`. The same also happened even after switching to `toolchains_llvm`.


**TL;DR - pybind11_abseil returns `RuntimeError` instead of `status.StatusNotOk` in a hermetic C++ setup.**