add_library(Address Address.cpp)

install (TARGETS Address DESTINATION bin)
install (FILES Address.h DESTINATION include)
