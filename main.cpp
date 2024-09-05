#include<bits/stdc++.h>
using namespace std;

#include "technoesis_central_system.cpp"
 #include "technical_event.cpp"
 #include "event.cpp"
 #include "organiser.cpp"

int main(){

      cout<<endl<<endl<<"<--------------------Technoesis MANAGEMENT SYSTEM--------------------->"<<endl<<endl;

while(1){
      int choose;
      cout<<"choose one of the option"<<endl; 
       cout<<"1.Technoesis"<<endl;
       cout<<"2.Technical_event"<<endl;
       cout<<"3.Event"<<endl;
        cout<<"4.Organiser"<<endl;
       cout<<"5.Exit"<<endl;
          cin>>choose;


          if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid choice.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        if(choose==1){
          TechneosisCentralSystem system;
    int choice;

    do {
        std::cout << "\nTechneosis Management System Menu:\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Delete Member\n";
        std::cout << "3. Edit Member\n";
        std::cout << "4. Show All Members\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                system.addMember();
                break;
            case 2:
                system.deleteMember();
                break;
            case 3:
                system.editMember();
                break;
            case 4:
                system.showAllMembers();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);
        }

          if(choose==2){
              
                TechnoesisCentralSystem system;
    int choice;

    do {
        std::cout << "\nTechnoesis Management System Menu:\n";
        std::cout << "1. Add artist\n";
        std::cout << "2. Delete artist\n";
        std::cout << "3. Edit srtist\n";
        std::cout << "4. Show All artist\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                system.addMember();
                break;
            case 2:
                system.deleteMember();
                break;
            case 3:
                system.editMember();
                break;
            case 4:
                system.showAllMembers();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);
          }

        if(choose==3){
              
              EventListManagementSystem system;
    int choice;

    do {
        std::cout << "\nEvent List Management System Menu:\n";
        std::cout << "1. Add Event\n";
        std::cout << "2. Delete Event\n";
        std::cout << "3. Edit Event\n";
        std::cout << "4. Show All Events\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                system.addEvent();
                break;
            case 2:
                system.deleteEvent();
                break;
            case 3:
                system.editEvent();
                break;
            case 4:
                system.showAllEvents();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);
          }
           if(choose==4){
              
               OrganiserTeamManagementSystem system;
    int choice;

   do {
        std::cout << "\nOrganiser Team Management System Menu:\n";
        std::cout << "1. Add Team\n";
        std::cout << "2. Delete Team\n";
        std::cout << "3. Edit Team\n";
        std::cout << "4. Show All Teams\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                system.addTeam();
                break;
            case 2:
                system.deleteTeam();
                break;
            case 3:
                system.editTeam();
                break;
            case 4:
                system.showAllTeams();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);
          }

          
          if(choose==5){break;}
}

}
