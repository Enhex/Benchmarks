import os
from sys import platform

source = os.path.dirname(os.path.realpath(__file__))

build_dir = "build/multi_dispatch"
os.chdir("../..")
os.makedirs(build_dir, exist_ok=True)
os.chdir(build_dir)

# conan
os.system('conan install "' + source + '/" --build=outdated -s arch=x86_64 -s build_type=Release')

os.chdir(source)

def premake_generate(generator):
    os.system('premake5 ' + generator + ' --location="../../' + build_dir + '/"')
    
if platform == 'win32':
    premake_generate('vs2019')
else:
    premake_generate('gmake2')
    premake_generate('vscode')