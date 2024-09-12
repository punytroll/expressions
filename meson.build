project(
  'expressions',
  'cpp',
  version: '0.7.0',
  meson_version: '>=1.4.0',
  default_options: [
    'cpp_std=c++20',
    'warning_level=3',
    'werror=true'
  ]
)

expressions_library_sources = files(
  'source/addition_term.cpp',
  'source/constant_term.cpp',
  'source/division_term.cpp',
  'source/expression.cpp',
  'source/multiplication_term.cpp',
  'source/negation_term.cpp',
  'source/operators.cpp',
  'source/subtraction_term.cpp',
  'source/term.cpp',
  'source/term_parent.cpp',
  'source/variable.cpp',
  'source/variable_term.cpp'
)

expressions_library = library(
  'expressions',
  sources: expressions_library_sources,
  include_directories: 
    include_directories('include')
)

expressions_library_dependency = declare_dependency(
  include_directories: include_directories('include'),
  link_with: [
    expressions_library
  ]
)
