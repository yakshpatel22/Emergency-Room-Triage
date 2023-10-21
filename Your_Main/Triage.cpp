/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
 *Purpose of file    :Creating a file named Triage.cpp for creating and displaying the main menu for the Fanshawe College Medical Centre
                      W2022.  Similarly, in this file we will include the Triage.h which is a header file which we have created where we 
                      stored all void and boolean function which we will be utilizing in this file. Likweise it has linked all the other
                      header files as well.This file would include all the functions which would be utilized in the menu.
*File Name           :Triage.cpp
*Version             :1.0.0
*/

/*
*PSEUDO CODE:-
*1.Creating a void function for displaying the welcom screen which is the name of the program as well as the coder's 
   name (Yaksh Shaileshbhai Patel)
*2.Creating a void function for displaying the menu to the screen and showing all the options availeble to the user which is triage nurses.
*3.Creating a void function named flush in the Triage class as that we can flush and start from beginning if the user wants.
*4.Writing a bool function named run which would be passing the output to the screen and where we will utilize the above created functions .
*5.After displaying the welcome screen and the main menu in the run function we will now write the switch statements which will 
   pass the options available to the user which is option 1 to 6 and 0 would be used for exiting the menu options. Likewise, the
   default would be "Unknown selection"  if any other number or letters are pressed other than 0, or 1-6.
*6.Now we would be writing all the rest functions which are the choices available in the menu provided to the user.
*7.They are add_patient, process_next_patient ,display_queue, view_history, load_queue,save_queue,exit.
*8.The load query and save query are the functions where we would implement the bonus part of this project which is the loading the csv
   file in the main menuse and saving it afterwords.
*/

#include "Triage.h"

Triage::Triage()
{}

//Writing a void function named print_welcome_screen and as it is an ostream so it would be 
//responsible for showing the output to trhe screen 
void Triage::print_welcome_screen(std::ostream& os)
{
    os << "****************************************************" << std::endl;
    os << "* Welcome to Fanshawe College Medical Center W2022 *" << std::endl;
    os << "* <Yaksh Shaileshbhai Patel>                       *" << std::endl;
    os << "****************************************************" << std::endl;
}


//Writing a void function named print_menu which is also an ostream aliased as 'os' 
void Triage::print_menu(std::ostream& os)
{
    os << std::endl;
    os << "Please Make A Selection:" << std::endl << std::endl;
    os << "\t1 - Add Patient" << std::endl;
    os << "\t2 - Process Next Patient In Queue" << std::endl;
    os << "\t3 - Display Queue" << std::endl;
    os << "\t4 - View Processed Patients History" << std::endl;
    os << "\t5 - Load Queue" << std::endl;
    os << "\t6 - Save Queue" << std::endl;
    os << "\t0 - Exit" << std::endl;
}


//Creating a void function named flush in the Triage class as that we can flush and start from beginning if the user wants
void Triage::flush(std::istream& is, char delim = '\n')
{
    is.ignore(std::numeric_limits<std::streamsize>::max(), delim);
}


//Writing bool function named run where we would be using both input stream and output stream which we aliased as 'os' in the above both functions
//Similarly here we would be using switch statements instred of if else as it would be more appropriate and would be more structured. 
bool Triage::run(std::istream& is, std::ostream& os)
{
    int choice = 0;

    //Printing the menu to the user by using Ooutput stream and passing it into the print_menu function
    print_menu(os);

    os << ">";
    is >> choice;
    flush(is);

    //Printing a new line for space between the menu and the choice made
    os << std::endl;

    //Writing a switch function named 'choice' and assigning appropriate cases from 1 to 6, and 0 for exit and the default 
    //would show 'Unknown selection' if any else number is pressed or any other word or any other character is even pressed. 
    switch (choice)
    {
    case 1:
        return add_patient(is, os);
    case 2:
        return process_next_patient(is, os);
    case 3:
        return display_queue(is, os);
    case 4:
        return view_history(is, os);
    case 5:
        return load_queue(is, os);
    case 6:
        return save_queue(is, os);
    case 0:
        return exit(is, os);
    default:
        os << "Unknown selection." << std::endl;
        return true;
    }
}


