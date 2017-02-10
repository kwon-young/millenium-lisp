
cmake_minimum_required(VERSION 2.6)

# Appends the cmake/modules path to MAKE_MODULE_PATH variable.
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

# Project declaration
project(millenium-lisp)

#
# Make a version file containing the current version from git.
#
include(GetGitRevisionDescription)
git_describe(VERSION --tags)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1 "${VERSION}")
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/version.c.in
                ${CMAKE_CURRENT_BINARY_DIR}/version.c)
set(version_file "${CMAKE_CURRENT_BINARY_DIR}/version.c")

# Adding project include directory
include_directories(include)

# Generate list of source file
file(
  GLOB_RECURSE
  source_files
  src/*
  )

file(
  GLOB_RECURSE
  header_files
  include/*
  )

# Executable declaration
add_executable(
  mlisp
  ${source_files}
  ${header_files}
  ${version_file}
  )
