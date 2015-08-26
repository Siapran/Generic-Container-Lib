Generic-Container-Lib
=====================

A pseudo template container library in C

## Usage

Create or copy gcl.h.
Instanciate templates for any type you whish to use.

	// gcl.h
	// a vector of ints
	#define TYPE int // choose a type
	#include "gcl/vector.h" // include the header
	#include "gcl/vector.def" // include the template definition
	#undef TYPE // release the type

You can now use your instanciated container by including gcl.h.

	// main.c
	#include <stdio.h>
	#include "gcl.h"

	int main(int argc, char const *argv[])
	{
		vector_t(int) *my_vector = vector_new(int)(0);
		vector_at(int)(my_vector, 5) = 42;
		printf("%d\n", vector_at(int)(my_vector, 5));
		vector_delete(int)(my_vector);

		return 0;
	}

A parser is planned for future releases.


## Currently Implemented:

Vector: a container designed for efficient random access and growth.
Map: a key-value associative container implemented as a RB tree.

## In Progress

List: a linked list with efficient insertion and deletion from a known position.
String: a refcounted string container and utility.

## Planned

Hashmap: a cache-friendly variant of Map.
Set and Bag: sometimes you need them.
Deque: a compromise between the cache friendliness of Vector and the fast insertion of List.

