cmake_minimum_required (VERSION 3.12)
project (addressdaten VERSION 1.0.0 LANGUAGES CXX)##

# add the libraries
 include_directories (libs/Address libs/Commandline libs/AddressParameter libs/RunInfo libs/Banner)
 add_subdirectory (libs/Address)
 add_subdirectory (libs/Commandline)
 add_subdirectory (libs/AddressParameter)
 add_subdirectory (libs/RunInfo)
 add_subdirectory (libs/Banner)
 
 #Address-libs
 set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/Address/Address.h )
  set (EXTRA_LIBS ${EXTRA_LIBS} Address)
#Commandline-libs
set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/Commandline/Commandline.h)
  set (EXTRA_LIBS ${EXTRA_LIBS} Commandline)
#AddressParameter-libs
set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/AddressParameter/AddressdatenParameter.h)
  set (EXTRA_LIBS ${EXTRA_LIBS} AddressdatenParameter)
#RunInfo-libs
set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/RunInfo/RunInfo.h)
set (EXTRA_LIBS ${EXTRA_LIBS} RunInfo)
#Banner-libs
set(HEADER_FILES ${HEADER_FILES} ${PROJECT_SOURCE_DIR}/libs/Banner/Banner.h)
set (EXTRA_LIBS ${EXTRA_LIBS} Banner)
					
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
