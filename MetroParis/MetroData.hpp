#ifndef METRODATA_H
#define METRODATA_H

#include <string>
#include "MetroNetwork.hpp"

class MetroData {
public:
    void readFromFile(const std::string& filename, MetroNetwork& network);
    void writeToFile(const std::string& filename, const MetroNetwork& network);
    int getMaxStationId(const std::string& filename);
    double convertDMSToDecimal(const std::string& dms);
    std::string sanitizeInput(const std::string& input);
};

#endif // METRODATA_H
