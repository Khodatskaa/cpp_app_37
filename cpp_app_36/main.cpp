#include <iostream>
#include <vector>
#include <string>

class Train {
public:
    int number;
    std::string departureTime;
    std::string destinationStation;

    Train(int num, const std::string& time, const std::string& dest) : number(num), departureTime(time), destinationStation(dest) {}
};

class RailwayStation {
private:
    std::vector<Train> trains;
public:
    void addTrain(int number, const std::string& departureTime, const std::string& destinationStation) {
        Train newTrain(number, departureTime, destinationStation);
        trains.push_back(newTrain);
        std::cout << "Train added successfully!\n";
    }

    void displayAllTrains() {
        if (trains.empty()) {
            std::cout << "No trains available\n";
            return;
        }

        std::cout << "All Trains Information:\n";
        for (const auto& train : trains) {
            std::cout << "Train No: " << train.number << ", Departure Time: " << train.departureTime << ", Destination Station: " << train.destinationStation << '\n';
        }
    }

    void displayTrainInfo(int trainNumber) {
        for (const auto& train : trains) {
            if (train.number == trainNumber) {
                std::cout << "Train Information for Train No " << trainNumber << ":\n";
                std::cout << "Departure Time: " << train.departureTime << "\n";
                std::cout << "Destination Station: " << train.destinationStation << "\n";
                return;
            }
        }
        std::cout << "Train with number " << trainNumber << " not found\n";
    }
};

int main() {
    RailwayStation station;

    while (true) {
        std::cout << "1. Add Train\n";
        std::cout << "2. Display All Trains\n";
        std::cout << "3. Display Train Information\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int number;
            std::string departureTime, destinationStation;

            std::cout << "Enter Train Number: ";
            std::cin >> number;
            std::cout << "Enter Departure Time: ";
            std::cin >> departureTime;
            std::cout << "Enter Destination Station: ";
            std::cin.ignore(); 
            std::getline(std::cin, destinationStation);

            station.addTrain(number, departureTime, destinationStation);
            break;
        }
        case 2:
            station.displayAllTrains();
            break;
        case 3: {
            int trainNumber;
            std::cout << "Enter Train Number to Display Information: ";
            std::cin >> trainNumber;
            station.displayTrainInfo(trainNumber);
            break;
        }
        case 4:
            std::cout << "Exiting the program\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again\n";
        }
    }

    return 0;
}