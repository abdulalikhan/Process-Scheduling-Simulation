#include "StdAfx.h"
#include "RoundRobinForm.h"

namespace ProcessSchedulingSimulation {
	RoundRobinForm::RoundRobinForm(int noOfProcesses, DynamicSafeArray<Process>& processArray)
	{
		InitializeComponent();
		readyQueue = new queue<Process>();
		remainingBurstTimes = new DynamicSafeArray<double>(noOfProcesses);
		this->noOfProcesses = noOfProcesses;
		timeQuantum = 2;
		netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
		for (int i = 0; i<noOfProcesses; i++){
			(*remainingBurstTimes)[i] = processArray[i].getBurstTime();
			readyQueue->enqueue(processArray[i]);
		}
	}

	void RoundRobinForm::updateReadyQueue()
	{
		listBox1->Items->Clear();
		queue<Process>* temp = new queue<Process>();
		*temp = *readyQueue;
		while (!temp->isEmpty()){
			listBox1->Items->Add(temp->dequeue().getProcID());
		}
	}

	void RoundRobinForm::simulateExecution()
	{
		int simulationClockTime = 0;
		double currentTime = 0;
		Process * thisProc;
		thisProc = new Process();
		double lastCompletionTime, firstArrivalTime;
		int i = 0;
		queue < Process > * outputQueue = new queue < Process > ();
		PIDTxt -> CheckForIllegalCrossThreadCalls = false;
		while (!readyQueue -> isEmpty()) {
			*thisProc = readyQueue -> dequeue();
			PIDTxt -> Text = System::Convert::ToString(thisProc -> getProcID());
			progressBar1 -> Value = 0;
			updateReadyQueue();
			if (i == 0)
				firstArrivalTime = thisProc -> getArrivalTime();
			if (( * remainingBurstTimes)[i] == thisProc -> getBurstTime()) {
				if (currentTime > thisProc -> getArrivalTime())
					thisProc -> setStartTime(currentTime);
				else
					thisProc -> setStartTime(thisProc -> getArrivalTime());
				netIdleTime += thisProc -> getStartTime() - currentTime;
				currentTime = thisProc -> getStartTime();
			}

			if ((( * remainingBurstTimes)[i] - timeQuantum) > 0) {
				( * remainingBurstTimes)[i] -= timeQuantum;
				currentTime += timeQuantum;
				readyQueue -> enqueue( * thisProc);
			} else {
				currentTime += ( * remainingBurstTimes)[i];
				( * remainingBurstTimes)[i] = 0;
				thisProc -> setCompletionTime(currentTime);
				thisProc -> setTurnAroundTime(thisProc -> getCompletionTime() - thisProc -> getArrivalTime());
				thisProc -> setWaitTime(thisProc -> getTurnAroundTime() - thisProc -> getBurstTime());
				thisProc -> setResponseTime(thisProc -> getStartTime() - thisProc -> getArrivalTime());

				netTurnAroundTime += thisProc -> getTurnAroundTime();
				netWaitTime += thisProc -> getWaitTime();
				netResponseTime += thisProc -> getResponseTime();
				outputQueue -> enqueue( * thisProc);
			}
			lastCompletionTime = thisProc -> getArrivalTime();
			simulationClockTime += thisProc -> getBurstTime();
			i++;
			for (int j = 0; j < 10; ++j) {
				progressBar1 -> Increment(10);
				Sleep(simulationSpeed * thisProc -> getBurstTime());
			}
			if (i == noOfProcesses)
				i = 0;
		}
		double avgTurnAroundTime = netTurnAroundTime / noOfProcesses;
		double avgWaitTime = netWaitTime / noOfProcesses;
		double avgResponseTime = netResponseTime / noOfProcesses;

		while (!outputQueue -> isEmpty()) {
			* thisProc = outputQueue -> dequeue();
			ListViewItem ^ ListViewItem0;
			ListViewItem0 = gcnew ListViewItem();
			ListViewItem0 -> Text = System::Convert::ToString(thisProc -> getProcID());
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getArrivalTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getBurstTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getStartTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getCompletionTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getTurnAroundTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getWaitTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(thisProc -> getResponseTime()));
			listView1 -> Items -> Add(ListViewItem0);
		}

		ListViewItem ^ ListViewItem1;
		ListViewItem1 = gcnew ListViewItem();
		ListViewItem1 -> Text = System::Convert::ToString(Math::Round(avgTurnAroundTime, 3));
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(avgWaitTime, 3)));
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(avgResponseTime, 3)));
		listView2 -> Items -> Add(ListViewItem1);
		MessageBox::Show("Simulation complete! See the results table for the simulation results.");
	}

	RoundRobinForm::~RoundRobinForm()
	{
		if (readyQueue != 0){
			delete readyQueue;
			readyQueue = 0;
		}
		if (remainingBurstTimes != 0){
			delete remainingBurstTimes;
			remainingBurstTimes = 0;
		}
		noOfProcesses = 0;
		timeQuantum = 0;
		netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
		if (components)
		{
			delete components;
		}
	}
}

