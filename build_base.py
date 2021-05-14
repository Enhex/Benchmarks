import os
from sys import platform

def build(source, build_type='Release'):
    project_name = os.path.basename(os.path.dirname(source + "/")) # adding "/" so it will recognize the last dir as dir
    build_dir = "build/" + project_name
    os.chdir(source)
    os.chdir("../..")
    os.makedirs(build_dir, exist_ok=True)
    os.chdir(build_dir)

    build_path = os.path.realpath(os.getcwd())

    # conan
    os.system('conan install "' + source + '/" --build=outdated -s arch=x86_64 -s build_type=' + build_type)

    os.chdir(source)

    def premake_generate(generator):
        os.system('premake5 ' + generator + ' --location="../../' + build_dir + '/"')

    if platform == 'win32':
        premake_generate('vs2019')
    else:
        premake_generate('gmake2')
        premake_generate('vscode')

    return build_path