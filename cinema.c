#include <stdio.h>

int main() {
   int tickets,movie,seat_type,booking_id=100,show_time;
   int price,total;
   char choice;
printf("*************************************************\n");
printf("*           WELCOME TO MAGIC CINEMAS            *\n");
printf("*************************************************\n");
do{
    
    
printf("----------------Movie Details--------------------\n");
printf("            1-Avengers-\n");
printf("            2-Frozen\n");
printf("            3-Home Alone\n");
printf("Please Select Movie:");
scanf("%d",&movie);
if(movie==1){
    printf("Selected Movie:Avengers\n");
}
else if(movie==2){
    printf("Selected Movie:Frozen\n");
}
else if(movie==3){
    printf("Selected Movie:Home Alone\n");
}
else{
    printf("Invalid Movie Selection");
    continue;
}
printf("-------------------Show Time--------------------\n");
printf("            1-10:00 AM\n");
printf("            2-2:00 PM\n");
printf("            3-7:00 PM\n");
printf("            4-10:00 PM\n");
printf("Select Show Time:");
scanf("%d",&show_time);
if(show_time==1){
    printf("Selected Show Time:Morning Show-10:00AM\n");
}
else if(show_time==2){
    printf("Selected Show Time:Matinee-2:00PM\n");
}
else if(show_time==3){
    printf("Selected Show Time:Evening Show-7:00PM\n");
    
}
else if(show_time==4){
    printf("Selected Show Time:Night Show-10:00PM\n");
}
else{
    printf("Invalid Show Time!\n");
    continue;
}
printf("----------------Seat Details--------------------\n");
printf("            1-Balcony:Price-250rs\n");
printf("            2-Deluxe:Price-200rs\n");
printf("            3-Regular:Price-150rs\n");
printf("Select Seat Type:");
scanf("%d",&seat_type);

if(seat_type==1){
    printf("Selected Seat:Balcony\n");
    price=250;
}
else if(seat_type==2){
    printf("Selected Seat:Deluxe\n");
    price=200;
}
else if(seat_type==3){
    printf("Selected Seat:Regular\n");
    price=150;
}
else{
    printf("Invalid seat type!\n");
    continue;
}
printf("Enter the Number Of Tickets:");
scanf("%d",&tickets);
total=price*tickets;
printf("------------Total----------------\n");
 
printf("Total:%drs\n",total);

printf("Your Booking Has Been Confirmed\n");
printf("Booking Id:MC%d\n",booking_id++);
printf("Enjoy the Movie!\n");

    printf("Do you want another booking(y/n)?");
    scanf(" %c",&choice);
     
}
while(choice=='y'||choice=='Y');
printf("\n=========================================\n");
printf("           BOOKING COMPLETED\n");
printf("=========================================\n");
return 0;
}