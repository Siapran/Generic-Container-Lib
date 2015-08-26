#ifndef LIST_GENERIC_MACROS
#define LIST_GENERIC_MACROS

#ifndef TOKENPASTE
/**
 * Concatenates A to B, used to generate suffixed function names
 */
#define TOKENPASTE(a, b) a##_##b
#endif

/* the list (double ended queue) container type */
#define list_t(T) TOKENPASTE(list_t, T)
#define list_node_t(T) TOKENPASTE(list_node_t, T)
#define list_iterator(T) TOKENPASTE(list_iterator, T)

/* two sets of constructors/destructors */
/* container_init initialises a container that has already been allocated */
/* container_new allocates a container on the heap and initialises it */
/* a container allocated by container_new shall be destroyed with container_delete */
/* a container allocated by the caller shall be destroyed with container_destroy */
/* a container allocated by the caller shall NOT be destroyed with container_delete */
#define list_init(T) TOKENPASTE(list_init, T)
#define list_destroy(T) TOKENPASTE(list_destroy, T)
#define list_new(T) TOKENPASTE(list_new, T)
#define list_delete(T) TOKENPASTE(list_delete, T)

#define list_push_back(T) TOKENPASTE(list_push_back, T)
#define list_pop_back(T) TOKENPASTE(list_pop_back, T)
#define list_push_front(T) TOKENPASTE(list_push_front, T)
#define list_pop_front(T) TOKENPASTE(list_pop_front, T)

#define list_insert(T) TOKENPASTE(list_insert, T)
#define list_erase(T) TOKENPASTE(list_erase, T)

#define list_clear(T) TOKENPASTE(list_clear, T)

#define list_begin(T) TOKENPASTE(list_begin, T)
#define list_reverse_begin(T) TOKENPASTE(list_reverse_begin, T)
#define list_end NULL
#define list_itr_increment(T) TOKENPASTE(list_itr_increment, T)
#define list_itr_decrement(T) TOKENPASTE(list_itr_decrement, T)

#define list_foreach(T, iterator, list) for ((*iterator) = list_begin(T)(list); *iterator != NULL; list_itr_increment(T)(iterator))

#endif


typedef struct list_node_t(TYPE) {
    struct list_node_t(TYPE) *next;
    struct list_node_t(TYPE) *prev;
    TYPE value;
} list_node_t(TYPE);

typedef struct list_t(TYPE) {
    size_t size;
    list_node_t(TYPE) *front;
    list_node_t(TYPE) *back;
} list_t(TYPE);

typedef list_node_t(TYPE)* list_iterator(TYPE);

void list_init(TYPE)(list_t(TYPE) *this);
void list_destroy(TYPE)(list_t(TYPE) *this);
list_t(TYPE) *list_new(TYPE)();
void list_delete(TYPE)(list_t(TYPE) *this);

void list_push_back(TYPE)(list_t(TYPE) *this, TYPE value);
TYPE list_pop_back(TYPE)(list_t(TYPE) *this);
void list_push_front(TYPE)(list_t(TYPE) *this, TYPE value);
TYPE list_pop_front(TYPE)(list_t(TYPE) *this);

void list_insert(TYPE)(list_t(TYPE) *this, list_iterator(TYPE) *itr, TYPE value);
void list_erase(TYPE)(list_t(TYPE) *this, list_iterator(TYPE) *itr);

void list_clear(TYPE)(list_t(TYPE) *this);

list_iterator(TYPE) list_begin(TYPE)(list_t(TYPE) *this);
list_iterator(TYPE) list_reverse_begin(TYPE)(list_t(TYPE) *this);
void list_itr_increment(TYPE)(list_iterator(TYPE) *itr);
void list_itr_decrement(TYPE)(list_iterator(TYPE) *itr);
