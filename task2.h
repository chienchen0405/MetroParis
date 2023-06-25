#ifndef TASK2_H
#define TASK2_H

#include "task1.h"

// Define the structure for a cell in the linked list
template<typename T>
struct Cell {
    T* value;
    Cell<T>* next;
};

// Function to create a cell from a value
template<typename T>
Cell<T>* createCell(T* value);

// Function to insert a cell at the beginning of a list
template<typename T>
void insertAtBeginning(Cell<T>*& list, Cell<T>* cell);

// Function to insert a cell at the end of a list
template<typename T>
void insertAtEnd(Cell<T>*& list, Cell<T>* cell);

// Function to pop a cell from the beginning of a list
template<typename T>
Cell<T>* popFromBeginning(Cell<T>*& list);

// Function to pop a cell from the end of a list
template<typename T>
Cell<T>* popFromEnd(Cell<T>*& list);

// Function to search if a cell exists in a list
template<typename T>
bool searchCell(Cell<T>* list, T* value);

// Function to destroy a list using an iterative algorithm
template<typename T>
void destroyListIterative(Cell<T>*& list);

// Function to destroy a list using a recursive algorithm
template<typename T>
void destroyListRecursive(Cell<T>*& list);

// Function to display all the cells from a list
template<typename T>
void displayList(Cell<T>* list);

#endif // TASK2_H