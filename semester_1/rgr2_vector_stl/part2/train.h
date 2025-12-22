#pragma once

#include <string>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;


enum class TrainType { 
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};


class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

public:
    Train() {
    }
    Train(TrainId id, TrainType type, std::string destination, std::time_t dispatch_time,
          std::time_t travelling_time)
        : id_(id),
          type_(type),
          destination_(destination),
          dispatch_time_(dispatch_time),
          travelling_time_(travelling_time) {
    }

    TrainId GetID() const {
        return id_;
    }
    std::string TrainIdToString(TrainType t) const {
        std::string res;
        switch (t) {
            case TrainType::PASSENGER:
                res = "Passenger";
                break;
            case TrainType::FREIGHT:
                res = "Freight";
                break;
            case TrainType::HIGH_SPEED:
                res = "High_Speed";
                break;
            case TrainType::SUBWAY:
                res = "Subway";
                break;
            case TrainType::SPECIALIZED:
                res = "Specialized";
                break;
            default:
                res = "Undenified type";
        }
        return res;
    }
    std::string GetType() const {
        return TrainIdToString(type_);
    }
    std::string GD() const {
        return destination_;
    }
    std::time_t GetDisp() const {
        return dispatch_time_;
    }
    std::time_t GetTT() const {
        return travelling_time_;
    }

    bool operator>(const Train& other) {
        return travelling_time_ > other.travelling_time_;
    }
};

