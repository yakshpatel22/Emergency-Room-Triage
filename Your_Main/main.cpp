/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the main for this program where we will create a program object andwhere the printing of the welcom screen 
					  and menu would be initialized and the mwnu would be in a while loop which will run till not pressed'0'
*Version             :1.0.0
*/
#include "Triage.h"

int main(int argc, char* argv[])
{
	// Creating the program object which will be used 
	Triage triage;

	// Printing the welcom screen of Fanshawe Medical Centre W2022
	triage.print_welcome_screen(std::cout);

	// Writing a while loop so that the triage program runs till not pressed 0 which is exit by the user
	while (triage.run(std::cin, std::cout));

	return 0;
}
