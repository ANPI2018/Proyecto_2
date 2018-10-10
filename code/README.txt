-----------------------------------------------
              COMPILATION
-----------------------------------------------

Create a directory build:

> mkdir build;

Go into that directory

> cd build;

You can choose to build a release version with:

> cmake ../ -DCMAKE_BUILD_TYPE=Release

or a debug version with

> cmake ../ -DCMAKE_BUILD_TYPE=Debug

And build everything with

> make


-----------------------------------------------
           EXECUTION OF BENCHMARKS
-----------------------------------------------

Go to the directory "bin" created in build
after the compilation

> cd build/bin/

To see the available benchmarks

> ./benchmark --list_content

To execute all benchmarks (add and sub)

> ./benchmark

To execute only benchmark

> ./benchmark --run_test=Matrix/<name>

Example:
       > ./benchmark --run_test=Matrix/Sub
