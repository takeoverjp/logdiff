add_subdirectory(googletest)

add_executable(test_comparator test_comparator.cpp)
target_link_libraries(test_comparator gtest gtest_main)
include_directories(
  ../
  ../dtl
  ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)

add_test(
  NAME comparator
  COMMAND test_comparator)

add_test(
  NAME logdiff
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/run_tests.sh ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
