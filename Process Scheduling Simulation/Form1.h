#pragma once
#include "process.h"
#include "DynamicSafeArray.h"
#include "FirstComeFirstServeForm.h"
#include "RoundRobinForm.h"
#include "NonPreemptivePrioritySchedulingForm.h"
#include "ShortestJobFirstForm.h"
#include "ShortestRemainingTimeFirst.h"

namespace ProcessSchedulingSimulation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		private: System::Windows::Forms::NumericUpDown^  procIDVal;
		private: System::Windows::Forms::NumericUpDown^  priorityVal;
		private: System::Windows::Forms::NumericUpDown^  burstTimeVal;
		private: System::Windows::Forms::NumericUpDown^  arrivalTimeVal;
		private: System::Windows::Forms::GroupBox^  groupBox2;
		private: System::Windows::Forms::Button^  generateBtn;
		private: System::Windows::Forms::NumericUpDown^  noOfProcessesVal;
		private: System::Windows::Forms::Label^  noOfProcessesLbl;
		private: System::Windows::Forms::Label^  titleLbl;
		private: System::Windows::Forms::ComboBox^  schedulingAlgos;
		private: System::Windows::Forms::Label^  schedulingAlgoLbl;
		private: System::Windows::Forms::Button^  runSimulationBtn;
		private: System::Windows::Forms::ListView^  listView1;
		private: System::Windows::Forms::ColumnHeader^  columnHeader1;
		private: System::Windows::Forms::ColumnHeader^  columnHeader2;
		private: System::Windows::Forms::ColumnHeader^  columnHeader3;
		private: System::Windows::Forms::ColumnHeader^  columnHeader4;
		private: System::Windows::Forms::GroupBox^  groupBox1;
		private: System::Windows::Forms::Button^  addProcBtn;
		private: System::Windows::Forms::Label^  burstTimeLbl;
		private: System::Windows::Forms::Label^  arrivalTimeLbl;
		private: System::Windows::Forms::Label^  procIDLbl;
		private: System::Windows::Forms::Label^  priorityLbl;
		private: System::Windows::Forms::Button^  exitBtn;
		private: System::Windows::Forms::PictureBox^  pictureBox1;
		private: System::Windows::Forms::Label^  label1;

	public:
		int noOfProcesses;
	private: System::Windows::Forms::Button^  clearBtn;
	public: 
		DynamicSafeArray<Process>* processArray;
		Form1(void);
	protected:
		~Form1();

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->titleLbl = (gcnew System::Windows::Forms::Label());
			this->schedulingAlgos = (gcnew System::Windows::Forms::ComboBox());
			this->schedulingAlgoLbl = (gcnew System::Windows::Forms::Label());
			this->runSimulationBtn = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->priorityVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->burstTimeVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->arrivalTimeVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->procIDVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->priorityLbl = (gcnew System::Windows::Forms::Label());
			this->addProcBtn = (gcnew System::Windows::Forms::Button());
			this->burstTimeLbl = (gcnew System::Windows::Forms::Label());
			this->arrivalTimeLbl = (gcnew System::Windows::Forms::Label());
			this->procIDLbl = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->generateBtn = (gcnew System::Windows::Forms::Button());
			this->noOfProcessesVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->clearBtn = (gcnew System::Windows::Forms::Button());
			this->noOfProcessesLbl = (gcnew System::Windows::Forms::Label());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->priorityVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->burstTimeVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->arrivalTimeVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->procIDVal))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->noOfProcessesVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// titleLbl
			// 
			this->titleLbl->AutoSize = true;
			this->titleLbl->Font = (gcnew System::Drawing::Font(L"Assistant SemiBold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->titleLbl->Location = System::Drawing::Point(133, 17);
			this->titleLbl->Name = L"titleLbl";
			this->titleLbl->Size = System::Drawing::Size(369, 36);
			this->titleLbl->TabIndex = 0;
			this->titleLbl->Text = L"Process Scheduling Simulation";
			// 
			// schedulingAlgos
			// 
			this->schedulingAlgos->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->schedulingAlgos->FormattingEnabled = true;
			this->schedulingAlgos->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"First Come First Serve", L"Shortest Job First", 
				L"Round Robin", L"Shortest Remaining Time First", L"Non Preemptive Priority Scheduling"});
			this->schedulingAlgos->Location = System::Drawing::Point(210, 374);
			this->schedulingAlgos->Name = L"schedulingAlgos";
			this->schedulingAlgos->Size = System::Drawing::Size(226, 21);
			this->schedulingAlgos->TabIndex = 0;
			// 
			// schedulingAlgoLbl
			// 
			this->schedulingAlgoLbl->AutoSize = true;
			this->schedulingAlgoLbl->Location = System::Drawing::Point(70, 377);
			this->schedulingAlgoLbl->Name = L"schedulingAlgoLbl";
			this->schedulingAlgoLbl->Size = System::Drawing::Size(134, 13);
			this->schedulingAlgoLbl->TabIndex = 3;
			this->schedulingAlgoLbl->Text = L"CPU Scheduling Algorithm:";
			// 
			// runSimulationBtn
			// 
			this->runSimulationBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"runSimulationBtn.Image")));
			this->runSimulationBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->runSimulationBtn->Location = System::Drawing::Point(273, 401);
			this->runSimulationBtn->Name = L"runSimulationBtn";
			this->runSimulationBtn->Size = System::Drawing::Size(117, 35);
			this->runSimulationBtn->TabIndex = 1;
			this->runSimulationBtn->Text = L"Run Simulation";
			this->runSimulationBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->runSimulationBtn->UseVisualStyleBackColor = true;
			this->runSimulationBtn->Click += gcnew System::EventHandler(this, &Form1::runSimulationBtn_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4});
			this->listView1->Location = System::Drawing::Point(31, 81);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(524, 282);
			this->listView1->TabIndex = 5;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Process ID";
			this->columnHeader1->Width = 120;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Arrival Time";
			this->columnHeader2->Width = 120;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Burst Time";
			this->columnHeader3->Width = 120;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Priority";
			this->columnHeader4->Width = 120;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->priorityVal);
			this->groupBox1->Controls->Add(this->burstTimeVal);
			this->groupBox1->Controls->Add(this->arrivalTimeVal);
			this->groupBox1->Controls->Add(this->procIDVal);
			this->groupBox1->Controls->Add(this->priorityLbl);
			this->groupBox1->Controls->Add(this->addProcBtn);
			this->groupBox1->Controls->Add(this->burstTimeLbl);
			this->groupBox1->Controls->Add(this->arrivalTimeLbl);
			this->groupBox1->Controls->Add(this->procIDLbl);
			this->groupBox1->Location = System::Drawing::Point(561, 77);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(204, 173);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add a New Process";
			// 
			// priorityVal
			// 
			this->priorityVal->Location = System::Drawing::Point(86, 106);
			this->priorityVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->priorityVal->Name = L"priorityVal";
			this->priorityVal->Size = System::Drawing::Size(100, 20);
			this->priorityVal->TabIndex = 10;
			this->priorityVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// burstTimeVal
			// 
			this->burstTimeVal->Location = System::Drawing::Point(86, 79);
			this->burstTimeVal->Name = L"burstTimeVal";
			this->burstTimeVal->Size = System::Drawing::Size(100, 20);
			this->burstTimeVal->TabIndex = 9;
			// 
			// arrivalTimeVal
			// 
			this->arrivalTimeVal->Location = System::Drawing::Point(86, 53);
			this->arrivalTimeVal->Name = L"arrivalTimeVal";
			this->arrivalTimeVal->Size = System::Drawing::Size(100, 20);
			this->arrivalTimeVal->TabIndex = 8;
			// 
			// procIDVal
			// 
			this->procIDVal->Location = System::Drawing::Point(86, 29);
			this->procIDVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->procIDVal->Name = L"procIDVal";
			this->procIDVal->Size = System::Drawing::Size(100, 20);
			this->procIDVal->TabIndex = 7;
			this->procIDVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->procIDVal->ValueChanged += gcnew System::EventHandler(this, &Form1::procIDVal_ValueChanged);
			// 
			// priorityLbl
			// 
			this->priorityLbl->AutoSize = true;
			this->priorityLbl->Location = System::Drawing::Point(39, 108);
			this->priorityLbl->Name = L"priorityLbl";
			this->priorityLbl->Size = System::Drawing::Size(41, 13);
			this->priorityLbl->TabIndex = 7;
			this->priorityLbl->Text = L"Priority:";
			// 
			// addProcBtn
			// 
			this->addProcBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"addProcBtn.Image")));
			this->addProcBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->addProcBtn->Location = System::Drawing::Point(61, 132);
			this->addProcBtn->Name = L"addProcBtn";
			this->addProcBtn->Size = System::Drawing::Size(104, 35);
			this->addProcBtn->TabIndex = 4;
			this->addProcBtn->Text = L"Add Process";
			this->addProcBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->addProcBtn->UseVisualStyleBackColor = true;
			this->addProcBtn->Click += gcnew System::EventHandler(this, &Form1::addProcBtn_Click);
			// 
			// burstTimeLbl
			// 
			this->burstTimeLbl->AutoSize = true;
			this->burstTimeLbl->Location = System::Drawing::Point(20, 82);
			this->burstTimeLbl->Name = L"burstTimeLbl";
			this->burstTimeLbl->Size = System::Drawing::Size(60, 13);
			this->burstTimeLbl->TabIndex = 2;
			this->burstTimeLbl->Text = L"Burst Time:";
			// 
			// arrivalTimeLbl
			// 
			this->arrivalTimeLbl->AutoSize = true;
			this->arrivalTimeLbl->Location = System::Drawing::Point(15, 56);
			this->arrivalTimeLbl->Name = L"arrivalTimeLbl";
			this->arrivalTimeLbl->Size = System::Drawing::Size(65, 13);
			this->arrivalTimeLbl->TabIndex = 1;
			this->arrivalTimeLbl->Text = L"Arrival Time:";
			// 
			// procIDLbl
			// 
			this->procIDLbl->AutoSize = true;
			this->procIDLbl->Location = System::Drawing::Point(18, 32);
			this->procIDLbl->Name = L"procIDLbl";
			this->procIDLbl->Size = System::Drawing::Size(62, 13);
			this->procIDLbl->TabIndex = 0;
			this->procIDLbl->Text = L"Process ID:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->generateBtn);
			this->groupBox2->Controls->Add(this->noOfProcessesVal);
			this->groupBox2->Controls->Add(this->clearBtn);
			this->groupBox2->Controls->Add(this->noOfProcessesLbl);
			this->groupBox2->Location = System::Drawing::Point(561, 256);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(291, 107);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Randomly Generate Processes";
			// 
			// generateBtn
			// 
			this->generateBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"generateBtn.Image")));
			this->generateBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->generateBtn->Location = System::Drawing::Point(143, 55);
			this->generateBtn->Name = L"generateBtn";
			this->generateBtn->Size = System::Drawing::Size(135, 46);
			this->generateBtn->TabIndex = 11;
			this->generateBtn->Text = L"Generate Processes";
			this->generateBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->generateBtn->UseVisualStyleBackColor = true;
			this->generateBtn->Click += gcnew System::EventHandler(this, &Form1::generateBtn_Click);
			// 
			// noOfProcessesVal
			// 
			this->noOfProcessesVal->Location = System::Drawing::Point(139, 30);
			this->noOfProcessesVal->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->noOfProcessesVal->Name = L"noOfProcessesVal";
			this->noOfProcessesVal->Size = System::Drawing::Size(84, 20);
			this->noOfProcessesVal->TabIndex = 11;
			this->noOfProcessesVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// clearBtn
			// 
			this->clearBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"clearBtn.Image")));
			this->clearBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->clearBtn->Location = System::Drawing::Point(13, 55);
			this->clearBtn->Name = L"clearBtn";
			this->clearBtn->Size = System::Drawing::Size(120, 46);
			this->clearBtn->TabIndex = 11;
			this->clearBtn->Text = L"Clear Processes";
			this->clearBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->clearBtn->UseVisualStyleBackColor = true;
			this->clearBtn->Click += gcnew System::EventHandler(this, &Form1::clearBtn_Click);
			// 
			// noOfProcessesLbl
			// 
			this->noOfProcessesLbl->AutoSize = true;
			this->noOfProcessesLbl->Location = System::Drawing::Point(22, 32);
			this->noOfProcessesLbl->Name = L"noOfProcessesLbl";
			this->noOfProcessesLbl->Size = System::Drawing::Size(111, 13);
			this->noOfProcessesLbl->TabIndex = 11;
			this->noOfProcessesLbl->Text = L"Number of Processes:";
			// 
			// exitBtn
			// 
			this->exitBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"exitBtn.Image")));
			this->exitBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->exitBtn->Location = System::Drawing::Point(139, 401);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(104, 35);
			this->exitBtn->TabIndex = 8;
			this->exitBtn->Text = L"Exit Program";
			this->exitBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &Form1::exitBtn_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(64, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(67, 64);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(196, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(208, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Data Structures [CS-218] Semester Project";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(869, 441);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->runSimulationBtn);
			this->Controls->Add(this->schedulingAlgoLbl);
			this->Controls->Add(this->schedulingAlgos);
			this->Controls->Add(this->titleLbl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Process Scheduling Simulation";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->priorityVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->burstTimeVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->arrivalTimeVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->procIDVal))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->noOfProcessesVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addProcBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				ListViewItem ^ListViewItem1;
				ListViewItem1 = gcnew ListViewItem();
				ListViewItem1->Text = procIDVal->Text;
				ListViewItem1->SubItems->Add(arrivalTimeVal->Text);
				ListViewItem1->SubItems->Add(burstTimeVal->Text);
				ListViewItem1->SubItems->Add(priorityVal->Text);
				listView1->Items->Add(ListViewItem1);
				int procID = System::Convert::ToInt32(procIDVal->Text->ToString());
				double arrivalTime = System::Convert::ToDouble(arrivalTimeVal->Text);
				double burstTime = System::Convert::ToDouble(burstTimeVal->Text);
				int priority = System::Convert::ToInt32(priorityVal->Text->ToString());
				Process temp(procID, priority, arrivalTime, burstTime);
				if (processArray->getSize() <= noOfProcesses)
					processArray->resize(noOfProcesses+10);
				(*processArray)[noOfProcesses] = temp;
				noOfProcesses++;
				if (noOfProcesses>100)
					processArray->resize(noOfProcesses);
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void runSimulationBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (listView1->Items->Count == 0){
				 MessageBox::Show("There are no processes to execute.");
			 }else if (schedulingAlgos->SelectedIndex > -1){
				 processArray->resize(noOfProcesses);
				 if (schedulingAlgos->SelectedItem->ToString() == "First Come First Serve"){
					FirstComeFirstServeForm^ f1 = gcnew FirstComeFirstServeForm(noOfProcesses, *processArray);
					f1->ShowDialog();
				 }else if (schedulingAlgos->SelectedItem->ToString() == "Round Robin"){
					RoundRobinForm^ f2 = gcnew RoundRobinForm(noOfProcesses, *processArray);
					f2->ShowDialog();
				 }else if (schedulingAlgos->SelectedItem->ToString() == "Non Preemptive Priority Scheduling"){
					NonPreemptivePrioritySchedulingForm^ f3 = gcnew NonPreemptivePrioritySchedulingForm(noOfProcesses, *processArray);
					f3->ShowDialog();
				 }else if (schedulingAlgos->SelectedItem->ToString() == "Shortest Job First"){
					ShortestJobFirstForm^ f4 = gcnew ShortestJobFirstForm(noOfProcesses, *processArray);
					f4->ShowDialog();
				 }else if (schedulingAlgos->SelectedItem->ToString() == "Shortest Remaining Time First"){
					ShortestRemainingTimeFirst^ f5 = gcnew ShortestRemainingTimeFirst(noOfProcesses, *processArray);
					f5->ShowDialog();
				 }
			 }else{
				 MessageBox::Show("Please select a scheduling algorithm to simulate.");
			 }
		 }
private: System::Void procIDVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void generateBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			int n = System::Convert::ToInt32(noOfProcessesVal->Text->ToString());
			ListViewItem ^ListViewItem1;
			Random^ rnd = gcnew Random();
			String^ thisProcID;
			String^ thisPriority;
			String^ thisArrivalTime;
			String^ thisBurstTime;
			for (int i=0; i<n; ++i){
				thisProcID = System::Convert::ToString(noOfProcesses+1);
				thisPriority = System::Convert::ToString(rnd->Next(1, 100));
				thisArrivalTime = System::Convert::ToString(rnd->Next(1, 10));
				thisBurstTime = System::Convert::ToString(rnd->Next(1, 10));
				ListViewItem1 = gcnew ListViewItem();
				ListViewItem1->Text = thisProcID;
				ListViewItem1->SubItems->Add(thisArrivalTime);
				ListViewItem1->SubItems->Add(thisBurstTime);
				ListViewItem1->SubItems->Add(thisPriority);
				listView1->Items->Add(ListViewItem1);
				int procID = System::Convert::ToInt32(thisProcID);
				double arrivalTime = System::Convert::ToDouble(thisArrivalTime);
				double burstTime = System::Convert::ToDouble(thisBurstTime);
				int priority = System::Convert::ToInt32(thisPriority);
				Process temp(procID, priority, arrivalTime, burstTime);
				if (processArray->getSize() <= noOfProcesses)
					processArray->resize(noOfProcesses+10);
				(*processArray)[noOfProcesses] = temp;
				noOfProcesses++;
				if (noOfProcesses>100)
					processArray->resize(noOfProcesses);
			}
		 }
private: System::Void exitBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void clearBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 listView1->Items->Clear();
			 noOfProcesses = 0;
			 processArray->resize(0);
		 }
};
}

