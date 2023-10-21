/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing a header class named Ailmentwhich includes all the constructors, getters and comparision operator.
*File Name           :Ailment.h
*Version             :1.0.0
*/
#pragma once

#include <string>

class Ailment
{
private:
    std::string name_;
    int severity_;
    int time_sensitivity_;
    int contagiousness_;

public:
    // Constructors
    Ailment();
    Ailment(const std::string& name, int severity, int time_sensitivity, int contagiousness);

    // Getter functions
    std::string get_name();
    int get_severity();
    int get_time_sensitivity();
    int get_contagiousness();

    // Comparison operator
    bool operator==(const Ailment& ailment) const;
    bool operator!=(const Ailment& ailment) const;
    
};
