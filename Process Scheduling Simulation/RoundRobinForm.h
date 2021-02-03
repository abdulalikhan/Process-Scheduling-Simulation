#pragma once
#include "queue.h"
#include "process.h"
#include "DynamicSafeArray.h"
#include <Windows.h>

namespace ProcessSchedulingSimulation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for RoundRobinForm
	/// </summary>
	public ref class RoundRobinForm : public System::Windows::Forms::Form
	{
		public:
			int simulationSpeed;
			int noOfProcesses;
			double timeQuantum;
			double netTurnAroundTime;
			double netWaitTime;
			double netResponseTime;
			double netIdleTime;
			double avgTurnAroundTime;
    		double avgWaitTime;
    		double avgResponseTime;
    		double throughput;
			queue<Process>* readyQueue;
			DynamicSafeArray<double>* remainingBurstTimes;
			Thread^ t;

			RoundRobinForm(int noOfProcesses, DynamicSafeArray<Process>& processArray);
			void updateReadyQueue();
			void simulateExecution();

	protected:
		~RoundRobinForm();
		private: System::Windows::Forms::Label^  label4;
		private: System::Windows::Forms::ComboBox^  simSpeedBox;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Button^  exitBtn;
		private: System::Windows::Forms::Button^  startBtn;
		private: System::Windows::Forms::ProgressBar^  progressBar1;
		private: System::Windows::Forms::TextBox^  PIDTxt;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::ListView^  listView2;
		private: System::Windows::Forms::ColumnHeader^  columnHeader9;
		private: System::Windows::Forms::ColumnHeader^  columnHeader10;
		private: System::Windows::Forms::ColumnHeader^  columnHeader11;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::TextBox^  timeQuantumTxt;
		private: System::Windows::Forms::Button^  stopBtn;
		private: System::Windows::Forms::ListView^  listView1;
		private: System::Windows::Forms::ColumnHeader^  columnHeader1;
		private: System::Windows::Forms::ColumnHeader^  columnHeader2;
		private: System::Windows::Forms::ColumnHeader^  columnHeader3;
		private: System::Windows::Forms::ColumnHeader^  columnHeader4;
		private: System::Windows::Forms::ColumnHeader^  columnHeader5;
		private: System::Windows::Forms::ColumnHeader^  columnHeader6;
		private: System::Windows::Forms::ColumnHeader^  columnHeader7;
		private: System::Windows::Forms::ColumnHeader^  columnHeader8;
		private: System::Windows::Forms::ListBox^  listBox1;
		private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RoundRobinForm::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->simSpeedBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->startBtn = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->PIDTxt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timeQuantumTxt = (gcnew System::Windows::Forms::TextBox());
			this->stopBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(208, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Simulation Speed:";
			// 
			// simSpeedBox
			// 
			this->simSpeedBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->simSpeedBox->FormattingEnabled = true;
			this->simSpeedBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Slow", L"Medium", L"Fast", L"Ultra Fast"});
			this->simSpeedBox->Location = System::Drawing::Point(306, 46);
			this->simSpeedBox->Name = L"simSpeedBox";
			this->simSpeedBox->Size = System::Drawing::Size(105, 21);
			this->simSpeedBox->TabIndex = 23;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(146, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Simulation Results:";
			// 
			// exitBtn
			// 
			this->exitBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exitBtn.Image")));
			this->exitBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->exitBtn->Location = System::Drawing::Point(10, 85);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(117, 39);
			this->exitBtn->TabIndex = 21;
			this->exitBtn->Text = L"Exit Simulation";
			this->exitBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &RoundRobinForm::exitBtn_Click);
			// 
			// startBtn
			// 
			this->startBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"startBtn.Image")));
			this->startBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->startBtn->Location = System::Drawing::Point(10, 4);
			this->startBtn->Name = L"startBtn";
			this->startBtn->Size = System::Drawing::Size(116, 36);
			this->startBtn->TabIndex = 20;
			this->startBtn->Text = L"Start Simulation";
			this->startBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->startBtn->UseVisualStyleBackColor = true;
			this->startBtn->Click += gcnew System::EventHandler(this, &RoundRobinForm::startBtn_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(144, 101);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(397, 23);
			this->progressBar1->TabIndex = 19;
			// 
			// PIDTxt
			// 
			this->PIDTxt->Location = System::Drawing::Point(308, 73);
			this->PIDTxt->Name = L"PIDTxt";
			this->PIDTxt->ReadOnly = true;
			this->PIDTxt->Size = System::Drawing::Size(41, 20);
			this->PIDTxt->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(146, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Currently Executing Process ID:";
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {this->columnHeader9, this->columnHeader10, 
				this->columnHeader11});
			this->listView2->Location = System::Drawing::Point(143, 407);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(562, 63);
			this->listView2->TabIndex = 16;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Average Turn Around Time";
			this->columnHeader9->Width = 150;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Average Wait Time";
			this->columnHeader10->Width = 130;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Average Response Time";
			this->columnHeader11->Width = 150;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8});
			this->listView1->Location = System::Drawing::Point(143, 153);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(816, 248);
			this->listView1->TabIndex = 15;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Process ID";
			this->columnHeader1->Width = 100;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Arrival Time";
			this->columnHeader2->Width = 100;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Burst Time";
			this->columnHeader3->Width = 100;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Start Time";
			this->columnHeader4->Width = 100;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Completion Time";
			this->columnHeader5->Width = 100;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Turn Around Time";
			this->columnHeader6->Width = 100;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Wait Time";
			this->columnHeader7->Width = 100;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Response Time";
			this->columnHeader8->Width = 100;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(10, 154);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(107, 316);
			this->listBox1->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 138);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Ready Queue:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(221, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Time Quantum:";
			// 
			// timeQuantumTxt
			// 
			this->timeQuantumTxt->Location = System::Drawing::Point(306, 19);
			this->timeQuantumTxt->Name = L"timeQuantumTxt";
			this->timeQuantumTxt->Size = System::Drawing::Size(100, 20);
			this->timeQuantumTxt->TabIndex = 26;
			// 
			// stopBtn
			// 
			this->stopBtn->Enabled = false;
			this->stopBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"stopBtn.Image")));
			this->stopBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->stopBtn->Location = System::Drawing::Point(10, 44);
			this->stopBtn->Name = L"stopBtn";
			this->stopBtn->Size = System::Drawing::Size(116, 35);
			this->stopBtn->TabIndex = 27;
			this->stopBtn->Text = L"Stop Simulation";
			this->stopBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->stopBtn->UseVisualStyleBackColor = true;
			this->stopBtn->Click += gcnew System::EventHandler(this, &RoundRobinForm::stopBtn_Click);
			// 
			// RoundRobinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(969, 488);
			this->Controls->Add(this->stopBtn);
			this->Controls->Add(this->timeQuantumTxt);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->simSpeedBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->startBtn);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->PIDTxt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"RoundRobinForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Round Robin Simulation";
			this->Load += gcnew System::EventHandler(this, &RoundRobinForm::RoundRobinForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RoundRobinForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 updateReadyQueue();
			 }
private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void startBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (timeQuantumTxt->Text != ""){
					timeQuantum = System::Convert::ToDouble(timeQuantumTxt->Text->ToString());
					if(simSpeedBox->SelectedIndex > -1){
							if (simSpeedBox->SelectedItem->ToString() == "Slow")
								simulationSpeed = 200;
							else if (simSpeedBox->SelectedItem->ToString() == "Medium")
								simulationSpeed = 100;
							else if (simSpeedBox->SelectedItem->ToString() == "Fast")
								simulationSpeed = 50;
							else if (simSpeedBox->SelectedItem->ToString() == "Ultra Fast")
								simulationSpeed = 10;
					}else
							simulationSpeed = 100;
					ThreadStart^ start = gcnew ThreadStart(this, &RoundRobinForm::simulateExecution);
					t = gcnew Thread(start);
					t->Start();
					stopBtn->Enabled = true;
					startBtn->Enabled = false;
			 }else{
				 MessageBox::Show("Please enter a time quantum");
			 }
		 }
private: System::Void stopBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 t->Abort();
			 stopBtn->Enabled = false;
		 }
};
}
