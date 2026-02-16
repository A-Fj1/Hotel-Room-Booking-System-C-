#include <iostream>
using namespace std;
// Arrays to booking rooms
int roomNumbers[100];        
int roomAvailability[100];   // 1 = Available, 0 = Booked
int customerIDs[100];        // customer IDs for booked rooms
int bookedRoomNumbers[100];  
int roomTypes[100];          // 1 = Single, 2 = Double
int bookingCount = 0;        
int roomCount = 0;           
// Function to initialize all arrays and counters
void init() {
   for (int i = 0; i < 100; i++) {
       roomNumbers[i] = 0;        
       roomAvailability[i] = 0;
       customerIDs[i] = 0;        
       bookedRoomNumbers[i] = 0;
       roomTypes[i] = 0;        
   }
   bookingCount = 0;             //Reset count
   roomCount = 0;                //Reset count
}
// Function to add rooms 
int addRooms() {
   int num;
   if (roomCount >= 100) {       //set the maximum
       cout << "Cannot add more rooms. Maximum room count reached.\n";
       return roomCount;
   }
   cout << "Enter the number of rooms to add: ";
   cin >> num;
   if (num <= 0) {               //Check for input
       cout << "Please enter a positive number of rooms.\n";
       return roomCount;
   }
   //Loop to add room 
   for (int i = 0; i < num; i++) {
       if (roomCount < 100) {
           cout << "Enter Room Number: ";
           cin >> roomNumbers[roomCount];
           int roomTypeInput;
           while (true) {        //room type input
               cout << "Enter Room Type (1 = Single, 2 = Double): ";
               cin >> roomTypeInput;
               if (roomTypeInput == 1 || roomTypeInput == 2) {
                   roomTypes[roomCount] = roomTypeInput;
                   break;       //Exit loop if input is valid
               } else {
                   cout << "Invalid input. Please enter 1 or 2.\n";
               }
           }
           roomAvailability[roomCount] = 1; //Mark room as available
           roomCount++;                      
           cout << "Room added successfully.\n";
       }
   }
   return roomCount;
}
//Function to display all available rooms
int displayAvailableRooms() {
   int availableCount = 0;         
   cout << "Available Rooms:\n";
   for (int i = 0; i < roomCount; i++) {
       if (roomAvailability[i] == 1) { 
           cout << "Room Number: " << roomNumbers[i] << " Type: ";
           if (roomTypes[i] == 1) {
               cout << "Single";
           } else {
               cout << "Double";
           }
           cout << "\n";
           availableCount++;
       }
   }
   return availableCount;         //Return total available rooms
}
//Function to book a room
int bookRoom() {
   int roomNumber, customerID;
   cout << "Enter Room Number to book: ";
   cin >> roomNumber;
   //Search for the room in the array
   for (int i = 0; i < roomCount; i++) {
       if (roomNumbers[i] == roomNumber && roomAvailability[i] == 1) {
           cout << "Enter Customer ID: ";
           cin >> customerID;
           customerIDs[bookingCount] = customerID;          //add customer ID
           bookedRoomNumbers[bookingCount] = roomNumber;    // add booked room number
           bookingCount++;                                  // booking count
           roomAvailability[i] = 0; // Mark room as booked
           cout << "Room booked successfully.\n";
           return 1;
       }
   }
   cout << "Room not available or does not exist.\n";
   return 0;
}
// Function to check booking status of a room
int checkBookingStatus() {
   int roomNumber;
   cout << "Enter Room Number to check: ";
   cin >> roomNumber;
   // Search for the room in bookedRoomNumbers
   for (int i = 0; i < bookingCount; i++) {
       if (bookedRoomNumbers[i] == roomNumber) { // If room is found
           cout << "Room Number: " << roomNumber
<< " is booked by Customer ID: " << customerIDs[i] << "\n";
           return 1;
       }
   }
   cout << "Room is available or not booked yet.\n";
   return 0;
}
// Function to display menu options and get user's choice
int displayMenu() {
   int choice;
   cout << "Hotel Room Booking System\n";
   cout << "1. Add Rooms\n";
   cout << "2. Display Available Rooms\n";
   cout << "3. Book Room\n";
   cout << "4. Check Booking Status\n";
   cout << "5. Exit\n";
   cout << "Enter your choice: ";
   cin >> choice;
   return choice;
}
//Main function to run the program
int main() {
   init(); //Initialize arrays and counters
   int choice = 0;
   //Loop to handle user input until they choose to exit
   while (choice != 5) {
       cout << "---------------------\n\n";
       choice = displayMenu();
       if (choice == 1) {
           addRooms();
       } else if (choice == 2) {
           displayAvailableRooms();
       } else if (choice == 3) {
           bookRoom();
       } else if (choice == 4) {
           checkBookingStatus();
       } else if (choice == 5) {
           cout << "Exiting program. Goodbye!\n";
       } else {
           cout << "Invalid choice. Please try again.\n";
       }
   }
   return 0;
}
