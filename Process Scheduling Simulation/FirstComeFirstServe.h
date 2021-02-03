#pragma once
#include "queue.h"
#include "process.h"
#include "DynamicSafeArray.h"
class FirstComeFirstServe
{
	private:
		int noOfProcesses;
		double netTurnAroundTime;
		double netWaitTime;
		double netResponseTime;
		double netIdleTime;
		double avgTurnAroundTime;
    	double avgWaitTime;
    	double avgResponseTime;
    	double throughput;
		queue<Process> readyqueue;
	public:
		FirstComeFirstServe();
		FirstComeFirstServe(int noOfProcesses, DynamicSafeArray<Process>& processArray);
		void showReadyqueue();
		void simulateExecution();
};

