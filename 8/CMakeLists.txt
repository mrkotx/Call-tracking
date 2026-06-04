# CMakeList.txt : CMake project for 8, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (8 "MyClass.cpp" "MyClass.h" "Main.cpp" "Structures.h" "MassA.h" "MassA.cpp" "MassB.h" "MassB.cpp" "SortVar.h" "SortVar.cpp" "Operators.h" "Operators.cpp" "Structures.cpp"			)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 8 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
