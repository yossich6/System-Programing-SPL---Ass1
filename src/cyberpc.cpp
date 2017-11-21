#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include <string.h>

using namespace std;

CyberPC::CyberPC():
					cyber_pc_name_(""),
					cyber_pc_os_(""),
					cyber_pc_connections_(),
					cyber_worm(NULL),
					cyber_pc_time_to_infect(0),
					dormancy(false)
{} // Prevent the use of an empty constructor

//public:
CyberPC::CyberPC( std::string cyber_pc_name, std::string cyber_pc_os):
    					cyber_pc_name_(cyber_pc_name),
						cyber_pc_os_(cyber_pc_os),
						cyber_pc_connections_(),
						cyber_worm(NULL),
						cyber_pc_time_to_infect(0),
						dormancy(false)
{}
// Only use this constructor
CyberPC::~CyberPC(){
	if(cyber_worm != NULL)
		delete cyber_worm;
}

const std::string CyberPC::getName()
{
	return cyber_pc_name_;
}

const std::string CyberPC::getOS()
{
	return cyber_pc_os_;
}

CyberWorm * CyberPC::getWorm(){
	return cyber_worm;
}


void CyberPC::setTimeToINfect(int time){
	cyber_pc_time_to_infect=time;
}

void CyberPC::AddConnection(std::string second_pc)
{
	CyberPC::cyber_pc_connections_.push_back(second_pc);

}// Add a connection to this PC
void CyberPC::Infect(CyberWorm & worm)
{
	cyber_worm=new CyberWorm(worm);

}// Add a worm to this PC

void CyberPC::Run(const CyberDNS & server){

	if (cyber_worm!=NULL){
		if(cyber_pc_time_to_infect == 0)
		{

			cout<< cyber_pc_name_<<" infecting..."<<endl;

			for(unsigned int i=0; i < cyber_pc_connections_.size();i++)
			{

				if((server.GetCyberPC(cyber_pc_connections_[i]).getOS())== cyber_worm->get_cyber_worm_os_())
				{
					cout<<"     "<<cyber_pc_connections_[i]<<" infected by "<< cyber_worm->get_cyber_worm_name_()<<endl;
					server.GetCyberPC(cyber_pc_connections_[i]).CyberPC::Infect(*cyber_worm);
					server.GetCyberPC(cyber_pc_connections_[i]).CyberPC::setTimeToINfect(cyber_worm->get_cyber_worm_dormancy_time_());
				}
				else cout<<"     Worm "<< cyber_worm->get_cyber_worm_name_() <<"is incompatible with "<< cyber_pc_connections_[i]<<endl;
			}
		}
		else
		{
			cyber_pc_time_to_infect--;
			cout<<this->cyber_pc_name_<<": Worm "<<cyber_worm->get_cyber_worm_name_()<<" is dormant"<<endl;
		}
	}
}

// Activate PC and infect others if worm is active
void CyberPC::Disinfect()
{
	cyber_worm= NULL;
	dormancy=false;
}