//Writing bool function named add_patients where we would be using to enter the name of the patients as well as all the other
//informations like ailment,severity,time_criticality and contragiousness in for loop.
bool Triage::add_patient(std::istream& is, std::ostream& os)
{
    std::string name, ailment;
    int severity, time_criticality, contagiousness;

    os << "Enter patient name: ";
    std::getline(is, name);

    //Creating a patient object where we would be inputting the name of the patient
    Patient patient(name);

    //Creating an infinite for loop for gathering all the required informations for the patients.
    for (;;)
    {
        os << "\tEnter ailment (leave blank when done): ";
        std::getline(is, ailment);

        if (ailment.empty())
            break;

        os << "\tEnter severity: ";
        is >> severity;
        flush(is);

        os << "\tEnter time criticality: ";
        is >> time_criticality;
        flush(is);

        os << "\tEnter contagiousness: ";
        is >> contagiousness;
        flush(is);

        os << std::endl;

        //Adding the  ailment list
        patient.add_ailment(Ailment(ailment, severity, time_criticality, contagiousness));
    }

    //At last adding the patients to the queue
    queue.enqueue(patient);

    return true;
}


//Writing bool function named process_next_patient which removes the patient from the queue with the highest 
//priority score and shows which patient is next.
bool Triage::process_next_patient(std::istream& is, std::ostream& os)
{
    //Writing an if statement to Check if queue is empty or not 
    if (queue.empty())
    {
        os << "Queue is empty. No patient was moved." << std::endl;
        return true;
    }

    Patient patient = queue.dequeue();

    //Displaying a print message on the screen for the patient being served
    os << patient.get_name() << " moved to the patient room!" << std::endl;

    // An if statement for displaying the patient with the next highest priority score
    if (!queue.empty())
    {
        Patient top = queue.peek();

        os << "Next in queue: " << top.get_name()
            << " with a priority score " << top.get_score() << std::endl;
    }

    //Adding customer to teh history
    history.push_back(patient);
    
    return true;
}


//Writing bool function named display_queue which Displays the patients in the queue including the following information ,
//Position in queue ,Patient Name ,Priority Score,Ailments
bool Triage::display_queue(std::istream& is, std::ostream& os)
{
    os << "Patients In Queue:" << std::endl << std::endl;

    //Creating a foor loop for Looping through each patient in the queue
    int count = 0;
    for (auto* patient = queue.begin(); patient; patient = patient->next)
    {
        os << count << " : " << patient->data << std::endl;
        count++;
    }

    //Printing message for no patients in the queue using an if statement
    if (count == 0)
        os << "Empty queue" << std::endl;

    return true;
}


//Writing bool function named view_history which will displays a list of patients that have been processed
//First of all it will show the Most recently treated patient first
//and then their informations inorder of Patient Priority and Ailments
bool Triage::view_history(std::istream& is, std::ostream& os)
{
    os << "History:" << std::endl;

    // For Loop which will loop through each item in the patient list
    int count = 0;
    for (auto* patient = history.begin(); patient; patient = patient->next)
    {
        os << patient->data << std::endl;
        count++;
    }

    //If there are no history then printing the message 'No history' which is written in an if statement
    if (count == 0)
        os << "No history" << std::endl;

    return true;
}


