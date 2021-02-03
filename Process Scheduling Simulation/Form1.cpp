#include "StdAfx.h"
#include "Form1.h"

namespace ProcessSchedulingSimulation {
	Form1::Form1(void)
	{
		InitializeComponent();
		noOfProcesses = 0;
		processArray = new DynamicSafeArray<Process>();
		processArray->resize(100);
	}

	Form1::~Form1()
	{
		noOfProcesses = 0;
		if (processArray != 0){
			delete processArray;
			processArray = 0;
		}
		if (components)
		{
			delete components;
		}
	}
}