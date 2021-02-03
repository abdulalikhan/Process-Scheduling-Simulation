#include "StdAfx.h"
#include "process.h"

// Default Constructor
Process::Process(){
	procID = priority = 0;
	arrivalTime = 0;
	burstTime = startTime = completionTime = turnAroundTime = waitTime = responseTime = 0;
}

// Parameterized Constructor #1
// Arguments: process ID, arrival time, burst time
Process::Process(int procID, double arrivalTime, double burstTime){
	this->procID = procID;
	this->arrivalTime = arrivalTime;
	this->burstTime = burstTime;
	priority = 0;
	startTime = completionTime = turnAroundTime = waitTime = responseTime = 0;
}

// Parameterized Constructor #2
// Arguments: process ID, priority, arrival time and burst time
Process::Process(int procID, int priority, double arrivalTime, double burstTime){
	this->procID = procID;
	this->priority = priority;
	this->arrivalTime = arrivalTime;
	this->burstTime = burstTime;
	startTime = completionTime = turnAroundTime = waitTime = responseTime = 0;
}

int Process::getProcID() const{
	return procID;
}

int Process::getPriority() const{
	return priority;
}

double Process::getArrivalTime() const{
	return arrivalTime;
}

double Process::getBurstTime() const{
	return burstTime;
}

double Process::getStartTime() const{
	return startTime;
}

double Process::getCompletionTime() const{
	return completionTime;
}

double Process::getTurnAroundTime() const{
	return turnAroundTime;
}

double Process::getWaitTime() const{
	return waitTime;
}

double Process::getResponseTime() const{
	return responseTime;
}

void Process::setPriority(int priority){
	this->priority = priority;	
} 

void Process::setStartTime(double startTime){
	this->startTime = startTime;
}

void Process::setCompletionTime(double completionTime){
	this->completionTime = completionTime;
}

void Process::setTurnAroundTime(double turnAroundTime){
	this->turnAroundTime = turnAroundTime;
}

void Process::setWaitTime(double waitTime){
	this->waitTime = waitTime;
}

void Process::setResponseTime(double responseTime){
	this->responseTime = responseTime;
}

bool Process::operator< (const Process& rhs){
	if (arrivalTime<rhs.arrivalTime)
		return true;
	return false;
}

bool Process::operator> (const Process& rhs){
	if (priority>rhs.priority)
		return true;
	return false;
}

bool Process::operator== (const Process& rhs){
	if ((procID == rhs.procID) && (priority == rhs.priority) && (arrivalTime == rhs.arrivalTime) && 
		(burstTime == rhs.burstTime) && (startTime == rhs.startTime) && 
		(completionTime == rhs.completionTime) && (turnAroundTime == rhs.turnAroundTime) && 
		(waitTime == rhs.waitTime) && (responseTime == rhs.responseTime))
		return true;
	return false;
}

Process& Process::operator= (const Process& rhs){
	if (this != &rhs){
		procID = rhs.procID;
		priority = rhs.priority;
		arrivalTime = rhs.arrivalTime;
		burstTime = rhs.burstTime;
		startTime = rhs.startTime;
		completionTime = rhs.completionTime;
		turnAroundTime = rhs.turnAroundTime;
		waitTime = rhs.waitTime;
		responseTime = rhs.responseTime;
	}
	return (*this);
}