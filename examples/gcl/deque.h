#ifndef DEQUE_GENERIC_MACROS
#define DEQUE_GENERIC_MACROS

#ifndef TOKENPASTE
/**
 * Concatenates A to B, used to generate suffixed function names
 */
#define TOKENPASTE(a, b) a##_##b
#endif

/* the deque container type */
#define deque_t(T) TOKENPASTE(deque_t, T)

/* container_at should always be accessed as a reference */
/* this way, the caller can write: */
/* ++deque_at(int)(my_deque, 42); */
/* deque_at resizes the deque if needed */
/* if the caller wants to do an unchecked access, they can write: */
/* my_deque->data[42] */
#define deque_at(T) TOKENPASTE(*deque_at, T)

/* two sets of constructors/destructors */
/* container_init initialises a container that has already been allocated */
/* container_new allocates a container on the heap and initialises it */
/* a container allocated by container_new shall be destroyed with container_delete */
/* a container allocated by the caller shall be destroyed with container_destroy */
/* a container allocated by the caller shall NOT be destroyed with container_delete */
#define deque_init(T) TOKENPASTE(deque_init, T)
#define deque_destroy(T) TOKENPASTE(deque_destroy, T)
#define deque_new(T) TOKENPASTE(deque_new, T)
#define deque_delete(T) TOKENPASTE(deque_delete, T)

/* deque_push_vack increments efficiently the size of the deque before storing the value */
/* deque_pop_back does NOT reallocate the deque */
#define deque_push_back(T) TOKENPASTE(deque_push_back, T)
#define deque_pop_back(T) TOKENPASTE(deque_pop_back, T)
#define deque_push_front(T) TOKENPASTE(deque_push_front, T)
#define deque_pop_front(T) TOKENPASTE(deque_pop_front, T)

/* deque_resize changes the size of the deque and calls deque_reserve */
/* deque_reserve reallocates the data only if needed */
#define deque_resize(T) TOKENPASTE(deque_resize, T)
#define deque_reserve(T) TOKENPASTE(deque_reserve, T)

#endif

/**
 * the deque type stores:
 * 		a logical size
 * 		a real allocated size
 * 		a pointer to the allocated data
 */
typedef struct deque_t(TYPE) {
    size_t size;
    size_t capacity;
    TYPE *data;
    TYPE *
} deque_t(TYPE);

/**
 * returns a pseudo-reference to the element of the deque at pos
 * if pos is greater or equal than the deque size, the deque is resized to fit
 * @param  this the deque
 * @param  pos  the position/index
 * @return      the a read-write reference to the element
 */
TYPE deque_at(TYPE)(deque_t(TYPE) *this, size_t pos);

/**
 * initializes the deque with a specified size
 * @param this the deque
 * @param size the size
 */
void deque_init(TYPE)(deque_t(TYPE) *this, size_t size);
/**
 * contructor provided for convenience
 */
deque_t(TYPE) *deque_new(TYPE)(size_t size);

/**
 * destroys the deque, freeing all allocated memory
 * @param this the deque
 */
void deque_destroy(TYPE)(deque_t(TYPE) *this);
/**
 * destructor provided for convenience
 */
void deque_delete(TYPE)(deque_t(TYPE) *this);

/**
 * pushes the value at the back of the deque
 * increases the size by 1
 * @param this  the deque
 * @param value the value
 */
void deque_push_back(TYPE)(deque_t(TYPE) *this, TYPE value);
/**
 * pops an element from the back of the deque
 * does NOT reallocate the deque
 * @param  this the deque
 * @return      the value of the popped element
 */
TYPE deque_pop_back(TYPE)(deque_t(TYPE) *this);
/**
 * pushes the value at the front of the deque
 * increases the size by 1
 * @param this  the deque
 * @param value the value
 */
void deque_push_front(TYPE)(deque_t(TYPE) *this, TYPE value);
/**
 * pops an element from the front of the deque
 * does NOT reallocate the deque
 * @param  this the deque
 * @return      the value of the popped element
 */
TYPE deque_pop_front(TYPE)(deque_t(TYPE) *this);
/**
 * resizes the deque to fit the size
 * reallocates the deque if needed
 * reallocation size is always a power of 2
 * @param this the deque
 * @param size the size
 */
void deque_resize(TYPE)(deque_t(TYPE) *this, size_t size);
/**
 * reallocates the deque to fit the size
 * reallocates the deque if needed
 * reallocation size is always a power of 2
 * @param this the deque
 * @param size the size
 */
void deque_reserve(TYPE)(deque_t(TYPE) *this, size_t size);
