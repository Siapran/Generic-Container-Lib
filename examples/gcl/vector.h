#ifndef VECTOR_GENERIC_MACROS
#define VECTOR_GENERIC_MACROS

#ifndef TOKENPASTE
#define TOKENPASTE(a, b) a##_##b
#endif

/* the vector container type */
#define vector_t(T) TOKENPASTE(vector_t, T)

/* container_at should always be accessed as a reference */
/* this way, the caller can write: */
/* ++vector_at(int)(my_vector, 42); */
/* vector_at resizes the vector if needed */
/* if the caller wants to do an unchecked access, they can write: */
/* my_vector->data[42] */
#define vector_at(T) TOKENPASTE(*vector_at, T)

/* two sets of constructors/destructors */
/* container_init initialises a container that has already been allocated */
/* container_new allocates a container on the heap and initialises it */
/* a container allocated by container_new shall be destroyed with container_delete */
/* a container allocated by the caller shall be destroyed with container_destroy */
/* a container allocated by the caller shall NOT be destroyed with container_delete */
#define vector_init(T) TOKENPASTE(vector_init, T)
#define vector_destroy(T) TOKENPASTE(vector_destroy, T)
#define vector_new(T) TOKENPASTE(vector_new, T)
#define vector_delete(T) TOKENPASTE(vector_delete, T)

/* vector_push_back increments efficiently the size of the vector before storing the value */
/* vector_pop_back does NOT reallocate the vector */
#define vector_push_back(T) TOKENPASTE(vector_push_back, T)
#define vector_pop_back(T) TOKENPASTE(vector_pop_back, T)

/* vector_resize changes the size of the vector and calls vector_reserve */
/* vector_reserve reallocates the data only if needed */
#define vector_resize(T) TOKENPASTE(vector_resize, T)
#define vector_reserve(T) TOKENPASTE(vector_reserve, T)

#endif

typedef struct vector_t(TYPE) {
    size_t size;
    size_t capacity;
    TYPE *data;
} vector_t(TYPE);

TYPE vector_at(TYPE)(vector_t(TYPE) *this, size_t pos);

void vector_init(TYPE)(vector_t(TYPE) *this, size_t size);
void vector_destroy(TYPE)(vector_t(TYPE) *this);
vector_t(TYPE) *vector_new(TYPE)(size_t size);
void vector_delete(TYPE)(vector_t(TYPE) *this);

void vector_push_back(TYPE)(vector_t(TYPE) *this, TYPE value);
TYPE vector_pop_back(TYPE)(vector_t(TYPE) *this);
void vector_resize(TYPE)(vector_t(TYPE) *this, size_t size);
void vector_reserve(TYPE)(vector_t(TYPE) *this, size_t size);
