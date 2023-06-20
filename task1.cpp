#include <iostream>
#include <string>

//易读规范
//public use for constructor
//and private use for parameter in constructor 
//This is often done to ensure that the class has control over 
//how the parameter is used and to prevent 'external code' from directly modifying the parameter 
//without going through the appropriate class methods or functions.
//这通常是为了确保类对参数的使用具有控制力，并防止外部代码直接修改参数而不经过适当的类方法或函数。


//constant reference declaration
//Declaring a reference as a constant reference ensures
//that the parameter passed into a function cannot be modified within the function.
//而将引用声明为常量引用，可以确保在函数内部不会修改传入的参数

//‘std::’ 
//A namespace is a mechanism used to avoid naming conflicts 
//by organizing related functions, classes, and objects under a single namespace.
//This allows for a clearer specification of their source when used in code.

//命名空间是一种用于避免命名冲突的机制，它将相关的函数、类和对象组织在一个命名空间下，
//以便在代码中使用时能够更清晰地指定它们的来源。

class Node {
public:
Node(const std::string& name) : name_(name) {} //Initialize node with parameter
Node() { //Initialize node without parameter
std::cout << "Enter node name: "; //print
std::cin >> name_; //input
}

void display() const { //print
    std::cout << "Node name: " << name_ << std::endl;
}

private:
std::string name_;
};

class Edge {
public:
Edge(int capacity, int cost) : capacity_(capacity), cost_(cost) {} //Initialize edges with parameter
Edge() { ////Initialize edges without parameter
std::cout << "Enter edge capacity: ";

std::cin >> capacity_; // Question1: why do we need this variable for edge 

std::cout << "Enter edge cost: ";
std::cin >> cost_;
}

void display() const {
    std::cout << "Edge capacity: " << capacity_ << ", cost: " << cost_ << std::endl;
}

private:
int capacity_;
int cost_;
};