# CMakeList.txt : CMake project for Sockets, include source and define
# project specific logic here.
#

add_library (Sockets STATIC "Sockets.cpp" "Sockets.h")
target_include_directories (Sockets PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sockets PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
