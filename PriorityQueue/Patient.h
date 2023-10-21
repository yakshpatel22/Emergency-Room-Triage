/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the header class for patients which includes the constructor ,ailment function and getters
*File Name           :Patients.h
*Version             :1.0.0
*/
#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;

public:
	// Writing poublic constructor named Patient 
	Patient();
	Patient(const std::string& name);

	//Writing Ailment function
	void add_ailment(const Ailment& ailment);

	//Writting Getter function
	//Here we will write 3 getter functions for name- get_name() ,
	//ailment-get_ailemnt() and for score-get_score()
	std::string get_name() const;
	const LinkedList<Ailment>& get_ailments() const;
	int get_score() const;

	//Writing an Operators
	bool operator==(const Patient& patient) const;
};

//Printing the patient's details on the output stream to the user
std::ostream& operator<< (std::ostream& os, const Patient& patient);
