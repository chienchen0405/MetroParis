#ifndef TASK2_H
#define TASK2_H

#include "task1.h"

template<typename T>
struct Cell {
    T* value;
    Cell<T>* next;
};

template<typename T>
Cell<T>* createCell(T* value);

template<typename T>
void insertAtBeginning(Cell<T>*& list, Cell<T>* cell);

template<typename T>
void insertAtEnd(Cell<T>*& list, Cell<T>* cell);

template<typename T>
Cell<T>* popFromBeginning(Cell<T>*& list);

template<typename T>
Cell<T>* popFromEnd(Cell<T>*& list);

template<typename T>
bool searchCell(Cell<T>* list, T* value);

template<typename T>
void destroyListIterative(Cell<T>*& list);

template<typename T>
void destroyListRecursive(Cell<T>*& list);

template<typename T>
void displayList(Cell<T>* list);

#endif // TASK2_H