# c-template
Simple CMake template for C projects using CPM 

# Already included libraries
I have created this template to provide at least a minimal set of functionality to the C language.
These libraries are included (and easily swappable or removable):
- STC: My favourite container library, not so big like GLib but definitely not a minimalistic option
- sds: Simple library to support dynamic strings
- mimalloc: Replacement to standard malloc. I have set this to NOT replace the standard malloc, but simply import and use it
- raylib: Fairly simple OpenGL library for 2d/3d game development or graphics
- GLib: Container (and much more) library. (Use if you need more abstraction like Objects, Async, etc)
- Interface99: Macro library to have static and dynamic interfaces in C
- Datatype99: Macro library to have sum types in C

For now these are the only included libraries, but it can change in the future (suggestions are appreciated)

Default Active Libraries -> STC, sds

# Usage
## Setup
First of all clone the template:
```
$ git clone https://github.com/lmarzocchetti/c-template
```

Rename the folder with your project name:
```
$ mv c-template your-project-name
```

Set the project name in the CMakeLists.txt file:
```
project(c-template C) -> project(your-project-name C)
```

## Build and Run
You can use normal CMake commands or use my script `run.sh` to build and run your project!

### With Configuration
Use conf to configure your cmake project (in Release or Debug mode): 
```
$ ./run.sh conf [Release|Debug]
```

Use conf-build to configure and build the final executable
```
$ ./run.sh conf-build [Release|Debug]
```

Use conf-run to configure, build and run the final executable
```
$ ./run.sh conf-run [Release|Debug]
```

### Without Configuration
If you already run the configuration step of cmake and want only to build or run the executable:
```
$ ./run.sh build
```

```
$ ./run.sh run
```

# Credit
STC: https://github.com/stclib/STC \
mimalloc: https://github.com/microsoft/mimalloc \
sds: https://github.com/antirez/sds
