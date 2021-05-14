# Celero-Template
Premake script for setting up a Celero benchmark project

## Usage
Copy the template as a base for your new project.
Pass the project name and Celero's include and lib paths as command line arguments to premake, or set them manually in the script.

For example:
```
premake5 vs2015 --name=Example --celero-include=C:/Celero/Celero/include --celero-lib=C:/Celero/Build/Release/celero.lib --celero-lib-d=C:/Celero/Build/Debug/celerod.lib
```