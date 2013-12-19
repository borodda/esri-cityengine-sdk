/*
  COPYRIGHT (c) 2013 ESRI
  TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
  Unpublished material - all rights reserved under the
  Copyright Laws of the United States and applicable international
  laws, treaties, and conventions.

  For additional information, contact:
  Environmental Systems Research Institute, Inc.
  Attn: Contracts and Legal Services Department
  380 New York Street
  Redlands, California, 92373
  USA

  email: contracts@esri.com
*/

#ifndef PRT_STDINT_H_
#define PRT_STDINT_H_

#include <cstddef>

#if !defined(_WIN32)
#	include <stdint.h>
#elif _MSC_VER >= 1600 // VC 10
#	include <cstdint>
#else


/* **************
 * stdint.h, hacked to work on _WIN32 as well as win64
 *
 */

#ifndef __LIB_STDINT_H
#define __LIB_STDINT_H

typedef signed char int8_t;
#define INT8_MAX 127
#define INT8_MIN (-INT8_MAX - 1)

typedef signed short int int16_t;
#define INT16_MAX 32767
#define INT16_MIN (-INT16_MAX - 1)

typedef signed int int32_t;
#define INT32_MAX 2147483647
#define INT32_MIN (-INT32_MAX - 1)

typedef signed long long int int64_t;
#define INT64_MAX 9223372036854775807LL
#define INT64_MIN (-INT64_MAX - 1)

typedef unsigned char uint8_t;
#define UINT8_MAX 255

typedef unsigned short int uint16_t;
#define UINT16_MAX 65535

typedef unsigned int uint32_t;
#define UINT32_MAX 4294967295U

typedef unsigned long long int uint64_t;
#define UINT64_MAX 18446744073709551615ULL

#ifdef _WIN64
	typedef int64_t intptr_t;
	#define INTPTR_MIN INT64_MIN
	#define INTPTR_MAX INT64_MAX
#else
	typedef int32_t intptr_t;
	#define INTPTR_MIN INT32_MIN
	#define INTPTR_MAX INT32_MAX
#endif


#ifdef _WIN64
	typedef uint64_t uintptr_t;
	#define UINTPTR_MAX UINT64_MAX
#else
	typedef uint32_t uintptr_t;
	#define UINTPTR_MAX UINT32_MAX
#endif

typedef int64_t intmax_t;
#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX

typedef uint64_t uintmax_t;
#define UINTMAX_MAX UINT64_MAX

#define PTRDIFF_MIN INT32_MIN
#define PTRDIFF_MAX INT32_MAX

#endif /* lib/stdint.h */

#endif // ifdef _WIN32

#endif // PRT_STDINT_H_

