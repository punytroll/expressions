/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__COMMON_H
#define EXPRESSIONS__SURCE__COMMON_H

#include <iostream>
#include <print>

#if defined(TRACE_LOGGING)
#define LOG_TRACE(A) { try { std::println(std::cerr, (A)); } catch(...) { } }
#else
#define LOG_TRACE(A)
#endif

#endif
