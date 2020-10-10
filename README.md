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
1. Git clone the project into desired folder in your computer using git clone https://github.com/aggarwalprateek72/Parking-Lot-Software-SquadStack-
2. Add a new text file for input by name of your choice in the folder with main.cpp.
3. Compile the program using <mark> g++ -o program main.cpp </mark>
4. Run the program using <mark> g++ -o program main.cpp&program.exe </mark>

<h3> Project Structure </h3>

