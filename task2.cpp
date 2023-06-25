#include "task2.h"

// Function to create a cell from a value
template<typename T>
Cell<T>* createCell(T* value) {
    Cell<T>* cell = new Cell<T>;
    cell->value = value;
    cell->next = nullptr;
    return cell;
}

// Function to insert a cell at the beginning of a list
template<typename T>
void insertAtBeginning(Cell<T>*& list, Cell<T>* cell) {
    cell->next = list;
    list = cell;
}

// Function to insert a cell at the end of a list
template<typename T>
void insertAtEnd(Cell<T>*& list, Cell<T>* cell) {
    if (list == nullptr) {
        list = cell;
    } else {
        Cell<T>* current = list;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = cell;
    }
}

// Function to pop a cell from the beginning of a list
template<typename T>
Cell<T>* popFromBeginning(Cell<T>*& list) {
    if (list == nullptr) {
        return nullptr;
    } else {
        Cell<T>* cell = list;
        list = list->next;
        cell->next = nullptr;
        return cell;
    }
}

// Function to pop a cell from the end of a list
template<typename T>
Cell<T>* popFromEnd(Cell<T>*& list) {
    if (list == nullptr) {
        return nullptr;
    } else if (list->next == nullptr) {
        Cell<T>* cell = list;
        list = nullptr;
        cell->next = nullptr;
        return cell;
    } else {
        Cell<T>* current = list;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Cell<T>* cell = current->next;
        current->next = nullptr;
        cell->next = nullptr;
        return cell;
    }
}

// Function to search if a cell exists in a list
template<typename T>
bool searchCell(Cell<T>* list, T* value) {
    Cell<T>* current = list;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to destroy a list using an iterative algorithm
template<typename T>
void destroyListIterative(Cell<T>*& list) {
    while (list != nullptr) {
        Cell<T>* cell = list;
        list = list->next;
        delete cell;
    }
}

// Function to destroy a list using a recursive algorithm
template<typename T>
void destroyListRecursive(Cell<T>*& list) {
    if (list != nullptr) {
        destroyListRecursive(list->next);
        delete list;
        list = nullptr;
    }
}

// Function to display all the cells from a list
template<typename T>
void displayList(Cell<T>* list) {
    Cell<T>* current = list;
    while (current != nullptr) {
        (*current->value).displayEdge();
        std::cout << std::endl;
        current = current->next;
    }
}

// Explicit template instantiation for supported types
template struct Cell<Edge>;
template Cell<Edge>* createCell(Edge* value);
template void insertAtBeginning(Cell<Edge>*& list, Cell<Edge>* cell);
template void insertAtEnd(Cell<Edge>*& list, Cell<Edge>* cell);
template Cell<Edge>* popFromBeginning(Cell<Edge>*& list);
template Cell<Edge>* popFromEnd(Cell<Edge>*& list);
template bool searchCell(Cell<Edge>* list, Edge* value);
template void destroyListIterative(Cell<Edge>*& list);
template void destroyListRecursive(Cell<Edge>*& list);
template void displayList(Cell<Edge>* list);

// Explicit template instantiation for std::shared_ptr<Edge>
template struct Cell<std::shared_ptr<Edge> >;
template Cell<std::shared_ptr<Edge> >* createCell(std::shared_ptr<Edge>* value);
template void insertAtBeginning(Cell<std::shared_ptr<Edge> >*& list, Cell<std::shared_ptr<Edge> >* cell);
template void insertAtEnd(Cell<std::shared_ptr<Edge> >*& list, Cell<std::shared_ptr<Edge> >* cell);
template Cell<std::shared_ptr<Edge> >* popFromBeginning(Cell<std::shared_ptr<Edge> >*& list);
template Cell<std::shared_ptr<Edge> >* popFromEnd(Cell<std::shared_ptr<Edge> >*& list);
template bool searchCell(Cell<std::shared_ptr<Edge> >* list, std::shared_ptr<Edge>* value);
template void destroyListIterative(Cell<std::shared_ptr<Edge> >*& list);
template void destroyListRecursive(Cell<std::shared_ptr<Edge> >*& list);
template void displayList(Cell<std::shared_ptr<Edge> >* list);
