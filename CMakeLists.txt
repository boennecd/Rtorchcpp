cmake_minimum_required(VERSION 2.8.7)
project(RcppTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(R REQUIRED)
message(STATUS "R libraries: ${R_LIBRARIES}")
message(STATUS "R include dirs: ${R_INCLUDE_DIR} ${Rcpp_INCLUDE_DIR} ${testthat_INCLUDE_DIR}")

add_library(cpptorch SHARED src/addition.cpp src/hello-world.cpp src/RcppExports.cpp src/test-example.cpp src/test-runner.cpp)
include_directories(cpptorch ${R_INCLUDE_DIR} ${Rcpp_INCLUDE_DIR} ${testthat_INCLUDE_DIR})
target_link_libraries(cpptorch ${R_LIBRARIES})

install(TARGETS cpptorch DESTINATION lib)
