#ifndef GCL_H
#define GCL_H

typedef const char* str;

#define TYPE str
#include "gcl/vector.h"
#include "gcl/vector.def"
#undef TYPE

#define KEY_TYPE str
#define VALUE_TYPE int
#include "gcl/map.h"
#include "gcl/map.def"
#undef KEY_TYPE
#undef VALUE_TYPE

/* a vector of ints */
/*
#define TYPE int
#include "gcl/vector.h"
#include "gcl/vector.def"
#undef TYPE
 */

/* A map of ints indexed by chars */
/*
#define KEY_TYPE char
#define VALUE_TYPE int
#include "gcl/map.h"
#include "gcl/map.def"
#undef KEY_TYPE
#undef VALUE_TYPE
 */

/* A vector of a custom structure */
/*
typedef struct my_struct {
	int foo;
	float bar;
} my_struct;

#define TYPE my_struct
#include "gcl/vector.h"
#include "gcl/vector.def"
#undef TYPE
 */

#endif