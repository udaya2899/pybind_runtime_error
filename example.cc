#include "example.h"

#include "absl/log/log.h"
#include "absl/status/status.h"
#include "absl/strings/str_cat.h"

absl::Status example() {
  LOG(INFO) << "This is an info log from my_function.";
  bool resource_found = false;
  if (!resource_found) {
    return absl::NotFoundError(absl::StrCat("Resource not found."));
  }

  return absl::OkStatus();
}
