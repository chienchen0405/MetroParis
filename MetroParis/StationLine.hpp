#include "LinkedList.hpp"
#include "Station.hpp"
#include <iostream>

class Line {
private:
    LinkedList<Node> stations;
    //Cell is used as a node in the Linked list, the 'Node' object from Station.hpp is used as the value of a Cell.
    //Node already be std::shared_ptr<Node>, now Cell<T> eaquas Node , and T is the value of Node,
    
    // Helper method to remove a station from the vector
public:
    bool nodeExists(std::shared_ptr<Node> station);
    void insertHeadStation(std::shared_ptr<Node> station);
    void insertEndStation(std::shared_ptr<Node> station);
    std::shared_ptr<Node> popHeadStation();
    std::shared_ptr<Node> popEndStation();
    bool searchStation(std::shared_ptr<Node> station);
    void destroyLineIterative();
    void destroyLineRecursive();
    void displayLine();
    std::shared_ptr<Cell<Node>> getHead() const;
    void saveToCSV(const std::string& filename) const;
    void removeStationFromVector(const std::shared_ptr<Node>& station);
};