//Writing bool function named load_queue which will Prompts the user to enter a path to a csv file containing
//a list of patients. 
bool Triage::load_queue(std::istream& is, std::ostream& os)
{
    std::string file;

    //it will Loads the patients from the file into the queue
    os << "Enter path to file: ";
    std::getline(is, file);

    //An ifstream function for Opening the csv file
    std::ifstream csv(file);
    if (!csv.is_open())
    {
        //An Can't open file error message will show if the file path is incorrect or cant locate the file 
        os << "Can't open file." << std::endl;
        return true;
    }

    //Reading the csv file 
    std::string name, ailment;
    int ailments, severity, time_criticality, contagiousness, new_patients = 0;

    //Skipping the header
    std::getline(csv, name);
    
    //Read the name first which is contained in a while loop
    while (std::getline(csv, name, ','))
    {
        //Creating patient object
        Patient patient(name);

        //Reading the number of ailments
        csv >> ailments;
        flush(csv, ',');

        //Reading the ailments which are in a for loop
        for (int i = 0; i < ailments; i++)
        {
            std::getline(csv, ailment, ',');
            
            csv >> severity;
            flush(csv, ',');

            csv >> time_criticality;
            flush(csv, ',');

            csv >> contagiousness;

            // Read for another if reader is not in the end
            if (i < ailments - 1)
                flush(csv, ',');
            //Reading till the end of line 
            else
                flush(csv);

            //At last Addiing the ailment
            patient.add_ailment(Ailment(ailment, severity, time_criticality, contagiousness));
        }

        //Adding new patient to queue after reading from the csv file 
        queue.enqueue(patient);

        new_patients++;
    }

    //closing the csv file
    csv.close();

    //At last showing the number of added patients which are added to the queue after reading from the csv file
    os << new_patients << " additional patient(s) are added to queue" << std::endl;

    return true;
}


//Writing bool function named save_queue which is the BONUS part of thsi assignment, and this function will 
//Prompts the user to enter a path to a file to write the patient data from the queue to.
bool Triage::save_queue(std::istream& is, std::ostream& os)
{
    std::string file;

    //Entering the destination which is the path of the file from the user
    os << "Enter path to file: ";
    std::getline(is, file);

    // Opening the csv file
    std::ofstream csv(file);
    if (!csv.is_open())
    {
        //An Can't open file error message will show if the file path is incorrect or cant locate the file 
        os << "Can't open file." << std::endl;
        return true;
    }

    //This time we will not skip and we will now print the header
    size_t maxAilmentCount = 0;

    for (auto* patient = queue.begin(); patient; patient = patient->next)
    {
        size_t curCount = patient->data.get_ailments().size();

        if (curCount > maxAilmentCount)
            maxAilmentCount = curCount;
    }

    //Writing the header of csv file in order
    csv << "Name,Number of Ailments";
    for (size_t i = 1; i <= maxAilmentCount; i++)
    {
        csv << ",Name_" << i;
        csv << ",Severity_" << i;
        csv << ",Time_Criticality_" << i;
        csv << ",Contagiousness_" << i;
    }
    csv << std::endl;

    //Writing the csv file
    int saved_patients = 0;
    for (auto* patient = queue.begin(); patient; patient = patient->next)
    {
        //Taking patient's basic details
        csv << patient->data.get_name() << ",";
        csv << patient->data.get_ailments().size();

        // Adding  the ailments
        for (auto* ailment = patient->data.get_ailments().begin(); ailment; ailment = ailment->next)
        {
            csv << "," << ailment->data.get_name();
            csv << "," << ailment->data.get_severity();
            csv << "," << ailment->data.get_time_sensitivity();
            csv << "," << ailment->data.get_contagiousness();
        }

        // Writing the new line
        csv << std::endl;

        saved_patients++;
    }
    //Closing the csv file
    csv.close();

    os << saved_patients << " patient(s) in queue are saved" << std::endl;

    return true;
}


// Writing bool function named exit which will be used if the user presses '0' as the input and wants to exit the Fanshawe Medical Centre W2022 
bool Triage::exit(std::istream& is, std::ostream& os)
{
    //Only here we will make the return statement of this function to false and as it is a boolean function it will exit the program
    return false;
}