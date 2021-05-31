cmake_minimum_required(VERSION 3.16,3)
project(RGZ)

set(CMAKE_CXX_STANDARD 14)

add_executable(RGZ_TournamentSort TournamentSort.cpp)
add_executable(RGZ_TreeSorting TreeSorting.cpp)
add_executable(RGZ_PyramidSort PyramidSort.cpp)
add_executable(RGZ_QuickSort QuickSort.cpp)
add_executable(RGZ_SortByPairMergers SortByPairMergers.cpp)