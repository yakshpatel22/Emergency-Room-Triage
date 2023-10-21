/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the header class for Triage which cont6ains all the constructor and other boolean functions which will 
                      be used in Triage class to create the menu for the Fanshawe College Medical centre W2022.
*Version             :1.0.0
*/


#pragma once
#include "Patient.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include <iostream>
#include <string>
#include <fstream>

class Triage
{
    private:
        PriorityQueue<Patient> queue;
        LinkedList<Patient> history;

    // Used to flush the input stream up to a given character delimeter
    void flush(std::istream& is, char delim);

    public:
         // Default constructor named Triage
         Triage();

    //A void function to Print the welcome screen to the user 
    void print_welcome_screen(std::ostream& os);

    //A void function to print the menu to the screen for the user
    void print_menu(std::ostream& os);

    //Boolean function for runnning one step of the triage process
    bool run(std::istream& is, std::ostream& os);

    //Boolean Function for adding a new patient to the queue
    bool add_patient(std::istream& is, std::ostream& os);

    //Boolean function to process the next patient in the queue
    bool process_next_patient(std::istream& is, std::ostream& os);

    //Boolean function to display the contents of the queue
    bool display_queue(std::istream& is, std::ostream& os);

    //Boolean function to view the history of served patients
    bool view_history(std::istream& is, std::ostream& os);

    //Boolean function to load a queue from a file
    bool load_queue(std::istream& is, std::ostream& os);

    //Boolean function to save a queue to a file
    bool save_queue(std::istream& is, std::ostream& os);

    //Boolean function to Exit the program only here the function will returm false
    bool exit(std::istream& is, std::ostream& os);

};

