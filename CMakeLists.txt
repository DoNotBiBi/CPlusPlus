project(CPlusPlus)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. DIRSRCS)



# add_subdirectory(NewLib)
add_executable(CPlusPlus  ${DIRSRCS} )


set(CMAKE_CXX_STANDARD 14)
# target_link_libraries(CPlusPlus NewLib)