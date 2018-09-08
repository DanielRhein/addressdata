add_library(Address Address.cpp)

add_library(Commandline Commandline.cpp)
add_library(AddressdatenParameter AddressdatenParameter.cpp)

#set(ADITIONALSOURCES ${PROJECT_SOURCE_DIR}/libs/Address.h 
#				     ${PROJECT_SOURCE_DIR}/libs/Commandline.h
#					 ${PROJECT_SOURCE_DIR}/libs/AddressdatenParameter.h)
#include_directories ("${PROJECT_SOURCE_DIR}/libs/Address")
#include_directories ("${PROJECT_SOURCE_DIR}/libs/Commandline")
#add_library(CommandlineProgramm AddressdatenCMDL.cpp ${ADITIONALSOURCES})
#target_link_libraries(CommandlineProgramm Address Commandline)
#target_link_libraries(CommandlineProgramm Address Commandline)


install (TARGETS Address DESTINATION bin)
install (FILES Address.h DESTINATION include)
install (TARGETS Commandline DESTINATION bin)
install (FILES Commandline.h DESTINATION include)
#install (TARGETS CommandlineProgramm DESTINATION bin)
#install (FILES AddressdatenParameter.h AddressdatenCMDL.h DESTINATION include)
