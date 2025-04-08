# c-template
Simple Meson template for C projects 

# Already included libraries
I have created this template to provide at least a minimal set of functionality to the C language.
These libraries are included (and easily swappable or removable):
- STC: My favourite container library, not so big like GLib but definitely not a minimalistic option
- sds: Simple library to support dynamic strings
- mimalloc: Replacement to standard malloc. I have set this to NOT replace the standard malloc, but simply import and use it
- raylib: Fairly simple OpenGL library for 2d/3d game development or graphics
- Interface99: Macro library to have static and dynamic interfaces in C
- Datatype99: Macro library to have sum types in C
- CException: Library that implement a simple Exception mechanism (setjmp/longjmp)

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

Set the project name in the meson.build file:
```
project('c-template', 'c', default_options: ['c_std=c17', 'warning_level=2'], version : '0.1.0') -> project('your-project-name', 'c', default_options: ['c_std=c17', 'warning_level=2'], version : '0.1.0')
```

## Build and Run
You can use normal Meson commands or use my script `run.sh` to build and run your project!

### With Configuration
Use conf to configure your meson project (in release or debug mode): 
```
$ ./run.sh conf [release|debug]
```

Use conf-build to configure and build the final executable
```
$ ./run.sh conf-build [release|debug]
```

Use conf-run to configure, build and run the final executable
```
$ ./run.sh conf-run [release|debug]
```

### Without Configuration
If you already run the configuration step of cmake and want only to build or run the executable:
```
$ ./run.sh build [release|debug]
```

```
$ ./run.sh run [release|debug]
```

# Credit
STC: https://github.com/stclib/STC \
mimalloc: https://github.com/microsoft/mimalloc \
sds: https://github.com/antirez/sds \
CException: https://github.com/ThrowTheSwitch/CException \
Raylib: https://github.com/raysan5/raylib \
Datatype99: https://github.com/Hirrolot/datatype99 \
Interface99: https://github.com/hirrolot/interface99
