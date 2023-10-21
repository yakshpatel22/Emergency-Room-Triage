/*
*Author              :Yaksh Patel
*Student ID          :1033454
*Course              :INFO-3135-22WCE
*Professor name      :Professor Dennis Edin Ljeti
*Date                :10/02/2022
*Project 1 Name      :Project#1 - Emergency Room Triage
*Project's objective :Write a console program that will simulate a patient emergency room triage system with a priority patient queue.
*Purpose of File     :Writing the header class for PriorityQueue whichwill be used for changing the list of patients based on the score
*Version             :1.0.0
*/
#pragma once


template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;

public:
	PriorityQueue() {}

	//bool for checking if queue is empty or not 
	bool empty() const
	{
		return patients_.empty();
	}

	//Getting the size of the queue
	size_t size() const
	{
		return patients_.size();
	}

	//Adding a new patient in a void function named enqueue
	void enqueue(const T& patient)
	{
		//Finding the correct spot for the patient's score
		int score = patient.get_score();

		//Checking if linked list is empty or not in an if statement
		if (patients_.empty())
		{
			patients_.push_front(patient);
			return;
		}

		//Finding the insertion point based on score by an if statement in a for loop 
		for (auto* node = patients_.begin(); node; node = node->next)
		{
			if (node->data.get_score() < score)
			{
				patients_.insert(node, patient);
				return;
			}
		}

		patients_.push_back(patient);
	}

	//Removing the first patient in from list
	T dequeue()
	{
		return patients_.pop_front();
	}

	//Getting the patient on top of the list
	T peek()
	{
		return patients_.begin()->data;
	}

	//Getting the pointer to the top of the list
	auto* begin()
	{
		return patients_.begin();
	}


};
