#include "time_utility.h"
#include "train.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

bool CheckFile(std::ifstream& file) {
    if (!file.is_open())
        return false;
    if (file.peek() == EOF)
        return false;
    return true;
}
std::vector<Train> GetInfoFromFile() {
    std::vector<Train> trains;
    std::ifstream file("input.txt");
    if (CheckFile(file)) {
        std::vector<Train> trains;
        std::string destination;
        TrainId id;
        int type;
        size_t dispatchTimeMinutes, DispatchTimeHours, TravelTimeMinutes, TravelTimeHours;
        while (file >> id >> type >> destination >> DispatchTimeHours >> dispatchTimeMinutes >>
               TravelTimeHours >> TravelTimeMinutes) {
            time_t dispatch_time = SetTime(DispatchTimeHours, dispatchTimeMinutes);
            time_t travel_time = SetTime(TravelTimeHours, TravelTimeMinutes);
            Train t(id, TrainType(type), destination, dispatch_time, travel_time);
            trains.push_back(t);
        }
    }
    return trains;
}

void PrintTrains(const Train& tr) {
    std::cout << " ID: " << tr.GetID() << "\n";

    std::cout << " Destination: " << tr.GD() << "\n";

    std::cout << " Type: " << tr.GetType() << "\n";

    std::cout << " Dispatch Time: " << tr.GetDisp() << "\n";

    std::cout << " Travel time: " << tr.GetTT() << "\n";
}
void SortAccordingToDispatchTime(std::vector<Train>& v) {
    std::sort(v.begin(), v.end(),
              [](const Train& a, const Train& b) { return a.GetDisp() < b.GetDisp(); });
}

void PrintTrainsFromTimeRange(time_t min, time_t max, std::vector<Train> v) {
    for (Train trs : v) {
        if ((trs.GetDisp() > min) && (trs.GetDisp() < max)) {
            PrintTrains(trs);
        }
    }
}
void PrintTrainsWithDestination(std::string dest, std::vector<Train> v) {
    for (Train trs : v) {
        if (trs.GD() == dest) {
            PrintTrains(trs);
        }
    }
}
void PrintTrainsWithTypeAndDest(std::string type, std::string dest, std::vector<Train> v) {
    for (Train trs : v) {
        if ((trs.GetType() == type) && (trs.GD() == dest)) {
            PrintTrains(trs);
        }
    }
}
Train FindTheFastestTrain(std::string dest, std::vector<Train> v) {
    std::time_t min;
    Train MinTrain;
    for (Train trs : v) {
        if (trs.GD() == dest) {
            min = trs.GetTT();
            break;
        }
    }

    for (Train trs : v) {
        if ((trs.GD() == dest) && (trs.GetTT() < min)) {
            min = trs.GetTT();
            MinTrain = trs;
        }
    }
    return MinTrain;
}
int main() {

      std::vector<Train> Tr = GetInfoFromFile();
    SortAccordingToDispatchTime(Tr);
    std::cout << "sorted by dispatch time: ";
    for (Train i : Tr) {
        PrintTrains(i);
    }
    std::cout << "Trains that depart from 0.00 to 12.00: ";
    PrintTrainsFromTimeRange(SetTime(0,0),SetTime(12, 0),Tr);

    std::cout << "Trains that go to Smalyavichi: ";
    PrintTrainsWithDestination("Smalyavichi",Tr);
    std::cout << "Passenger trains that go to Maladechna: ";
    PrintTrainsWithTypeAndDest("Passenger", "Maladechna",Tr);

    std::cout << "The Fastest train to Baranavichy is ";
    PrintTrains(FindTheFastestTrain("Baranavichy", Tr));

    using namespace time_utility;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::time_t t1 = SetTime(12, 23);
    try {
        t1 = SetTime(12, 60);
    } catch (const std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }

    std::time_t t2 = GenerateRandomTime(generator);

    std::cout << "t1: ";
    PrintTime(t1);

    std::cout << "t2: ";
    PrintTime(t2);

    std::cout << "t1 < t2: " << std::boolalpha << (t1 < t2) << '\n';
    std::cout << "t2 < t1: " << std::boolalpha << (t2 < t1) << '\n';


  

    return EXIT_SUCCESS;
}
