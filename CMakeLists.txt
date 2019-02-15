cmake_minimum_required(VERSION 3.5)

add_executable(logdiff logdiff.cpp)
include_directories(dtl)

install(TARGETS logdiff
  RUNTIME
  DESTINATION bin)

enable_testing()
add_subdirectory(tests)
