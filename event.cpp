#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Event {
private:
    std::string event_name;
    std::string organiser_name;
    bool is_organised;
    std::string required_info;

public:
    // Constructor
    Event(const std::string& name, const std::string& organiser, bool organised, const std::string& required)
        : event_name(name), organiser_name(organiser), is_organised(organised), required_info(required) {}

    // Getters
    std::string getEventName() const { return event_name; }
    std::string getOrganiserName() const { return organiser_name; }
    bool isOrganised() const { return is_organised; }
    std::string getRequiredInfo() const { return required_info; }

    // Setters
    void setEventName(const std::string& newName) { event_name = newName; }
    void setOrganiserName(const std::string& newName) { organiser_name = newName; }
    void setOrganised(bool organised) { is_organised = organised; }
    void setRequiredInfo(const std::string& newInfo) { required_info = newInfo; }

    // Function to display event details
    void displayDetails() const {
        std::cout << "Event Name: " << event_name << std::endl;
        std::cout << "Organiser Name: " << organiser_name << std::endl;
        std::cout << "Is Organised: " << (is_organised ? "Yes" : "No") << std::endl;
        std::cout << "Required Info: " << required_info << std::endl;
    }
};

class EventListManagementSystem {
private:
    std::vector<Event> events;

public:
    void addEvent() {
        std::string event_name, organiser_name, required_info;
        bool is_organised;
        char choice;

        std::cout << "Enter Event Name: ";
        std::getline(std::cin, event_name);
        std::cout << "Enter Organiser Name: ";
        std::getline(std::cin, organiser_name);
        std::cout << "Is Event Organised? (y/n): ";
        std::cin >> choice;
        is_organised = (choice == 'y' || choice == 'Y');
        std::cin.ignore();
        std::cout << "Enter Required Info: ";
        std::getline(std::cin, required_info);

        events.push_back(Event(event_name, organiser_name, is_organised, required_info));
        std::cout << "Event added successfully." << std::endl;
    }

    void deleteEvent() {
        int eventIndex;
        showAllEvents();
        std::cout << "Enter the index of the event to delete (starting from 0): ";
        std::cin >> eventIndex;
        std::cin.ignore();

        if (eventIndex >= 0 && eventIndex < events.size()) {
            events.erase(events.begin() + eventIndex);
            std::cout << "Event deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No event deleted." << std::endl;
        }
    }

    void editEvent() {
        int eventIndex;
        showAllEvents();
        std::cout << "Enter the index of the event to edit (starting from 0): ";
        std::cin >> eventIndex;
        std::cin.ignore();

        if (eventIndex >= 0 && eventIndex < events.size()) {
            Event& event = events[eventIndex];
            std::string new_name, new_organiser, new_info;
            char choice;

            std::cout << "Enter new Event Name (leave blank to not change): ";
            std::getline(std::cin, new_name);
            if (!new_name.empty()) {
                event.setEventName(new_name);
            }

            std::cout << "Enter new Organiser Name (leave blank to not change): ";
            std::getline(std::cin, new_organiser);
            if (!new_organiser.empty()) {
                event.setOrganiserName(new_organiser);
            }

            std::cout << "Is Event Organised? (y/n, leave blank to not change): ";
            std::cin >> choice;
            std::cin.ignore();
            if (choice == 'y' || choice == 'Y') {
                event.setOrganised(true);
            } else if (choice == 'n' || choice == 'N') {
                event.setOrganised(false);
            }

            std::cout << "Enter new Required Info (leave blank to not change): ";
            std::getline(std::cin, new_info);
            if (!new_info.empty()) {
                event.setRequiredInfo(new_info);
            }

            std::cout << "Event edited successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No event edited." << std::endl;
        }
    }

    void showAllEvents() const {
        if (events.empty()) {
            std::cout << "No events found." << std::endl;
            return;
        }

        for (const auto& event : events) {
            event.displayDetails();
            std::cout << "-------------------------" << std::endl;
        }
    }
};

// int main() {
//     EventListManagementSystem system;
//     int choice;

//     do {
//         std::cout << "\nEvent List Management System Menu:\n";
//         std::cout << "1. Add Event\n";
//         std::cout << "2. Delete Event\n";
//         std::cout << "3. Edit Event\n";
//         std::cout << "4. Show All Events\n";
//         std::cout << "5. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;
//         std::cin.ignore(); // Clear the input buffer

//         switch (choice) {
//             case 1:
//                 system.addEvent();
//                 break;
//             case 2:
//                 system.deleteEvent();
//                 break;
//             case 3:
//                 system.editEvent();
//                 break;
//             case 4:
//                 system.showAllEvents();
//                 break;
//             case 5:
//                 std::cout << "Exiting program.\n";
//                 break;
//             default:
//                 std::cout << "Invalid choice! Please try again.\n";
//                 break;
//         }
//     } while (choice != 5);

//     return 0;
// }
