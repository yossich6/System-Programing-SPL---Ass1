#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberworm.h"



CyberWorm::CyberWorm():
cyber_worm_os_(""),
cyber_worm_name_(""),
cyber_worm_dormancy_time_(0)
{}  // Prevent the use of an empty constructor
// Add your variables here


CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time):
    			cyber_worm_os_(cyber_worm_os),
				cyber_worm_name_(cyber_worm_name),
				cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
{}

CyberWorm::CyberWorm(const CyberWorm& other):
				cyber_worm_os_(other.cyber_worm_os_),
				cyber_worm_name_(other.cyber_worm_name_),
				cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_){}


const std::string CyberWorm::get_cyber_worm_os_()
{
	return cyber_worm_os_;
}

const std::string CyberWorm::get_cyber_worm_name_()
{
	return cyber_worm_name_;
}

const int CyberWorm::get_cyber_worm_dormancy_time_()
{
	return cyber_worm_dormancy_time_;
}

