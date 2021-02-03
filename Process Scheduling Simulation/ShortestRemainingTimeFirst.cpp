#include "StdAfx.h"
#include "ShortestRemainingTimeFirst.h"

namespace ProcessSchedulingSimulation {
	ShortestRemainingTimeFirst::ShortestRemainingTimeFirst(int noOfProcesses, DynamicSafeArray<Process>& processArrayArg)
	{
		InitializeComponent();
		this->noOfProcesses = noOfProcesses;
		processArray = new DynamicSafeArray<Process>(noOfProcesses);
		*(processArray) = processArrayArg;
		completed = new DynamicSafeArray<bool>(noOfProcesses);
		btemp = new DynamicSafeArray<double>(noOfProcesses);
		avgta = avgrt = avgwt = 0.0;
		for (int i = 0; i<noOfProcesses; i++){
			(*completed)[i] = false;
			(*btemp)[i] = (*processArray)[i].getBurstTime();
		}
	}

	void ShortestRemainingTimeFirst::updateReadyQueue()
	{
		listBox1->Items->Clear();
		for (int i=0; i<noOfProcesses; ++i){
			if ((*completed)[i] == false){
				listBox1->Items->Add((*processArray)[i].getProcID());
			}
		}
	}

	void ShortestRemainingTimeFirst::simulateExecution() {
		int total_turnaround_time = 0;
		int total_waiting_time = 0;
		int total_response_time = 0;
		int total_idle_time = 0;
		double throughput;
		PIDTxt -> CheckForIllegalCrossThreadCalls = false;
		int current_time = 0;
		int complete = 0;
		int prev = 0;
		while (complete != noOfProcesses) {
			int idx = -1;
			int mn = 10000000;
			for (int i = 0; i < noOfProcesses; i++) {
				if (( * processArray)[i].getArrivalTime() <= current_time && ( * completed)[i] == false) {
					if (( * btemp)[i] < mn) {
						mn = ( * btemp)[i];
						idx = i;
					}
					if (( * btemp)[i] == mn) {
						if (( * processArray)[i].getArrivalTime() < ( * processArray)[idx].getArrivalTime()) {
							mn = ( * btemp)[i];
							idx = i;
						}
					}
				}
			}

			if (idx != -1) {
				if (( * btemp)[idx] == ( * processArray)[idx].getBurstTime()) {
					( * processArray)[idx].setStartTime(current_time);
					total_idle_time += ( * processArray)[idx].getStartTime() - prev;

				}
				( * btemp)[idx] -= 1;
				current_time++;
				prev = current_time;
				PIDTxt -> Text = System::Convert::ToString(( * processArray)[idx].getProcID());
				progressBar1 -> Value = 0;
				int h = ( * processArray)[idx].getBurstTime();
				for (int i = 0; i < 10; i++) {
					progressBar1 -> Increment(10);
					Sleep(h * simulationSpeed);
				}
				if (( * btemp)[idx] == 0) {
					( * processArray)[idx].setCompletionTime(current_time);
					( * processArray)[idx].setTurnAroundTime(( * processArray)[idx].getCompletionTime() - ( * processArray)[idx].getArrivalTime());
					( * processArray)[idx].setWaitTime(( * processArray)[idx].getTurnAroundTime() - ( * processArray)[idx].getBurstTime());
					( * processArray)[idx].setResponseTime(( * processArray)[idx].getStartTime() - ( * processArray)[idx].getArrivalTime());

					total_turnaround_time += ( * processArray)[idx].getTurnAroundTime();
					total_waiting_time += ( * processArray)[idx].getWaitTime();
					total_response_time += ( * processArray)[idx].getResponseTime();

					( * completed)[idx] = true;
					complete++;
					updateReadyQueue();
				} else {
					// Another process has arrived with lesser burst time
				}
			} else {
				current_time++;
			}
		}

		double min_arrival_time = 10000000;
		double max_completion_time = -1;
		for (int i = 0; i < noOfProcesses; i++) {
			min_arrival_time = min(min_arrival_time, ( * processArray)[i].getArrivalTime());
			max_completion_time = max(max_completion_time, ( * processArray)[i].getCompletionTime());
		}

		avgta = (double) total_turnaround_time / noOfProcesses;
		avgwt = (double) total_waiting_time / noOfProcesses;
		avgrt = (double) total_response_time / noOfProcesses;
		cpu = ((max_completion_time - total_idle_time) / (double) max_completion_time) * 100;
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

	ShortestRemainingTimeFirst::~ShortestRemainingTimeFirst()
	{
		if (processArray != 0){
			delete processArray;
			processArray = 0;
		}
		if (completed != 0){
			delete completed;
			completed = 0;
		}
		if (btemp != 0){
			delete btemp;
			btemp = 0;
		}
		noOfProcesses = 0;
		avgta = avgrt = avgwt = 0.0;
		if (components)
		{
			delete components;
		}
	}
}
