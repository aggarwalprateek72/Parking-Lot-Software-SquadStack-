<h1>Parking Lot Software</h1>

<h2>Problem Statement</h2>
We own a parking lot that can hold up to ‘n’ cars at any given point in time. Each slot is given a number starting at one increasing with increasing distance from the entry point in steps of one. We want to create an automated ticketing system that allows our customers to use our parking lot without human intervention.

When a car enters the parking lot, we want to have a ticket issued to the driver. The ticket issuing process includes:- 
1. We are taking note of the number written on the vehicle registration plate and the age of the driver of the car.
2. And we are allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are kind enough to always park in the slots allocated to them).

The customer should be allocated a parking slot that is nearest to the entry. At the exit, the customer returns the ticket, marking the slot they were using as being available.
Due to government regulation, the system should provide us with the ability to find out:-
- Vehicle Registration numbers for all cars which are parked by the driver of a certain age,
- Slot number in which a car with a given vehicle registration plate is parked.
- Slot numbers of all slots where cars of drivers of a particular age are parked.

We interact with the system via a file-based input system, i.e. it should accept a filename as an input. The file referenced by filename will contain a set of commands separated by a newline, we need to execute the commands in order and produce output.

<h3>Prerequisites</h3>

- C++ Compiler (Preferably MinGW)
- Text Editor (Atom/Brackets)

<h3>Installing</h3>

1. Head to www.mingw.org and click the “Download/Installer” link to download the MinGW setup file, or 
- https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/ for Windows, 
- http://www.mingw.org/wiki/LinuxCrossMinGW for Linux
- https://brewinstall.org/Install-mingw-w64-on-Mac-with-Brew/ for Mac
2. After downloading, install MinGW and wait for the “MinGW Installation Manager” to show up.

    ![i1](https://user-images.githubusercontent.com/42617633/95651263-c6537680-0b06-11eb-9bd1-bdb19b602b33.png)
3. When the “MinGW Installation Manager” shows up, click on mingw32-gcc-g++ then select “Mark for Installation”

    ![i2](https://user-images.githubusercontent.com/42617633/95651262-c6537680-0b06-11eb-9219-ce9e6cfe72bc.png)
4. In the menu at the top left corner, click on “Installation  > Apply Changes”
    
    ![i3](https://user-images.githubusercontent.com/42617633/95651261-c5224980-0b06-11eb-87e2-41569268153f.png)
5. Wait and allow to install completely. Ensure you have a stable internet connection during this process.


<h3> Edit your PATH environment variable to include the directory where the C++ compiler is located </h3>

PATH is an environment variable on Unix-like operating systems, DOS, OS/2, and Microsoft Windows, specifying a set of directories where executable programs are located. 

After installing MinGW, it can be found in  C:\MinGW\bin. Now you have to include this directory in your environment variable PATH. If you've been using computers for a while now you should know how to do this already, but if you don't, here are a few resources:

- Click https://www.computerhope.com/issues/ch000549.htm for Windows Guide
- Click https://www.cyberciti.biz/faq/unix-linux-adding-path/ for Linux Guide
- Click https://hathaway.cc/2008/06/how-to-edit-your-path-environment-variables-on-mac/ for Mac OS Guide

<h3> Repository </h3>

The repository contains the following:
- C++ Solution Code

<h3> Learning Outcome </h3>

At the end of this project, we should be able to:
- solve the Parking Lot problem with data structures optimized for complexity
- write modular code using Classes
- utilize heap, hash map, find, erase, data structures in C++

<h3> Instructions </h3>
1. Git clone the project into desired folder in your computer using 

        git clone https://github.com/aggarwalprateek72/Parking-Lot-Software-SquadStack-.git


2. Add a new text file for input by name of your choice in the folder with main.cpp.

3. Open Command Prompt (in Windows) or Terminal (in Linux/Mac) and move to the project directory.


4. Compile the program using

        - Windows:
                 g++ -o program main.cpp 
                
        -Linux/Ubuntu:
                 g++ main.cpp 
                
        -MacOs:
                 make main


5. Run the program using 

        -Windows:
                 g++ -o program main.cpp&program.exe 
                
        -Linux:
                 ./a.out 
                
        -MacOs:
                 ./main 

<h3> Project Structure </h3>

- Parking Class to contain all the necessary Functions and Data Structures

    - Methods:
    
        1. register_new_vehicle() to register new user to the parking lot and assign closest slot to the entrance, which if full, would return empty string
        
        2. fetch_all_slots_for_age() Method to return all the slot numbers of cars for a given age, which if invalid would return empty vector(null)
        
        3. fetch_slot_number_for_reg_no() Method to return the parking slot for a given registration number, which if invalid would return -1
        
        4. fetch_all_reg_no_for_age() Method to return all the registration numbers of cars for a given age, which if invalid would return empty vector(null)
        
        5. user_leaving_parking() Method to empty the parking slot when the user leaves for given slot, and clearing all its stored value, if invalid, returns empty message
    
    - Data Structures:
    
        1. Priority Queue or Min-heap to store all the free slots in increasing order
        
        2. unordered_map<> to handle keys and values in order to fetch for specific age, slot, or registration number in Logarithmic time
        
        3. vector<> to store dynamic values from the query
        
- File Handling methods like ifstream and ofstream to read file given in input and write to a new/overwrite to existing file.
 
- Main Function to take the query type and calling the necessary functions and class
 

<h3> Sample Input </h3>

    Create_parking_lot 6 

    Park KA-01-HH-1234 driver_age 21 

    Park PB-01-HH-1234 driver_age 21

    Slot_numbers_for_driver_of_age 21

    Park PB-01-TG-2341 driver_age 40

    Slot_number_for_car_with_number PB-01-HH-1234

    Leave 2

    Park HR-29-TG-3098 driver_age 39

    Vehicle_registration_number_for_driver_of_age 18

<h3> Sample Output </h3>

    Created parking of 6 slots

    Car with vehicle registration number KA-01-HH-1234 has been parked at slot number 1

    Car with vehicle registration number PB-01-HH-1234 has been parked at slot number 2

    1,2

    Car with vehicle registration number PB-01-TG-2341 has been parked at slot number 3

    2

    Slot number 2 vacated, the car with vehicle registration number PB-01-HH-1234 left the space, the driver of the car was of age 21

    Invalid Command

    Car with vehicle registration number HR-29-TG-3098 has been parked at slot number 2

    No Registration Numbers for Given age has been parked. 

<h2> Assumptions </h2>

1. If the file name entered is invalid (file not present in the directory), it will print "Invalid File Name. Check for Case Sensitive" on the screen.

2. File name can be given with .txt extension or without .txt extension, the program will automatically consider both of the names in same way.

3. If there is no empty slot while a new user asks for ticket, it will add "No Empty Parking Space" to the output file.

4. For fetching slot numbers issued to given age, if there is no such value, it will add "NULL" to the output file.

5. For fetching slot numbers with given registration Numbers, if there is no such value, it will add "No such Car is Present" to the output file.

6. For user leaving the parking slot, if the slot number is already empty (i.e no car is parked on the queried slot number, it will add "No Car is Present at Slot Number "+ {slot number passed} to the output file.

7. For Fetch all registration numbers for given age, if their is no such values, it will add "No Registration Numbers for Given age has been parked." to the output file.

8. If the command doesn't match any of the given formats (in Problem Description), it will be considered invalid & will print "Invalid Command" on the screen.

9. After adding output to the new file, it will print "Results have been added to the output file named output.txt" on the screen.

10. For all the other cases/values, it will print "Invalid Option" on the screen.


