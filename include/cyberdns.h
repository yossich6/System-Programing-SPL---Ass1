#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../include/cyberpc.h"

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
	std::map<const std::string, CyberPC *> cyber_DNS_; //Hash map to hold PC names and pointers



 
public:
	~CyberDNS();
    std::map<const std::string, CyberPC *> get_cyber_DNS_ ();
	std::map<const std::string, CyberPC &>:: iterator found;
	std::vector<std::string> v;
    CyberDNS();
	void AddPC(CyberPC * cyber_pc_);
	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
													// All access to PC objects should use this function
													// Do not store pointers elsewhere!
};

#endif
