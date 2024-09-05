#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

class TechneosisMember {
private:
    std::string organiser_name;
    std::string director_name;
    std::string general_secretary_name;
    std::vector<std::string> sponsors_names;
    int total_fund_alloted;

public:
    // Constructor
    TechneosisMember(
        const std::string& on, const std::string& dn, const std::string& gsn,
        const std::vector<std::string>& sn, int tf)
        : organiser_name(on), director_name(dn), general_secretary_name(gsn),
          sponsors_names(sn), total_fund_alloted(tf) {}

    // Getters
    std::string getOrganiserName() const { return organiser_name; }
    std::string getDirectorName() const { return director_name; }
    std::string getGeneralSecretaryName() const { return general_secretary_name; }
    std::vector<std::string> getSponsorsNames() const { return sponsors_names; }
    int getTotalFundAlloted() const { return total_fund_alloted; }

    // Setters
    void setOrganiserName(const std::string& newName) { organiser_name = newName; }
    void setDirectorName(const std::string& newName) { director_name = newName; }
    void setGeneralSecretaryName(const std::string& newName) { general_secretary_name = newName; }
    void addSponsorName(const std::string& newName) { sponsors_names.push_back(newName); }
    void setTotalFundAlloted(int newTotalFund) { total_fund_alloted = newTotalFund; }

    // Function to display member details
    void displayDetails() const {
        std::cout << "Organiser Name: " << organiser_name << std::endl;
        std::cout << "Director Name: " << director_name << std::endl;
        std::cout << "General Secretary Name: " << general_secretary_name << std::endl;
        std::cout << "Sponsors Names: ";
        for (const auto& sponsor : sponsors_names) {
            std::cout << sponsor << ", ";
        }
        std::cout << std::endl;
        std::cout << "Total Fund Alloted: " << total_fund_alloted << std::endl;
    }
};

class TechneosisCentralSystem {
private:
    std::vector<TechneosisMember> members;

public:
    void addMember() {
        std::string organiser_name, director_name, general_secretary_name;
        std::vector<std::string> sponsors_names;
        int total_fund_alloted;
        std::string sponsor_name;
        int num_sponsors;

        std::cout << "Enter Organiser Name: ";
        std::getline(std::cin, organiser_name);
        std::cout << "Enter Director Name: ";
        std::getline(std::cin, director_name);
        std::cout << "Enter General Secretary Name: ";
        std::getline(std::cin, general_secretary_name);
        std::cout << "Enter the number of sponsors: ";
        std::cin >> num_sponsors;
        std::cin.ignore();
        for (int i = 0; i < num_sponsors; ++i) {
            std::cout << "Enter Sponsor Name: ";
            std::getline(std::cin, sponsor_name);
            sponsors_names.push_back(sponsor_name);
        }
        std::cout << "Enter Total Fund Alloted: ";
        std::cin >> total_fund_alloted;
        std::cin.ignore();

        members.push_back(TechneosisMember(organiser_name, director_name, general_secretary_name, sponsors_names, total_fund_alloted));
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
        TechneosisMember &member = members[memberIndex];
        std::string organiser_name;
        std::cout << "Enter new Organiser Name (leave blank to not change): ";
        std::getline(std::cin, organiser_name);
        if (!organiser_name.empty()) {
            member.setOrganiserName(organiser_name);
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
//     TechneosisCentralSystem system;
//     int choice;

//     do {
//         std::cout << "\nTechneosis Management System Menu:\n";
//         std::cout << "1. Add Member\n";
//         std::cout << "2. Delete Member\n";
//         std::cout << "3. Edit Member\n";
//         std::cout << "4. Show All Members\n";
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