set source=%~dp0

set build_dir=build\file_reading

cd ..\..
mkdir %build_dir%
cd %build_dir%

REM conan install "%source%\" --build=outdated -s build_type=Debug -s arch=x86_64
conan install "%source%\" --build=outdated -s arch=x86_64

copy %source%\test.txt .\

cd %source%
premake5 vs2019 --location="../../%build_dir%/"
