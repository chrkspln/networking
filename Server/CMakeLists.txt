# CMakeList.txt : CMake project for Server, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Server)
target_sources (Server PRIVATE "Server.cpp" "Server.h")
target_link_libraries (Server PRIVATE Sockets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Server PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
