/*
 * Program name: Assignment1.cpp
 * 
 * Purpose: Unit Conversion from Tons to Various Weight Units.
 *          This program reads a weight value in tons from an input file, converts it
 *          into pounds, ounces, kilograms, and grams, and writes the results to an
 *          output file along with the conversion factors.
 *
 * Features:
 *        - Input validation: Accepts only values between 1 and 9 tons.
 *        - Outputs the converted values with a precision of two decimal points.
 *        - Displays the corresponding conversion factors for each unit.
 
 * Author:  Arpit Dahiya
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ifstream iii; // Input file buffer
    ofstream ooo; // Output file buffer

    iii.open("tons.txt"); // Open the input file

     if (!iii) //Unsuccessful
    {
        //Printing error message
        cout << "There was an error opening the input file(tons.txt).\nExiting....";
        return 1; //Stopping the Program
    }

    ooo.open("report.txt"); // Open the output file

     if (!ooo)
    {
        //Printing error message
        cout << "There was an error opening the output file(report.txt).\nExiting....";
        return 1; //Stopping the program
    }


    int tons, lb, oz, kg, g; // Declaring variables to hold weight values in different units

   
    iii >> tons; // Reading the weight in tons from the input file

    // Validating input to ensure it's between 1 and 9 tons
    if (tons > 0 && tons < 10)
    {
        // Doing conversions from tons to other weight units
        lb = tons * 2000;    // Conversion to pounds
        oz = tons * 32000;   // Conversion to ounces
        kg = tons * 907.185; // Conversion to kilograms
        g = tons * 907184.74; // Conversion to grams

        ooo << "\nHere are the conversions of the number you provided:-\n\n\n"; // Declaring the output

        // Writing converted values and their conversion factors onto the output file
        ooo << "Weight in pounds: " << lb << " lb"
            << setw(40) << "1 ton = 2000 pounds" << endl;

        ooo << "Weight in ounces: " << oz << " oz"
            << setw(40) << "1 ton = 32000 ounces" << endl;

        ooo << "Weight in kilograms: " << kg << " kg"
            << setw(40) << "1 ton = 907.185 kilograms" << endl;

        ooo << "Weight in grams: " << g << " g"
            << setw(40) << "1 ton = 907184.74 grams" << endl;
    }
    else
    {
        ooo << "Invalid input. Please enter a value from 1 to 9 tons in the input file(tons.txt)."; // Message for invalid input
    }

    iii.close(); //Close the input file
    ooo.close(); //Close the output file

    return 0; //Close the Program
}