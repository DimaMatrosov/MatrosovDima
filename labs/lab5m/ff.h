#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CACHE_SIZE 10
#define BUFFER_SIZE 256
#define RECORD_PATH "records.txt"


typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
    struct Node *prev;
    struct Node *collision_chain;
} Node;

typedef struct Table {
    int capacity;
    Node **array;
} Table;

typedef struct List {
    int size;
    int capacity;
    Node *head;
    Node *tail;
} List;

typedef struct LRUCache {
    Table *table;
    List *list;
} LRUCache;

Node *create_node(char *key, char *value);

Table *create_table(int capacity);

LRUCache *create_cache(int size);

typedef struct {
    int len;
    char **str;
} string;

static size_t get_hash_index(Table *table, const char *source);

void remove_oldest(LRUCache *cache);

void move_to_front(LRUCache *cache, char *key);

void add_to_list(LRUCache *cache, Node *node);

int add_to_table(Table *table, Node *node);

void put(LRUCache *cache, char *key, char *value);

char *get(LRUCache *cache, char *key);

void print_cache(LRUCache *cache);

string *split(char *input, char *delimiter);

int is_ip(const char *str);

char *file_read(char path[]);

void fill_cache(LRUCache *cache);

void get_in_file(char *key, LRUCache *cache);

char *find_ip_by_domain(LRUCache *cache, char *key);

void add_record();

void find_domains_by_ip();
