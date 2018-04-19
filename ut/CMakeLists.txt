include_directories("${gtest_root}/googletest/include/" 
                     "../src/template/" 
                     "../src/exercise/")
link_directories(${CMAKE_SOURCE_DIR}/build/)
add_executable(gtest_main.out TestMain.cpp TestTemplate.cpp TestExercise.cpp)

target_link_libraries (gtest_main.out
                          "libgtest.a"
                          "pthread" 
                          "template" 
                          "exercise")