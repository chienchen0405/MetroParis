#include "LinkedList.hpp"
#include "Station.hpp"
#include <iostream>

class Line {
private:
    LinkedList<Node> stations;
    //Cell is used as a node in the Linked list, the 'Node' object from Station.hpp is used as the value of a Cell.
    //Node already be std::shared_ptr<Node>, now Cell<T> eaquas Node , and T is the value of Node, 
public:
    void insertHeadStation(std::shared_ptr<Node> station);
    void insertEndStation(std::shared_ptr<Node> station);
    std::shared_ptr<Node> popHeadStation();
    std::shared_ptr<Node> popEndStation();
    bool searchStation(std::shared_ptr<Node> station);
    void destroyLineIterative();
    void destroyLineRecursive();
    void displayLine();
    std::shared_ptr<Cell<Node>> getHead();
};

