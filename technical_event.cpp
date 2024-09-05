#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

class TechnoesisMember {
private:
    int total_number_of_artist;
    int total_amount_of_fund_used;
    std::vector<std::string> sponsors_of_the_event;

public:
    // Constructor
    TechnoesisMember(
        int total_artist, int fund_used,
        const std::vector<std::string>& sponsors)
        : total_number_of_artist(total_artist),
          total_amount_of_fund_used(fund_used),
          sponsors_of_the_event(sponsors) {}

    // Getters
    int getTotalNumberOfArtist() const { return total_number_of_artist; }
    int getTotalAmountOfFundUsed() const { return total_amount_of_fund_used; }
    std::vector<std::string> getSponsorsOfTheEvent() const { return sponsors_of_the_event; }

    // Setters
    void setTotalNumberOfArtist(int newTotalArtist) { total_number_of_artist = newTotalArtist; }
    void setTotalAmountOfFundUsed(int newFundUsed) { total_amount_of_fund_used = newFundUsed; }
    void addSponsor(const std::string& sponsor) { sponsors_of_the_event.push_back(sponsor); }
    void removeSponsor(const std::string& sponsor) {
        auto it = std::find(sponsors_of_the_event.begin(), sponsors_of_the_event.end(), sponsor);
        if (it != sponsors_of_the_event.end()) {
            sponsors_of_the_event.erase(it);
        }
    }

    // Function to display member details
    void displayDetails() const {
        std::cout << "Total Number of Artists: " << total_number_of_artist << std::endl;
        std::cout << "Total Amount of Fund Used: " << total_amount_of_fund_used << std::endl;
        std::cout << "Sponsors of the Event: ";
        for (const auto& sponsor : sponsors_of_the_event) {
            std::cout << sponsor << ", ";
        }
        std::cout << std::endl;
    }
};

class TechnoesisCentralSystem {
private:
    std::vector<TechnoesisMember> members;

public:
    void addMember() {
        int total_artist, fund_used;
        std::vector<std::string> sponsors;
        std::string sponsor;
        int num_sponsors;

        std::cout << "Enter Total Number of Artists: ";
        std::cin >> total_artist;
        std::cout << "Enter Total Amount of Fund Used: ";
        std::cin >> fund_used;
        std::cout << "Enter the number of sponsors: ";
        std::cin >> num_sponsors;
        std::cin.ignore();
        for (int i = 0; i < num_sponsors; ++i) {
            std::cout << "Enter Sponsor Name: ";
            std::getline(std::cin, sponsor);
            sponsors.push_back(sponsor);
        }

        members.push_back(TechnoesisMember(total_artist, fund_used, sponsors));
        std::cout << "Member added successfully." << std::endl;
    }

    void deleteMember() {
        int memberIndex;
        showAllMembers();
        std::cout << "Enter the index of the member to delete (starting from 0): ";
        std::cin >> memberIndex;
        std::cin.ignore();

        if (memberIndex >= 0 && memberIndex < members.size()) {
            members.erase(members.begin() + memberIndex);
            std::cout << "Member deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No member deleted." << std::endl;
        }
    }

    void editMember() {
        int memberIndex;
        showAllMembers();
        std::cout << "Enter the index of the member to edit (starting from 0): ";
        std::cin >> memberIndex;
        std::cin.ignore();

        if (memberIndex >= 0 && memberIndex < members.size()) {
            TechnoesisMember &member = members[memberIndex];
            int total_artist, fund_used;
            std::string sponsor;
            int num_sponsors;

            std::cout << "Enter new Total Number of Artists: ";
            std::cin >> total_artist;
            std::cout << "Enter new Total Amount of Fund Used: ";
            std::cin >> fund_used;
            std::cout << "Enter the number of sponsors: ";
            std::cin >> num_sponsors;
            std::cin.ignore();
            member.setTotalNumberOfArtist(total_artist);
            member.setTotalAmountOfFundUsed(fund_used);
            member.getSponsorsOfTheEvent().clear();
            for (int i = 0; i < num_sponsors; ++i) {
                std::cout << "Enter Sponsor Name: ";
                std::getline(std::cin, sponsor);
                member.addSponsor(sponsor);
            }

            std::cout << "Member edited successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No member edited." << std::endl;
        }
    }

    void showAllMembers() const {
        if (members.empty()) {
            std::cout << "No members found." << std::endl;
            return;
        }

        for (const auto& member : members) {
            member.displayDetails();
            std::cout << "-------------------------" << std::endl;
        }
    }
};

// int main() {
//     TechnoesisCentralSystem system;
//     int choice;

//     do {
//         std::cout << "\nTechnoesis Management System Menu:\n";
//         std::cout << "1. Add artist\n";
//         std::cout << "2. Delete artist\n";
//         std::cout << "3. Edit srtist\n";
//         std::cout << "4. Show All artist\n";
//         std::cout << "5. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;
//         std::cin.ignore(); // Clear the input buffer

//         switch (choice) {
//             case 1:
//                 system.addMember();
//                 break;
//             case 2:
//                 system.deleteMember();
//                 break;
//             case 3:
//                 system.editMember();
//                 break;
//             case 4:
//                 system.showAllMembers();
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
