#pragma once
class Process
{
	protected:
		int procID;
		int priority;
		double arrivalTime;
		double burstTime;
		double startTime;
		double completionTime;
		double turnAroundTime;
		double waitTime;
		double responseTime;
	public:
		// Default Constructor
		// Initializes all other member variables to zero
		Process();
		
		// Parameterized Constructor #1
		// Takes the process ID, arrival time and burst time as parameters.
		// Initializes all other member variables to zero
		// Used for constructing Process instances without priorities
		Process(int procID, double arrivalTime, double burstTime);

		// Parameterized Constructor #2
		// Takes the process ID, priority, arrival time, and burst time as parameters
		// Initializes all other member variables to zero
		// Used for constructing Process instances with priorities
		Process(int procID, int priority, double arrivalTime, double burstTime);
		
		// Getter functions
		int getProcID() const;
		int getPriority() const;
		double getArrivalTime() const;
		double getBurstTime() const;
		double getStartTime() const;
		double getCompletionTime() const;
		double getTurnAroundTime() const;
		double getWaitTime() const;
		double getResponseTime() const;
		
		// Setter functions
		void setPriority(int priority);
		void setStartTime(double startTime);
		void setCompletionTime(double completionTime);
		void setTurnAroundTime(double turnAroundTime);
		void setWaitTime(double waitTime);
		void setResponseTime(double responseTime);
		
		
		// Assignment operator overload
		Process& operator= (const Process& rhs);
				
		// Equality operator overload
		// Compared on the basis of all member variables
		bool operator== (const Process& rhs);
		
		// Less than operator overload
		// Compared on the basis of process arrival time
		bool operator< (const Process& rhs);
		
		// Greater than operator overload
		// Compared on the basis of process priority
		bool operator> (const Process& rhs);
		
};

