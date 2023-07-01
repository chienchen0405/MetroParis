#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>

template<typename T>
struct Cell {
    std::shared_ptr<T> value; // Value stored in the cell
    std::shared_ptr<Cell<T>> next; // Pointer to the next cell
};

template<typename T>
class LinkedList {
private:
    std::shared_ptr<Cell<T>> head; // Pointer to the head of the linked list
public:
    LinkedList() : head(nullptr) {} // Constructor to initialize the head to nullptr

    void insertAtBeginning(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> cell = std::make_shared<Cell<T>>(); // Create a new cell
        cell->value = value; // Assign the value to the cell
        cell->next = head; // Set the next pointer of the new cell to the current head
        head = cell; // Set the head to the new cell
    }

    void insertAtEnd(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> cell = std::make_shared<Cell<T>>(); // Create a new cell
        cell->value = value; // Assign the value to the cell
        if (head == nullptr) { // If the list is empty, set the head to the new cell
            head = cell;
        } else { // Otherwise, traverse the list to find the last cell and set its next pointer to the new cell
            std::shared_ptr<Cell<T>> current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = cell;
        }
    }

    std::shared_ptr<T> popFromBeginning() {
        if (head == nullptr) { // If the list is empty, return nullptr
            return nullptr;
        } else {
            std::shared_ptr<Cell<T>> cell = head; // Store the current head
            head = head->next; // Update the head to the next cell
            cell->next = nullptr; // Set the next pointer of the popped cell to nullptr
            return cell->value; // Return the value of the popped cell
        }
    }

    std::shared_ptr<T> popFromEnd() {
        if (head == nullptr) { // If the list is empty, return nullptr
            return nullptr;
        } else if (head->next == nullptr) { // If there is only one cell in the list, pop it and return its value
            std::shared_ptr<T> value = head->value;
            head = nullptr;
            return value;
        } else { // Otherwise, traverse the list to find the second last cell, pop the last cell, and return its value
            std::shared_ptr<Cell<T>> current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            std::shared_ptr<T> value = current->next->value; // Store the value of the last cell
            current->next = nullptr; // Set the next pointer of the second last cell to nullptr
            return value; // Return the value of the popped cell
        }
    }

    bool searchCell(std::shared_ptr<T> value) {
        std::shared_ptr<Cell<T>> current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse the list until the end
            if (current->value == value) { // If the value is found, return true
                return true;
            }
            current = current->next; // Move to the next cell
        }
        return false; // If the value is not found, return false
    }

    void destroyListIterative() {
        while (head != nullptr) { // Traverse the list until the end
            std::shared_ptr<Cell<T>> cell = head; // Store the current head
            head = head->next; // Update the head to the next cell
            cell = nullptr; // Destroy the current cell
        }
    }

    void destroyListRecursiveHelper(std::shared_ptr<Cell<T>>& list) {
        if (list != nullptr) { // If the list is not empty
            destroyListRecursiveHelper(list->next); // Recursively call the function for the next cell
            list = nullptr; // Destroy the current cell
        }
    }
    
    void destroyListRecursive() {
        destroyListRecursiveHelper(head); // Call the recursive helper function
}
    std::shared_ptr<Cell<T>> getHead() const {
        return head; // Return the head of the linked list
    }
    
    std::size_t size() const {
        std::size_t size = 0;
        std::shared_ptr<Cell<T>> temp = head;

        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        return size;
    }

};

#endif // LINKEDLIST_HPP
