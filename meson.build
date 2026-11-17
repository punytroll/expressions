project(
  'expressions',
  'cpp',
  version: '26.11.0',
  license: 'MIT',
  license_files: ['LICENSE'],
  meson_version: '>=1.12.0',
  default_options: {
    'cpp_std': 'c++23',
    'warning_level': '3',
  },
)

expressions_library_include_directories = include_directories('include')

expressions_library_cpp_args = []

trace_logging_enabled = get_option('trace_logging').enable_auto_if(meson.is_subproject() == false).enabled()
summary({'trace logging': trace_logging_enabled}, bool_yn: true, section: 'Features')
if trace_logging_enabled == true
  expressions_library_cpp_args += '-DTRACE_LOGGING'
endif

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
  'source/variable_term.cpp',
)

expressions_library = library(
  'expressions',
  cpp_args: expressions_library_cpp_args,
  sources: expressions_library_sources,
  include_directories: expressions_library_include_directories,
)

expressions_library_dependency = declare_dependency(
  include_directories: expressions_library_include_directories,
  link_with: expressions_library,
)

meson.override_dependency('expressions', expressions_library_dependency)

enable_tests = get_option('tests').enable_auto_if(meson.is_subproject() == false).enabled()
summary({'run tests': enable_tests}, bool_yn: true, section: 'Features')
if enable_tests == true
  test(
    'expressions_test_suite',
    executable(
      'test_suite',
      build_by_default: false,
      dependencies: [expressions_library_dependency],
      sources: ['testing/test_suite.cpp'],
    ),
  )
endif
