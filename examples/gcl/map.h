#define K KEY_TYPE
#define V VALUE_TYPE

#ifndef MAP_GENERIC
#define MAP_GENERIC

#ifndef TOKENPASTE2
/**
 * Concatenates A to B, used to generate suffixed function names
 */
#define TOKENPASTE2(x, y, z) x##_##y##_##z
#endif

/* the map container type */
#define map_t(K, V) TOKENPASTE2(map_t, K, V)
#define map_node_t(K, V) TOKENPASTE2(map_node_t, K, V)
#define map_iterator(K, V) TOKENPASTE2(map_iterator, K, V)

/* container_at should always be accessed as a reference */
/* map_at gives a reference to the value at KEY */
/* if no element exists for KEY, it is automatically created and assigned to 0 */
#define map_at(K, V) TOKENPASTE2(*map_at, K, V)

/* two sets of constructors/destructors */
/* container_init initialises a container that has already been allocated */
/* container_new allocates a container on the heap and initialises it */
/* a container allocated by container_new shall be destroyed with container_delete */
/* a container allocated by the caller shall be destroyed with container_destroy */
/* a container allocated by the caller shall NOT be destroyed with container_delete */
#define map_init(K, V) TOKENPASTE2(map_init, K, V)
#define map_destroy(K, V) TOKENPASTE2(map_destroy, K, V)
#define map_new(K, V) TOKENPASTE2(map_new, K, V)
#define map_delete(K, V) TOKENPASTE2(map_delete, K, V)

#define map_find_or_create(K, V) TOKENPASTE2(map_find_or_create, K, V)
#define map_find(K, V) TOKENPASTE2(map_find, K, V)
#define map_insert(K, V) TOKENPASTE2(map_insert, K, V)
#define map_erase(K, V) TOKENPASTE2(map_erase, K, V)

#define map_clear(K, V) TOKENPASTE2(map_clear, K, V)

#define map_begin(K, V) TOKENPASTE2(map_begin, K, V)
#define map_reverse_begin(K, V) TOKENPASTE2(map_reverse_begin, K, V)
#define map_end NULL
#define map_itr_increment(K, V) TOKENPASTE2(map_itr_increment, K, V)
#define map_itr_decrement(K, V) TOKENPASTE2(map_itr_decrement, K, V)

typedef enum map_node_color { RED, BLACK } map_node_color;

#define map_foreach(K, V, iterator, map) for ((*iterator) = map_begin(K, V)(map); *iterator != NULL; map_itr_increment(K, V)(iterator))

#endif

typedef struct map_node_t(K, V) {
	K key;
	V value;
	struct map_node_t(K, V) *left;
	struct map_node_t(K, V) *right;
	struct map_node_t(K, V) *parent;
	int color;
} map_node_t(K, V);

typedef struct map_t(K, V) {
	/* compare(a,b) should return 1 if *a > *b, -1 if *a < *b, and 0 otherwise */
	int (*compare)(const K a, const K b);
	map_node_t(K, V) *root;
} map_t(K, V);

typedef map_node_t(K, V)* map_iterator(K, V);

V map_at(K, V)(map_t(K, V) *this, K key);

void map_init(K, V)(map_t(K, V) *this, int (*compare)(const K a, const K b));
void map_destroy(K, V)(map_t(K, V) *this);
map_t(K, V) *map_new(K, V)(int (*compare)(const K a, const K b));
void map_delete(K, V)(map_t(K, V) *this);

map_iterator(K, V) map_find(K, V)(map_t(K, V) *this, K key);
map_iterator(K, V) map_find_or_create(K, V)(map_t(K, V) *this, K key);
void map_insert(K, V)(map_t(K, V) *this, K key, V value);
void map_erase(K, V)(map_t(K, V) *this, K key);
void map_clear(K, V)(map_t(K, V) *this);

map_iterator(K, V) map_begin(K, V)(map_t(K, V) *this);
map_iterator(K, V) map_reverse_begin(K, V)(map_t(K, V) *this);
void map_itr_increment(K, V)(map_iterator(K, V) *itr);
void map_itr_decrement(K, V)(map_iterator(K, V) *itr);


#undef K
#undef V