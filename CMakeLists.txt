cmake_minimum_required (VERSION 3.12)
project (addressdaten VERSION 1.0.0 LANGUAGES CXX)##

# add the address data directory
 include_directories (libs)
 add_subdirectory (libs)
 set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/Address.h )
  set (EXTRA_LIBS ${EXTRA_LIBS} Address)
# add the commandline data directory

set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/Commandline.h)
  set (EXTRA_LIBS ${EXTRA_LIBS} Commandline)
# add the commandline programm directory
#set(HEADER_FILES ${HEADER_FILES} "${PROJECT_SOURCE_DIR}/libs/AddressdatenCMDL.h")
set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/AddressdatenParameter.h)
  set (EXTRA_LIBS ${EXTRA_LIBS} AddressdatenParameter)
#include_directories (${PROJECT_SOURCE_DIR}/CommandlineProgramm)
#set (EXTRA_LIBS ${EXTRA_LIBS} CommandlineProgramm)

					
message("info libs: "  ${EXTRA_LIBS})
message("info headerfiles: " ${HEADER_FILES})
					
add_executable(addressdaten Addressdaten.cpp AddressdatenCMDL.cpp ${HEADER_FILES})
target_include_directories (addressdaten PUBLIC
					"libs" ${PROJECT_SOURCE_DIR})
target_link_libraries(addressdaten ${EXTRA_LIBS})
target_compile_features(addressdaten PRIVATE cxx_std_17)
target_compile_options(addressdaten PRIVATE -Werror)

# add the install targets
install (TARGETS addressdaten DESTINATION bin)
