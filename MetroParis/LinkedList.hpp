#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>

template<typename T>
struct Cell {
    std::shared_ptr<T> value;// Value stored in the cell
    std::shared_ptr<Cell<T>> next;// Pointer to the next cell
};

template<typename T>
class LinkedList {
private:
    std::shared_ptr<Cell<T>> head;// Pointer to the head of the linked list
public:
    LinkedList() : head(nullptr) {}  // Constructor to initialize the head to nullptr

    void insertAtBeginning(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> cell = std::make_shared<Cell<T>>(); // Create a new cell
        cell->value = value;// Assign the value to the cell
        cell->next = head; // Set the next pointer of the new cell to the current head
        head = cell;// Set the head to the new cell
    }

    void insertAtEnd(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> cell = std::make_shared<Cell<T>>(); 
        cell->value = value;
        if (head == nullptr) {
            head = cell;
        } else {
            std::shared_ptr<Cell<T>> current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = cell;
        }
    }

    std::shared_ptr<T> popFromBeginning() {
        if (head == nullptr) {
            return nullptr;
        } else {
            std::shared_ptr<Cell<T>> cell = head;
            head = head->next;
            cell->next = nullptr;
            return cell->value;
        }
    }

    std::shared_ptr<T> popFromEnd() {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            std::shared_ptr<T> value = head->value;
            head = nullptr;
            return value;
        } else {
            std::shared_ptr<Cell<T>> current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            std::shared_ptr<T> value = current->next->value;
            current->next = nullptr;
            return value;
        }
    }

    bool searchCell(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void destroyListIterative() {
        while (head != nullptr) {
            std::shared_ptr<Cell<T>> cell = head;
            head = head->next;
            cell = nullptr;
        }
    }

    void destroyListRecursiveHelper(std::shared_ptr<Cell<T>>& list) {
        if (list != nullptr) {
            destroyListRecursiveHelper(list->next);
            list = nullptr;
        }
    }
    
    void destroyListRecursive() {
        destroyListRecursiveHelper(head);
    }

    std::shared_ptr<Cell<T>> getHead() {
        return head;
    }
};

#endif // LINKEDLIST_HPP
