if [ -z "$1" ]; then
	echo "Usage: sh $0 <cpp-file-to-be-tested>"
	exit 1
fi

# Compilation command
clang++ -std=c++17 -lstdc++ -Wall -O3 -pthread -I/mnt/d/DSA/TestSuite/googletest/include -L/mnt/d/DSA/TestSuite/_build/lib "$1" -lgtest -lgtest_main

# Check compilation
if [ $? -eq 0 ]; then
	echo "Compilation success!"
else
	echo "Compilation failed!"
fi