/* TODO: delete */
#include <testthat.h>
#include "addition.h"

context("Sample unit tests") {
  test_that("two plus three equals five") {
    expect_true(add(2, 3) == 5);
  }
}
