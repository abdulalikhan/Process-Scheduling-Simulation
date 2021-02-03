#include "StdAfx.h"
#include "FirstComeFirstServeForm.h"
namespace ProcessSchedulingSimulation {
	FirstComeFirstServeForm::FirstComeFirstServeForm(int noOfProcesses, DynamicSafeArray<Process>& processArray)
	{
		InitializeComponent();
		this->noOfProcesses = noOfProcesses;
		processArray.sortArray();
		readyQueue = new queue<Process>();
		netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
		for (int i = 0; i<noOfProcesses; i++){
			readyQueue->enqueue(processArray[i]);
		}
	}
	
	void FirstComeFirstServeForm::updateReadyQueue(){
		listBox1->Items->Clear();
		queue<Process>* temp = new queue<Process>();
		*temp = *readyQueue;
		while (!temp->isEmpty()){
			listBox1->Items->Add(temp->dequeue().getProcID());
		}
	}

	void FirstComeFirstServeForm::simulateExecution() {
		int simulationClockTime = 0;
		thisProc = new Process();
		double lastCompletionTime, firstArrivalTime;
		int i = 0;
		queue < Process > * outputqueue = new queue < Process > ();
		PIDTxt -> CheckForIllegalCrossThreadCalls = false;
		while (!readyQueue -> isEmpty()) {
			* thisProc = readyQueue -> dequeue();
			PIDTxt -> Text = System::Convert::ToString(thisProc -> getProcID());
			progressBar1 -> Value = 0;
			updateReadyQueue();
			if (i == 0) {
				// the start time of the first process is its arrival time
				thisProc -> setStartTime(thisProc -> getArrivalTime());
				firstArrivalTime = thisProc -> getArrivalTime();
			} else {
				/* If the completion time of the last process is greater than this process's arrival time,
				this process will start after the last process completes. Otherwise it will start when its arrival
				time occurs*/
				if (lastCompletionTime > thisProc -> getArrivalTime())
					thisProc -> setStartTime(lastCompletionTime);
				else
					thisProc -> setStartTime(thisProc -> getArrivalTime());
			}
			thisProc -> setCompletionTime(thisProc -> getStartTime() + thisProc -> getBurstTime());
			thisProc -> setTurnAroundTime(thisProc -> getCompletionTime() - thisProc -> getArrivalTime());
			thisProc -> setWaitTime(thisProc -> getTurnAroundTime() - thisProc -> getBurstTime());
			thisProc -> setResponseTime(thisProc -> getStartTime() - thisProc -> getArrivalTime());

			netTurnAroundTime += thisProc -> getTurnAroundTime();
			netWaitTime += thisProc -> getWaitTime();
			netResponseTime += thisProc -> getResponseTime();
			netIdleTime += (i == 0) ? (thisProc -> getArrivalTime()) : (thisProc -> getStartTime() - lastCompletionTime);

			lastCompletionTime = thisProc -> getCompletionTime();
			simulationClockTime += thisProc -> getBurstTime();
			for (int j = 0; j < 10; ++j) {
				progressBar1 -> Increment(10);
				Sleep(simulationSpeed * thisProc -> getBurstTime());
			}
			i++;
			outputqueue -> enqueue( * thisProc);
		}
		double avgTurnAroundTime = netTurnAroundTime / noOfProcesses;
		double avgWaitTime = netWaitTime / noOfProcesses;
		double avgResponseTime = netResponseTime / noOfProcesses;
		double throughput = (double) noOfProcesses / (lastCompletionTime - firstArrivalTime);
		while (!outputqueue -> isEmpty()) {
			*thisProc = outputqueue -> dequeue();
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
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(throughput, 3)));
		listView2 -> Items -> Add(ListViewItem1);
		MessageBox::Show("Simulation complete! See the results table for the simulation results.");
	}

	FirstComeFirstServeForm::~FirstComeFirstServeForm()
	{
		if (thisProc != 0){
			delete thisProc;
			thisProc = 0;
		}
		if (readyQueue != 0){
			delete readyQueue;
			readyQueue = 0;
		}
		noOfProcesses = 0;
		readyQueue = 0;
		netTurnAroundTime = netWaitTime = netResponseTime = netIdleTime = avgTurnAroundTime = avgWaitTime = avgResponseTime = throughput = 0;
		if (components)
		{
			delete components;
		}
	}
}
