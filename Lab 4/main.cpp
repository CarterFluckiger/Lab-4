/*
Carter Fluckiger
C++ Fall 2019
Due: October 10, 2019
Lab 4 Temperature Output
Description:To design and write a C++ program that inputs a series of hourly
temperature from a file, and outputs a bar chart (using stars) of the temperatures for the day.
The temperature should be printed to the left of the corresponding bar, and there should be a
heading that gives the scale of the chart. The range of temperatures should be from
-30 to 120. Because it is hard to display 150 characters on the screen, you should have
each star represent a range of 3 degrees. That way, the bars will be at most 50
characters wide. Use meaningful variable names, proper indentation, and appropriate
comments. Thoroughly test the program using your own data sets. Make sure to vet the
values from the input file.

*/
#include <iostream>
#include <fstream>
#include <iomanip>
//The libraries used in this program
using namespace std;

int infile;
//integer used for infile in a while function
float userinput;
float subinput;
float negsubinput;
// Floats used for the userinput and the variables used for calculations of spaces and stars

int main()
{
    void lines();
    void stars();
    //The void functions used to calculate the stars and line spacing
    string fileinput ="/Users/tag1/Desktop/Lab 4/Lab 4/inputFile.dat";
    ifstream inFile;
    inFile.open(fileinput);
    //This is the functions that open the file with the data on it
    cout<<"Temperatures for 24 hours: "<< endl;
     cout<<"            "<<"-30"<<"         "<<"0"<<"         "<<"30"<<"        "<<"60"<<"        "<<"90"<<"        "<<"120"<< endl;
     // These are the cout statements that set up the format for the file output
     inFile>>userinput;
  // The first in read statement
   
     while (inFile)
     {
      //While function that runs if the file is valid and can be read
        if (-30 > userinput || userinput > 120)
        {
            cout<< "Invalid input"<<endl;
        }
         // This if function checks to see if the userinput is within the accepted range
       else if(-30<=userinput || userinput <= 120)
        {
            cout<<setw(7)<<userinput;
            
            stars();
            cout<<endl;
        }
         //This else if statement is used to find if the userinput is an accepted value and if
         // it is to set up the format to allow decimals to be used as an input
          inFile>>userinput;
         //Second read in statement
         if(!inFile)
         {
             cout<<"Input does not meet perameters or all numbers have been read"<<endl;
             return 1;
         }
         //This if statement allows that if the stream fails with a bad input a message
         //displays and the stream ends nicely
    }
    
    return 0;
}
void lines()
{
    cout<<"           "<<"\t"<<"\t"<<""<<"|";
}
//Void function that sets up the line spacing for positive inputs
void neglines()
{
    negsubinput = userinput;
    //This statement allows the user to use the userinput without actually changing it
    negsubinput = -30 - negsubinput;
    // This statement helps when finding the amount of spaces needed before stars start
    cout<<"\t"<<"  ";
    //This while function runs until the correct amount of spaces calculating that each star
    // is equal to 3
    while(negsubinput <= -1.5)
    {
    negsubinput = negsubinput + 3;
    cout<<" ";
    }
    //This while function that places the correct amount of spaces to line up with the program
}
//Void neglines is a function that sets up the spaces for negative inputs
//Void stars is the function that places the correct amount of stars for the inputs of the user
void stars()
{
    //This statement allows me to use a different variable that is equal to the userinput
          subinput = userinput;
    //The if statement is for the positive values
    if (subinput>0)
    {
         //call for the void function that puts the spaces in for positives userinput
        lines();
       //This while function subtracts a three from the userinput and places a star every time
        // the subinput meets the loop test and is true
        while (subinput>1.5)
        {
     subinput=subinput-3;
            //This subtracts three from the subinput every iteration allowing for the exact
            //amount of stars to be ouput to the screen
     cout<<"*";
            // This cout outputs a star for every iteration of the while statement
     }
    }
    //This if else statement is for inputs that are negative
        else if(subinput<0)
        {
            cout << "   ";
            // This cout is for formating
            neglines();
            //neglines is a void statement for setting spaces for negative number inputs
            while (subinput<-1.5)
            {
                subinput = subinput+3;
                //This statement allows for the correct amount of stars to be placed
                //through the calculations of adding three
                cout<<"*";
                //This cout is for outputing a star for every iteration
        }
            cout<<"|";
            //This cout is for formating
        }
    //This if statement is for if the userinput is zero
    if (userinput==0)
    {
        cout<<"                 |";
    }
}
