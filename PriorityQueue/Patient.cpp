/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the  class for patients which implements the constructor ,ailment function and getters from the header class
*File Name           :Patients.cpp
*Version             :1.0.0
*/
#include "Patient.h"

// Constructor
Patient::Patient() : name_(), ailments_()
{
}

Patient::Patient(const std::string& name) : name_(name), ailments_()
{
}

// Ailment functions
void Patient::add_ailment(const Ailment& ailment)
{
    ailments_.push_back(ailment);
}

// Getter functions
std::string Patient::get_name() const
{
    return name_;
}

const LinkedList<Ailment>& Patient::get_ailments() const
{
    return ailments_;
}

int Patient::get_score() const
{
    int score = 0;

    // Loop through each ailment and compute the score for each in a for loop
    // Add all the scores for each element
    for (auto* ailment = ailments_.begin(); ailment != nullptr; ailment = ailment->next)
    {
        score += ailment->data.get_severity() * ailment->data.get_time_sensitivity() + ailment->data.get_contagiousness();
    }

    return score;
}

bool Patient::operator==(const Patient& patient) const
{
    // Comparing the name
    if (patient.name_ != name_)
        return false;

    //Comparing the number of ailments
    if (patient.ailments_.size() != ailments_.size())
        return false;

    //Comparing the ailments one-by-one
    for (auto* ailment1 = ailments_.begin(), *ailment2 = patient.ailments_.begin();
         ailment1 != nullptr;
         ailment1 = ailment1->next, ailment2 = ailment2->next)
    {
        if (ailment1->data != ailment2->data)
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<< (std::ostream& os, const Patient& patient)
{
    //Printing name and score
    os << patient.get_name() << " - ";
    os << patient.get_score() << " - ";

    //Printing ailments
    for (auto* ailment = patient.get_ailments().begin(); ailment; ailment = ailment->next)
    {
        os << ailment->data.get_name() << ", ";
    }

    return os;
}