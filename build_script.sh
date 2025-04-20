cmake -S Testsuite/googletest/ -B Testsuite/_build/ -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DGOOGLETEST_VERSION=1.16.0 -DCMAKE_BUILD_TYPE=Debug
cd Testsuite/_build
make