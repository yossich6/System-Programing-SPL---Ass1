#include <iostream>
#include <string>
#include <utility>  
#include <map>
#include <vector>
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include <algorithm>
using namespace std;

CyberDNS::CyberDNS():cyber_DNS_(),v(){

}

CyberDNS::~CyberDNS(){

	for(std::map<const std::string, CyberPC *>:: iterator it=cyber_DNS_.begin();   it != cyber_DNS_.end();   it++){
		delete it->second;
	}
}

void CyberDNS::AddPC(CyberPC * cyber_pc_)
{
	cyber_DNS_.insert(pair<string,CyberPC*> (cyber_pc_->getName(),cyber_pc_));
}

CyberPC & CyberDNS::GetCyberPC(const std::string  &cyber_pc_name) const{
	return *(cyber_DNS_.find(cyber_pc_name) ->second);
}

std::map<const std::string, CyberPC *> CyberDNS::get_cyber_DNS_(){
	return CyberDNS::cyber_DNS_;
}

std::vector<std::string> CyberDNS::GetCyberPCList(){
	std::vector<std::string> k;
	v=k;


	std::map<const std::string, CyberPC *>:: iterator found= CyberDNS::cyber_DNS_.begin();


	while(found != cyber_DNS_.end() ){

		v.push_back(found->first);
		found++;

	}
	reverse(v.begin(),v.end());

	return v;

}



// Return list of PC's as a vector of strings.
// Do not store pointers elsewhere!
