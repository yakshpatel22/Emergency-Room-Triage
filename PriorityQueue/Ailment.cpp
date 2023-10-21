/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing Ailment class which uses the consructors,getters and comparision operator from header file .
*File Name           :Ailment.cpp
*Version             :1.0.0
*/
#include "Ailment.h"

Ailment::Ailment() : 
    name_(), severity_(0), time_sensitivity_(0), contagiousness_(0)
{
}

Ailment::Ailment(const std::string& name, int severity, int time_sensitivity, int contagiousness) :
    name_(name), severity_(severity), time_sensitivity_(time_sensitivity), contagiousness_(contagiousness)
{
}

std::string Ailment::get_name()
{
    return name_;
}

int Ailment::get_severity()
{
    return severity_;
}

int Ailment::get_time_sensitivity()
{
    return time_sensitivity_;
}

int Ailment::get_contagiousness()
{
    return contagiousness_;
}

bool Ailment::operator==(const Ailment& ailment) const
{
    //Checking all the parts for equality
    return ailment.name_ == name_ && ailment.severity_ == severity_
        && ailment.time_sensitivity_ == time_sensitivity_ && ailment.contagiousness_ == contagiousness_;
}

bool Ailment::operator!=(const Ailment& ailment) const
{
    //Doing the == operation and negate it
    return !(*this == ailment);
}