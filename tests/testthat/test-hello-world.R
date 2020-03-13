test_that("Says hello", {
  expect_output(hello_world(), "^Hello world$")
})
