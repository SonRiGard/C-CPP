#ifndef LIST_H
#define LIST_H

#include <stddef.h> // size_t

#define MAX 100  // Static array size

// Struct Node (Stored in a static array)
typedef struct {
    int value;
    int next;
} Node;

// Function prototypes
void InitArray();
void AddElement(int value);
void DeleteElement(int value);
void Sort();
int Search(int value);
void Display();

#endif // LIST_H
