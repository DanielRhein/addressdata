cmake_minimum_required (VERSION 3.12)

file(STRINGS "banner" BANNER)
file(STRINGS "banner_flower_power" BANNERFLOWERPOWER)
file(STRINGS "bannersimple" BANNERSIMPLE)

string(REPLACE " " " " BANNER ${BANNER})
string(REPLACE " " " " BANNERFLOWERPOWER ${BANNERFLOWERPOWER})
string(REPLACE " " " " BANNERSIMPLE ${BANNERSIMPLE})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "Banner.h.in"
  "Banner.h"
  )
configure_file (
  "Banner.cpp.in"
  "Banner.cpp"
  )  
  

add_library(Banner Banner.cpp)

install (TARGETS Banner DESTINATION bin)
install (FILES Banner.h DESTINATION include)
