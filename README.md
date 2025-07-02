**pybind11_abseil returns `RuntimeError` instead of `status.StatusNotOk` in a hermetic C++ setup.**

### Requirements:
- [bazelisk](https://github.com/bazelbuild/bazelisk) preinstalled 
- Linux (maybe possible to add support for Mac/Windows if needed but I haven't tried).

To reproduce:
```
bazel test :example_test
```

### Error
You'll see an output like this:
```
Traceback (most recent call last):
  File "$HOME/.cache/bazel/_bazel_udayaprakash/a4f0aca6c3283bb76d23d9bece3c63ef/sandbox/linux-sandbox/502/execroot/_main/bazel-out/k8-fastbuild/bin/example_test.runfiles/_main/example_test.py", line 14, in test_example_not_found
    self.fail("Unknown Exception: type: {}, exception: {}".format(type(e), str(e)))
AssertionError: Unknown Exception: type: <class 'RuntimeError'>, exception: Caught an unknown exception!
```

### Attempt to fix this using rules_pywrap
