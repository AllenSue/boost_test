cmake_minimum_required (VERSION 3.5)
project (BoostTester)

set (CMAKE_CXX_STANDARD 11)

# Generate a CompilationDatabase (compile_commands.json file) for our build,
# for use by clang_complete, YouCompleteMe, etc.
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

set (BOOST_LIBS
  boost_chrono
  boost_system
  boost_thread
  )

add_executable (boost_test main.cpp)
target_link_libraries (boost_test ${BOOST_LIBS})
