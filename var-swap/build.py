import os
from sys import platform

source = os.path.dirname(os.path.realpath(__file__))

build_type = "Release"
build_dir = "../../build/var-swap/"

os.makedirs(build_dir, exist_ok=True)
os.chdir(build_dir)


# conan
conan_profile = ''
if platform != 'win32':
	conan_profile = ' -pr=clang'
os.system('conan install "' + source + '/" --build=outdated -s arch=x86_64 -s build_type=' + build_type + conan_profile)


compiler = ''
if platform != 'win32':
	compiler = ' --cc=clang'

def premake_generate(generator):
	command = 'premake5 ' + generator + ' --location="' + build_dir + '"' + compiler
	os.system(command)

print("AAAA")
# premake
os.chdir(source)
# choose generator based on OS
if platform == 'win32':
	premake_generate('vs2019')
else:
	premake_generate('gmake2')
	premake_generate('vscode')
