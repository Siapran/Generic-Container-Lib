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

#define TYPE int
#include "gcl/list.h"
#include "gcl/list.def"
#undef TYPE

#endif