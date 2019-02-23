add_subdirectory(googletest)

add_executable(test_comparator test_comparator.cpp)
include_directories(
  ../
  ../dtl)

add_test(
  NAME comparator
  COMMAND test_comparator)

add_test(
  NAME logdiff
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/run_tests.sh ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
