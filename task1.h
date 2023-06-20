#ifndef TASK1_H
#define TASK1_H

#include <string>

class Node {
public:
    Node(const std::string& name);
    Node();
    void display() const;

private:
    std::string name_;
};

class Edge {
public:
    Edge(int capacity, int cost);
    Edge();
    void display() const;

private:
    int capacity_;
    int cost_;
};

#endif // TASK1_H