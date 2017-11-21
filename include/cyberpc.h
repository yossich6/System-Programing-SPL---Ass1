#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"

class CyberDNS; // Forward decleration

class CyberPC
{
private:
	const std::string cyber_pc_name_;
    const std::string cyber_pc_os_;
    std::vector<std::string> cyber_pc_connections_;
    CyberWorm * cyber_worm;
	int cyber_pc_time_to_infect;

    CyberPC(); // Prevent the use of an empty constructor
 
public:
    ~CyberPC();
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);// Only use this constructor
    const std::string getName();
    const std::string getOS();
    CyberWorm * getWorm();
	void AddConnection(std::string second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void setTimeToINfect(int time);
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active
	void Disinfect();// called by cyber expert, disinfect PC
	bool dormancy;



	//Add additional functions here if necessary
	
};


#endif
