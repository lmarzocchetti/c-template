project('c-template', 'c', default_options: ['c_std=c17', 'warning_level=2'], version : '0.1.0')

fs = import('fs')
cmake = import('cmake')

c = meson.get_compiler('c')
# add_project_arguments('-Wall', language : 'c')

# STC
stc_proj = subproject('stc')

# MiMalloc
mimalloc_proj = cmake.subproject('mimalloc')
mimalloc_lib = mimalloc_proj.dependency('mimalloc')

# Raylib
raylib_proj = cmake.subproject('raylib')
raylib_lib = raylib_proj.dependency('raylib')

# Datatype99
datatype99_proj = cmake.subproject('datatype99')
datatype99_lib = datatype99_proj.dependency('datatype99')

# Interface99
interface99_proj = cmake.subproject('interface99')
interface99_lib = interface99_proj.dependency('interface99')

# CException
cexception_proj = subproject('cexception')

# SDS
sds_repo_dir = meson.project_source_root() / 'external' / 'sds'
if not fs.exists(sds_repo_dir)
  run_command('git', 'clone', 'https://github.com/antirez/sds', sds_repo_dir)
endif
sds_repo_inc = './external/sds'
sds_repo_sources = files(
  sds_repo_dir / 'sds.c'
)

main_source = files('main.c')

sources = main_source + sds_repo_sources

executable(
  'c-template',
  sources,
  dependencies : [stc_proj.get_variable('stc_dep'), mimalloc_lib], #, raylib_proj.get_variable('raylib_dep'), datatype99_proj.get_variable('datatype99_dep'), interface99_proj.get_variable('interface99_dep'), cexception_proj.get_variable('cexception_dep')],
  include_directories: include_directories(sds_repo_inc)
)
