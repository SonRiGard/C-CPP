#include "list.h"
#include <stdio.h>

static Node nodes[MAX];  // Static array to store nodes
static int head;         // Index of the first element
static int freeIndex;    // Index of the next available memory slot

// Initialize the linked list
void InitArray() {
    head = -1;  // Empty list
    freeIndex = 0;  // Start from the first position of the array
}

// Add an element to the linked list
void AddElement(int value) {
    if (freeIndex >= MAX) {
        printf("List is full!\n");
        return;
    }

    nodes[freeIndex].value = value;
    nodes[freeIndex].next = head;  // Insert at the beginning
    head = freeIndex;
    freeIndex++;  // Update the next free index
}

// Delete an element from the linked list
void DeleteElement(int value) {
    int current = head;
    int prev = -1;

    while (current != -1) {
        if (nodes[current].value == value) {
            if (prev == -1) {
                head = nodes[current].next;  // Remove the first element
            } else {
                nodes[prev].next = nodes[current].next;  // Skip the deleted element
            }
            printf("Deleted %d\n", value);
            return;
        }
        prev = current;
        current = nodes[current].next;
    }

    printf("Element %d not found\n", value);
}

// Function to sort the linked list
void Sort() {
    int sorted[MAX];
    int count = 0;
    int current = head;

    while (current != -1) {
        sorted[count++] = nodes[current].value;
        current = nodes[current].next;
    }

    // Sort the array
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // Rebuild the linked list in sorted order
    head = -1;
    freeIndex = 0;
    for (int i = 0; i < count; i++) {
        AddElement(sorted[i]);
    }

    printf("List sorted!\n");
}

// Search for an element in the list
int Search(int value) {
    int current = head;
    while (current != -1) {
        if (nodes[current].value == value) {
            return current;  // Return index if found
        }
        current = nodes[current].next;
    }
    return -1;  // Not found
}

// Display the linked list
void Display() {
    int current = head;
    printf("List: ");
    while (current != -1) {
        printf("%d -> ", nodes[current].value);
        current = nodes[current].next;
    }
    printf("NULL\n");
}
