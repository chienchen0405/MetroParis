#include "LinkedList.hpp"
#include "Station.hpp"
#include <iostream>

class Line {
private:
    LinkedList<Node> stations;
public:
    void insertHeadStation(std::shared_ptr<Node> station);
    void insertEndStation(std::shared_ptr<Node> station);
    std::shared_ptr<Node> popHeadStation();
    std::shared_ptr<Node> popEndStation();
    bool searchStation(std::shared_ptr<Node> station);
    void destroyLineIterative();
    void destroyLineRecursive();
    void displayLine();
};

