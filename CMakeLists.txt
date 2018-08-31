cmake_minimum_required (VERSION 3.12)
project (addressdaten VERSION 1.0.0 LANGUAGES CXX)##

add_executable(addressdaten Commandline.cpp AddressdatenCMDL.cpp Addressdaten.cpp Address.cpp)
target_compile_features(addressdaten PRIVATE cxx_std_17)
target_compile_options(addressdaten PRIVATE -Werror)
