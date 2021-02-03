#include "StdAfx.h"
#include "ShortestJobFirstForm.h"

namespace ProcessSchedulingSimulation {
	ShortestJobFirstForm::ShortestJobFirstForm(int noOfProcesses, DynamicSafeArray<Process>& processArrayArg)
	{
		InitializeComponent();
		this->noOfProcesses = noOfProcesses;
		processArray = new DynamicSafeArray<Process>(noOfProcesses);
		*(processArray) = processArrayArg;
		completed = new DynamicSafeArray<bool>(noOfProcesses);
		avgta = avgrt = avgwt = 0.0;
		for (int i = 0; i<noOfProcesses; i++){
			(*completed)[i] = false;
		}
	}

	void ShortestJobFirstForm::updateReadyQueue()
	{
		listBox1->Items->Clear();
		for (int i=0; i<noOfProcesses; ++i){
			if ((*completed)[i] == false){
				listBox1->Items->Add((*processArray)[i].getProcID());
			}
		}
	}


	void ShortestJobFirstForm::simulateExecution() 
	{
		double curr_time = 0;
		double totaltt = 0;
		double totalwt = 0;
		double totalrt = 0;
		double totalit = 0;
		double throughput;
		PIDTxt -> CheckForIllegalCrossThreadCalls = false;
		int complete = 0;
		int prev = 0;
		while (complete != noOfProcesses) {
			int idx = -1;
			double mn = 10000000;
			//traversing through all process to find minimum burst time
			for (int i = 0; i < noOfProcesses; i++) {
				//basic condition to find a process with minimum bursttime that is not completed yet
				if (( * processArray)[i].getArrivalTime() <= curr_time && ( * completed)[i] == 0) {
					if (( * processArray)[i].getBurstTime() < mn) {
						mn = ( * processArray)[i].getBurstTime();
						idx = i;
					}
					/*if two process have same burst time then we will use the process that
					 came at frst*/
					if (( * processArray)[i].getBurstTime() == mn) {
						if (( * processArray)[i].getArrivalTime() < ( * processArray)[idx].getArrivalTime()) {
							mn = ( * processArray)[i].getBurstTime();
							idx = i;
						}
					}
				}
			}
			if (idx != -1) {
				PIDTxt -> Text = System::Convert::ToString(( * processArray)[idx].getProcID());
				progressBar1 -> Value = 0;
				int h = ( * processArray)[idx].getBurstTime();
				for (int i = 0; i < 10; i++) {
					//cout << a;
					progressBar1 -> Increment(10);
					Sleep(h * simulationSpeed);
				}
				( * processArray)[idx].setStartTime(curr_time);
				( * processArray)[idx].setCompletionTime(( * processArray)[idx].getBurstTime() + ( * processArray)[idx].getStartTime());
				( * processArray)[idx].setTurnAroundTime(( * processArray)[idx].getCompletionTime() - ( * processArray)[idx].getArrivalTime());
				( * processArray)[idx].setWaitTime(( * processArray)[idx].getTurnAroundTime() - ( * processArray)[idx].getBurstTime());
				( * processArray)[idx].setResponseTime(( * processArray)[idx].getStartTime() - ( * processArray)[idx].getArrivalTime());

				totaltt += ( * processArray)[idx].getTurnAroundTime();
				totalwt += ( * processArray)[idx].getWaitTime();
				totalrt += ( * processArray)[idx].getResponseTime();
				totalit += ( * processArray)[idx].getStartTime() - prev;

				( * completed)[idx] = true;
				updateReadyQueue();
				complete++;
				curr_time = ( * processArray)[idx].getCompletionTime();
				prev = curr_time;
			} else {
				curr_time++;
			}

		}
		double min_arrival_time = 10000000;
		double max_completion_time = -1;
		for (int i = 0; i < noOfProcesses; i++) {
			min_arrival_time = min(min_arrival_time, ( * processArray)[i].getArrivalTime());
			max_completion_time = max(max_completion_time, ( * processArray)[i].getCompletionTime());
		}
		avgta = (double) totaltt / noOfProcesses;
		avgwt = (double) totalwt / noOfProcesses;
		avgrt = (double) totalrt / noOfProcesses;
		cpu = ((max_completion_time - totalit) / (double) max_completion_time) * 100;
		throughput = double(noOfProcesses) / (max_completion_time - min_arrival_time);

		for (int i = 0; i < noOfProcesses; i++) {
			ListViewItem ^ ListViewItem0;
			ListViewItem0 = gcnew ListViewItem();
			ListViewItem0 -> Text = System::Convert::ToString(( * processArray)[i].getProcID());
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getArrivalTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getBurstTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getStartTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getCompletionTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getTurnAroundTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getWaitTime()));
			ListViewItem0 -> SubItems -> Add(System::Convert::ToString(( * processArray)[i].getResponseTime()));
			listView1 -> Items -> Add(ListViewItem0);
		}

		ListViewItem ^ ListViewItem1;
		ListViewItem1 = gcnew ListViewItem();
		ListViewItem1 -> Text = System::Convert::ToString(Math::Round(avgta, 3));
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(avgwt, 3)));
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(avgrt, 3)));
		ListViewItem1 -> SubItems -> Add(System::Convert::ToString(Math::Round(throughput, 3)));
		listView2 -> Items -> Add(ListViewItem1);
		MessageBox::Show("Simulation complete! See the results table for the simulation results.");
	}

	ShortestJobFirstForm::~ShortestJobFirstForm()
	{
		if (processArray != 0){
			delete processArray;
			processArray = 0;
		}
		if (completed != 0){
			delete completed;
			completed = 0;
		}
		noOfProcesses = 0;
		avgta = avgwt = avgrt = cpu = 0;
		if (components)
		{
			delete components;
		}
	}
}

