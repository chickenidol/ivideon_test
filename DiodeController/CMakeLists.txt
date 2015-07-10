project(diodecontroller)

add_executable(diodecontroller tools.cpp commandresult.cpp commandmanager.cpp commutator.cpp diode.cpp main.cpp)

install(TARGETS diodecontroller RUNTIME DESTINATION bin)

add_subdirectory(command)

include_directories(.)
