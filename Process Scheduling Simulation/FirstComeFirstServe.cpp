#include "StdAfx.h"
#include "FirstComeFirstServe.h"
#include "OutOfBoundsException.h"
#include <iostream>
#include <windows.h>
#include <math.h>
#include <iomanip>
using namespace std;

FirstComeFirstServe::FirstComeFirstServe(){
	noOfProcesses = 0;
	netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
}

FirstComeFirstServe::FirstComeFirstServe(int noOfProcesses, DynamicSafeArray<Process>& processArray){
	this->noOfProcesses = noOfProcesses;
	netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
	for (int i = 0; i<noOfProcesses; i++){
		try{
			readyqueue.enqueue(processArray[i]);
		}catch (OutOfBoundsException& e){
			e.what();
		}	
	}
}

void FirstComeFirstServe::showReadyqueue(){
	queue<Process> temp = readyqueue;
	Process currentProc;
	cout << "| ";
	while (!temp.isEmpty()){
		currentProc = temp.dequeue();
		cout << currentProc.getProcID() << " | ";
	}
}

void FirstComeFirstServe::simulateExecution(){
	// simulationCycle -> The time one CPU clock cycle should take in the simulation (in milliseconds)
	int simulationCycle = 1000;
	int simulationClockTime = 0;
	Process thisProc;
	double lastCompletionTime, firstArrivalTime;
	int i = 0;
	queue<Process> outputqueue;
	while (!readyqueue.isEmpty()){
		thisProc = readyqueue.dequeue();
		cout << "At T=" << simulationClockTime << ", The CPU is handling Process with ID " << thisProc.getProcID() << endl;
		cout << "Simulation Clock: " << simulationClockTime << endl;
		cout << "Ready queue: ";
		if (readyqueue.isEmpty())
			cout << "EMPTY";
		else
			showReadyqueue();
		cout << endl << "Current Process ID: " << thisProc.getProcID() << endl;
		if (i == 0){
			// the start time of the first process is its arrival time
			thisProc.setStartTime(thisProc.getArrivalTime());
			firstArrivalTime = thisProc.getArrivalTime();
		}else{
			/* If the completion time of the last process is greater than this process's arrival time,
			this process will start after the last process completes. Otherwise it will start when its arrival
			time occurs*/ 
			if (lastCompletionTime>thisProc.getArrivalTime())
				thisProc.setStartTime(lastCompletionTime);
			else
				thisProc.setStartTime(thisProc.getArrivalTime());
		}
		thisProc.setCompletionTime(thisProc.getStartTime() + thisProc.getBurstTime());
		thisProc.setTurnAroundTime(thisProc.getCompletionTime() - thisProc.getArrivalTime());
		thisProc.setWaitTime(thisProc.getTurnAroundTime() - thisProc.getBurstTime());
		thisProc.setResponseTime(thisProc.getStartTime() - thisProc.getArrivalTime());
		
		netTurnAroundTime += thisProc.getTurnAroundTime();
		netWaitTime += thisProc.getWaitTime();
		netResponseTime += thisProc.getResponseTime();
		netIdleTime += (i == 0)? (thisProc.getArrivalTime()): (thisProc.getStartTime() - lastCompletionTime);
		
        lastCompletionTime = thisProc.getCompletionTime();
        simulationClockTime += thisProc.getBurstTime();
        Sleep(simulationCycle*thisProc.getBurstTime());
        system("cls");
        i++;
        outputqueue.enqueue(thisProc);
        cout << "At T=" << simulationClockTime << ", Process with ID " << thisProc.getProcID() << " has terminated" << endl;
    }
    double avgTurnAroundTime = netTurnAroundTime/noOfProcesses;
    double avgWaitTime = netWaitTime/noOfProcesses;
    double avgResponseTime = netResponseTime/noOfProcesses;
    double throughput = (double) noOfProcesses/(lastCompletionTime-firstArrivalTime);
    
    cout << "PID\t" << "AT\t" << "BT\t" << "ST\t" << "CT\t" << "TAT\t" << "WT\t" << "RT\t" << endl;
    
    cout << setprecision(2) << fixed;
    while (!outputqueue.isEmpty()){
    	thisProc = outputqueue.dequeue();
    	cout << thisProc.getProcID() << '\t' << thisProc.getArrivalTime() << '\t' << thisProc.getBurstTime() << '\t' << thisProc.getStartTime() << '\t' << thisProc.getCompletionTime() << '\t' << thisProc.getTurnAroundTime() << '\t' << fabs(thisProc.getWaitTime()) << '\t' << thisProc.getResponseTime() << endl;
	}
	
    cout << "Average Turn Around Time: " << avgTurnAroundTime <<endl;
    cout << "Average Wait Time: " << avgWaitTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;
    cout << "CPU Throughput: " << throughput << " Process/Unit Time" << endl;
}
