# Bus Management System

This program implements a simple Bus Management System that allows users to reserve seats, check seat availability, delete customer records, search for customers, display seating charts, display all customer records, check traveler legality, and update loyalty points.

## How to Use

1. Reserve a Seat
   - Choose option 1 to reserve a seat.
   - Select whether you're a new customer (1) or an existing customer (2).
   - Fill in the customer's details and select a seat to reserve.

2. Check Seat Availability
   - Choose option 2 to check seat availability.
   - Enter the row and column to check seat availability.

3. Delete Customer
   - Choose option 3 to delete a customer record.
   - Enter the customer's ID to be deleted.

4. Search Customer
   - Choose option 4 to search for a customer by ID.
   - Enter the customer's ID to search.

5. Display Seating Chart
   - Choose option 5 to display the seating chart.

6. Display All Customer Records
   - Choose option 6 to display all customer records.

7. Check Traveler Legality (for Managers)
   - Choose option 7 to check the legality of a traveler.
   - Enter the customer's ID to check.

8. Update Loyalty Points
   - Choose option 8 to update a customer's loyalty points.
   - Enter the customer's ID and the points to add.

9. Exit
   - Choose option 0 to exit the program.

## Code Structure

The program consists of several functions and structs:
- Customer and Ticket structs to represent customer and ticket information.
- Functions to reserve a seat, check seat availability, display the seating chart, add a customer, generate a ticket and receipt, search for a customer, delete a customer, calculate the price, display all customer records, check traveler legality, update loyalty points, and manage the main reservation process.
- The main function handles the user interface and menu choices.

## File Handling
- Customer data is stored in a file named "info.txt".
- Functions read and write customer data to/from this file.

## Seat Reservation
- The program uses a 2D array to represent seat availability, with false indicating an available seat and true indicating an occupied seat.

Feel free to explore and utilize the features of this Bus Management System!
