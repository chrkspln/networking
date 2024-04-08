# CMakeList.txt : CMake project for Sockets, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Client)
target_sources (Client PRIVATE "Client.cpp" "Client.h")
target_link_libraries (Client PRIVATE Sockets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Client PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
