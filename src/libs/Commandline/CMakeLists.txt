add_library(Commandline Commandline.cpp)

install (TARGETS Commandline DESTINATION bin)
install (FILES Commandline.h DESTINATION include)
