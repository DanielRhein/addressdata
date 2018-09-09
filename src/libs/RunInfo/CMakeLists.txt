cmake_minimum_required (VERSION 3.12)

file(STRINGS "runinfo" RUNINFO)

string(REPLACE ";" "" RUNINFO ${RUNINFO})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "RunInfo.h.in"
  "RunInfo.h"
  )
configure_file (
  "RunInfo.cpp.in"
  "RunInfo.cpp"
  )  
  

add_library(RunInfo RunInfo.cpp)

install (TARGETS RunInfo DESTINATION bin)
install (FILES RunInfo.h DESTINATION include)
