#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Computer {
public:
    string name;
    int GHz; // in GHz
    int ram_size;
    bool has_dvd_rom;
    double price;

    Computer(string name, int GHz, int ram_size, bool has_dvd_rom, double price)
        : name(name), GHz(GHz), ram_size(ram_size), has_dvd_rom(has_dvd_rom), price(price) {}

    void print() const {
        cout << "Name: " << name << ", GHz: " << GHz << " GHz, RAM: " << ram_size << " GB, DVD-ROM: "
            << (has_dvd_rom ? "Yes" : "No") << ", Price: " << price << " UAH" << endl;
    }
};

int main() {
    vector<Computer> computers = {
        Computer("HP Pavilion", 3, 8, true, 15000),
        Computer("Dell Inspiron", 2, 16, false, 20000),
        Computer("Lenovo ThinkPad", 4, 32, true, 25000),
        Computer("Asus ZenBook", 2, 8, false, 18000),
        Computer("Acer Nitro", 3, 16, true, 22000)
    };

    // Print the initial state of the container
    cout << "Initial state of the container:" << endl;
    for (const auto& computer : computers) {
        computer.print();
    }
    cout << endl;

    // 1. Find a computer by name using find_if()
    string search_name = "Lenovo ThinkPad";
    auto found = find_if(computers.begin(), computers.end(), [&](const Computer& computer) {
        return computer.name == search_name;
        });

    if (found != computers.end()) {
        cout << "Found computer: ";
        found->print();
    }
    else {
        cout << "Computer with name '" << search_name << "' not found." << endl;
    }
    cout << endl;

    // 2. Find the computer with the lowest frequency and remove it from the container (min_element() and erase())
    auto min_GHz = min_element(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.GHz < b.GHz;
        });

    cout << "Removed computer with the lowest GHz: ";
    min_GHz->print();
    computers.erase(min_GHz);

    cout << "State of the container after removal:" << endl;
    for (const auto& computer : computers) {
        computer.print();
    }
    cout << endl;

    // 3. Count the number of computers that have a DVD-ROM (count_if())
    int dvd_count = count_if(computers.begin(), computers.end(), [](const Computer& computer) {
        return computer.has_dvd_rom;
        });

    cout << "Number of computers with DVD-ROM: " << dvd_count << endl;
    cout << endl;

    // 4. Increase the price of computers with more than 16GB of RAM (for_each())
    for_each(computers.begin(), computers.end(), [](Computer& computer) {
        if (computer.ram_size > 16) {
            computer.price *= 1.1; // Increase price by 10%
        }
        });

    cout << "State of the container after price increase:" << endl;
    for (const auto& computer : computers) {
        computer.print();
    }
    cout << endl;

    // 5. Sort the container in ascending and descending order of price (sort())
    // Sort by ascending price
    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.price < b.price;
        });

    cout << "State of the container after sorting by ascending price:" << endl;
    for (const auto& computer : computers) {
        computer.print();
    }
    cout << endl;

    // Sort by descending price
    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.price > b.price;
        });

    cout << "State of the container after sorting by descending price:" << endl;
    for (const auto& computer : computers) {
        computer.print();
    }
    cout << endl;

    return 0;
}