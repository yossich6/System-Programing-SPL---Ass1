#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"


class CyberExpert
{
private:
	const std::string cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    CyberExpert();
     // Prevent the use of an empty constructor
	// Add your own variables here
 
public:
    int work_time_counter;
    int rest_time_counter;

    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc); 
	const std::string get_cyber_expert_name_();
	const int get_cyber_expert_work_time_(); 
	const int get_cyber_expert_rest_time_(); 
	const int get_cyber_expert_efficiency_(); 
	//CyberExpert& operator=(CyberExpert exp);

};

#endif
