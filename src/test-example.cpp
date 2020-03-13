/* TODO: delete */
#include <testthat.h>
#include "addition.h"

context("Sample unit tests") {
  test_that("two plus two equals four") {
    expect_true(add(2, 2) == 4);
  }
}
