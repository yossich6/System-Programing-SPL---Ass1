#include "../include/cyberexpert.h"
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"


CyberExpert::CyberExpert():
cyber_expert_name_(""),
cyber_expert_work_time_(0),
cyber_expert_rest_time_(0),
cyber_expert_efficiency_(0),
work_time_counter(0),
rest_time_counter(0)
{} // Prevent the use of an empty constructor
// Add type filter text your own variables here


CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
    			 cyber_expert_name_(cyber_expert_name_),
				 cyber_expert_work_time_(cyber_expert_work_time_),
				 cyber_expert_rest_time_(cyber_expert_rest_time_),
				 cyber_expert_efficiency_(cyber_expert_efficiency_),
				 work_time_counter(cyber_expert_work_time_),
				 rest_time_counter(cyber_expert_rest_time_)
{}


const std::string CyberExpert::get_cyber_expert_name_(){
	return CyberExpert::cyber_expert_name_;
}
const int CyberExpert::get_cyber_expert_work_time_(){
	return CyberExpert::cyber_expert_work_time_;
}
const int CyberExpert::get_cyber_expert_rest_time_(){
	return CyberExpert::cyber_expert_rest_time_;

}
const int CyberExpert::get_cyber_expert_efficiency_(){
	return CyberExpert::cyber_expert_efficiency_;

}

void CyberExpert::Clean(CyberPC & cyber_pc){
	cyber_pc.Disinfect();
}

//CyberExpert& CyberExpert::operator=(CyberExpert exp){
//return exp;

//}





