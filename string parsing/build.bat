mkdir build
cd build

conan install ../

cd ..
premake5 vs2017 --name=string_parsing --celero-include=E:/Celero/Celero/include --celero-lib=E:/Celero/build_64/Release/celero.lib --celero-lib-d=E:/Celero/build_64/Debug/celerod.lib