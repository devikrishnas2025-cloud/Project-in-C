//Bus Reservation System using C
#include <stdio.h>
#include <string.h>
//Defining structure to store bus details
struct Bus{
    int bus_id;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
};
//Defining structure to store user details
struct User{
    char username[50];
    char password[50];
};

//defining the function displayMainMenu to display the main menu
void displayMainMenu(){
    printf("\n----- Main Menu -----\n");
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}
//defining the function displayUserMenu to display the user menu
void displayUserMenu(){
    printf("\n----- User Menu -----\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
}

//defining the function loginUser which perform user login
int loginUser(struct User users[], int NumUsers,char username[],char password[]){
    for(int i=0;i<NumUsers;i++){
        if(strcmp(users[i].username,username)==0 && strcmp(users[i].password,password)==0){
            return i;
        }

    }
    return -1;
}
//defining the function Bookticket for booking ticket
void Bookticket(struct Bus buses[],int NumBuses){
    int bus_id;
    printf("Enter the Bus Number:\n");
    scanf("%d",&bus_id);
//Finding the bus with given bus number
       int busindex=-1;
       for(int i=0;i<NumBuses;i++){
        if(buses[i].bus_id==bus_id){
         busindex=i;
         break;

                }
            
    }
if(busindex==-1)
{
    printf("Bus with %d bus number not found\n",bus_id);
}
else{
    printf("Enter the number of seats:");
    int seatToBook;
    scanf("%d",&seatToBook);

if(buses[busindex].availableSeats<seatToBook){
    printf("Sorry No seats available in bus number=%d",bus_id);
}
else{
    buses[busindex].availableSeats-=seatToBook;
    printf("Booking Successful! Seat has been reserved.\n");
    printf("Your bus number = %d\n", bus_id);
}
}
}

//defining function cancelTicket for cancelling ticket
void cancelTicket(struct Bus buses[],int NumBuses){
    int bus_id;
    printf("Enter the Bus Number:\n");
    scanf("%d",&bus_id);
//Finding the bus with given bus number
       int busindex=-1;
       for(int i=0;i<NumBuses;i++){
        if(buses[i].bus_id==bus_id){
         busindex=i;
         break;
        }
            }
if(busindex==-1)
{
    printf("Bus with %d bus number not found\n",bus_id);
}
else{
    printf("Enter the number of seats to cancel:");
    int seatsToCancel;
    scanf("%d",&seatsToCancel);
if(seatsToCancel>buses[busindex].totalSeats-buses[busindex].availableSeats){
    printf("You can't cancel the seats than you were booked\n");
}
else{
    buses[busindex].availableSeats+=seatsToCancel;
    printf("Cancellation was successful!\n");
}
}
}
//defining function checkBusStatus for checking the bus status
void checkBusStatus(struct Bus buses[],int NumBuses){
printf("Enter the bus number:");
int bus_id;
scanf("%d",&bus_id);
int busindex=-1;
for(int i=0;i<NumBuses;i++){

if(buses[i].bus_id==bus_id){
busindex=i;
break;
}
}
if(busindex != -1){
    printf("Bus Number=%d\n",buses[busindex].bus_id);
    printf("Source=%s\n",buses[busindex].source);
    printf("Destination=%s\n",buses[busindex].destination);
    printf("Total Seats=%d\n",buses[busindex].totalSeats);
    printf("Available Seats=%d\n",buses[busindex].availableSeats);
    printf("Fare=%.2f\n",buses[busindex].fare);
}
else{
   printf("No bus found with the bus number=%d\n",bus_id);

}
}

int main(){
    //Initialise bus data
    struct Bus buses[3]={
        {101,"Kottayam","Ernakulam",50,50,150},
        {102,"Kannur","Kozhikode",50,50,120},
        {103,"Alappuzha","Kottayam",50,50,90},

    };
    int NumBuses=3;
    struct User users[5]={
        //Initialise user data
        {"user1","pass1"},{"user2","pass2"},{"user3","pass3"},{"user4","pass4"},{"user5","pass5"}
    };
    int NumUsers=5;
    
    int loggedinID=-1;
    while(1){
        if(loggedinID==-1){
            displayMainMenu();
            int choice;
            scanf("%d",&choice);
        
        
            if(choice==1){
char username[50];
char password[50];
printf("Enter your Username:\n");
scanf("%s",username);
printf("Enter your Password:\n");
scanf("%s",password);
//calling the loginUser function
loggedinID=loginUser(users,NumUsers,username,password);

if(loggedinID==-1){
    printf("Login failed,check your username and password\n");
}
else{
    printf("Login successful!\n");
}
            }
            
 else if(choice==2){
    printf("Exit successful!\n");
    break;
}
    
else{
    printf("Invalid choice,Please try again:\n");
}
        
}
else{
    displayUserMenu();
            int userchoice;
            scanf("%d",&userchoice);
switch(userchoice){
    case 1:
    Bookticket(buses,NumBuses);
    break;
    case 2:
    cancelTicket(buses,NumBuses);
    break;
    case 3:
    checkBusStatus(buses,NumBuses);
    break;
    case 4:
    printf("Logout successful!\n");
    loggedinID=-1;
    break;
    default:
    printf("Invalid Choice:\n");
}
}
}
printf("\nThank you for using Bus Reservation System!\n");
return 0;
}








