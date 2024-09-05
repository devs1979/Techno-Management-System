#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

class OrganiserTeam {
private:
    std::string event_name;
    std::vector<std::string> committee_members;

public:
    // Constructor
    OrganiserTeam(const std::string& name, const std::vector<std::string>& members)
        : event_name(name), committee_members(members) {}

    // Getters
    std::string getEventName() const { return event_name; }
    std::vector<std::string> getCommitteeMembers() const { return committee_members; }

    // Setters
    void setEventName(const std::string& newName) { event_name = newName; }
    void addCommitteeMember(const std::string& member) { committee_members.push_back(member); }
    void removeCommitteeMember(const std::string& member) {
        auto it = std::find(committee_members.begin(), committee_members.end(), member);
        if (it != committee_members.end()) {
            committee_members.erase(it);
        }
    }

    // Function to display team details
    void displayDetails() const {
        std::cout << "Event Name: " << event_name << std::endl;
        std::cout << "Organiser Team Committee Members: ";
        for (const auto& member : committee_members) {
            std::cout << member << ", ";
        }
        std::cout << std::endl;
    }
};

class OrganiserTeamManagementSystem {
private:
    std::vector<OrganiserTeam> teams;

public:
    void addTeam() {
        std::string event_name;
        std::vector<std::string> committee_members;
        std::string member;
        int num_members;

        std::cout << "Enter Event Name: ";
        std::getline(std::cin, event_name);
        std::cout << "Enter the number of committee members: ";
        std::cin >> num_members;
        std::cin.ignore();
        for (int i = 0; i < num_members; ++i) {
            std::cout << "Enter Committee Member Name: ";
            std::getline(std::cin, member);
            committee_members.push_back(member);
        }

        teams.push_back(OrganiserTeam(event_name, committee_members));
        std::cout << "Team added successfully." << std::endl;
    }

    void deleteTeam() {
        int teamIndex;
        showAllTeams();
        std::cout << "Enter the index of the team to delete (starting from 0): ";
        std::cin >> teamIndex;
        std::cin.ignore();

        if (teamIndex >= 0 && teamIndex < teams.size()) {
            teams.erase(teams.begin() + teamIndex);
            std::cout << "Team deleted successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No team deleted." << std::endl;
        }
    }

    void editTeam() {
        int teamIndex;
        showAllTeams();
        std::cout << "Enter the index of the team to edit (starting from 0): ";
        std::cin >> teamIndex;
        std::cin.ignore();

        if (teamIndex >= 0 && teamIndex < teams.size()) {
            OrganiserTeam &team = teams[teamIndex];
            std::string event_name;
            std::cout << "Enter new Event Name (leave blank to not change): ";
            std::getline(std::cin, event_name);
            if (!event_name.empty()) {
                team.setEventName(event_name);
            }

            std::cout << "Team edited successfully." << std::endl;
        } else {
            std::cout << "Invalid index. No team edited." << std::endl;
        }
    }

    void showAllTeams() const {
        if (teams.empty()) {
            std::cout << "No teams found." << std::endl;
            return;
        }

        for (const auto& team : teams) {
            team.displayDetails();
            std::cout << "-------------------------" << std::endl;
        }
    }
};

// int main() {
//     OrganiserTeamManagementSystem system;
//     int choice;

//     do {
//         std::cout << "\nOrganiser Team Management System Menu:\n";
//         std::cout << "1. Add Team\n";
//         std::cout << "2. Delete Team\n";
//         std::cout << "3. Edit Team\n";
//         std::cout << "4. Show All Teams\n";
//         std::cout << "5. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;
//         std::cin.ignore(); // Clear the input buffer

//         switch (choice) {
//             case 1:
//                 system.addTeam();
//                 break;
//             case 2:
//                 system.deleteTeam();
//                 break;
//             case 3:
//                 system.editTeam();
//                 break;
//             case 4:
//                 system.showAllTeams();
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
