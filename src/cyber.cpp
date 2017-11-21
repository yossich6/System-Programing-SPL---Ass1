#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <set>
#include <exception>
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include "../include/cyberworm.h"
#include <iostream>
#include <string>
#include "../include/cyberexpert.h"
#include <algorithm>
using namespace std;
using boost::property_tree::ptree;



int main(int argc, char *argv[]) {

	long day=0;
	CyberDNS * cyberdns = new CyberDNS();
	std::vector<CyberExpert*> ex;
	using boost::property_tree::ptree;
	ptree pt;
	ptree pt1;
	ptree pt2;
	int end;
	CyberPC *helper=NULL;
	CyberWorm * worm=NULL;
	CyberExpert *expi=NULL;
	std::vector<CyberWorm*> deleteWorms;
	std::vector<CyberPC*> deletePC;


	read_xml("../computers.xml",pt);
	BOOST_FOREACH(ptree::value_type const&v, pt.get_child(""))//const & = beahave
	{
		helper=new CyberPC(v.second.get<string>("name"), v.second.get<string>("os"));
		deletePC.push_back(helper);
		cyberdns->AddPC (helper);
		cout<<"Adding to server: "<<v.second.get<string>("name")<<endl;
		cout<<v.second.get<string>("name")<<" connected to server"<<endl;
	}




	read_xml("../network.xml",pt1);
	BOOST_FOREACH(ptree::value_type const&v, pt1.get_child(""))//const & = beahave
	{

		std::string pointA=v.second.get<string>("pointA");
		std::string pointB=v.second.get<string>("pointB");

		cyberdns->GetCyberPC(pointA).AddConnection(pointB);
		cyberdns->GetCyberPC(pointB).AddConnection(pointA);

		cout<<"Connecting "<<pointA<<" to "<<pointB<<endl;
		cout<<pointA<<" now connected to "<< pointB<< endl;
		cout<<pointB<<" now connected to "<< pointA<< endl;
	}


	read_xml("../events.xml",pt2);
	BOOST_FOREACH(ptree::value_type const&v, pt2.get_child(""))//const & = beahave
	{
		cout<<"Day : "<<day<<endl;

		if(v.first == "hack"){
			std::string computer=v.second.get<string>("computer");
			std::string wormName =v.second.get<string>("wormName");
			int wormDormancy =v.second.get<int>("wormDormancy");
			std::string wormOs =v.second.get<string>("wormOs");
			worm=new CyberWorm(wormOs,wormName,wormDormancy);
			deleteWorms.push_back(worm);


			std::map<const std::string, CyberPC *> map1=cyberdns->get_cyber_DNS_();
			std::map<const std::string, CyberPC *>::iterator helper= map1.find(computer);



			if( (helper->second)->getOS() == wormOs ){
				(helper->second)->CyberPC::Infect(*worm);
				(helper->second)->setTimeToINfect(wormDormancy);
				cout<<"Hack occurred on "<<computer<< endl;
				cout<<"       "<<computer<<" infected by "<<wormName<<endl;


			}else 	cout<<"Worm "<<wormName<<"is incompatible with "<< computer;
		}
		if(v.first == "clock-in"){
			std::string name=v.second.get<string>("name");
			int worktime=v.second.get<int>("workTime");
			int restTime=v.second.get<int>("restTime");
			int efficiency=v.second.get<int>("efficiency");

			expi=new CyberExpert(name,worktime,restTime,efficiency);

			ex.push_back(expi);
			cout<<"Clock-In: "<<name<<" began working"<<endl ;
		}

		if(v.first== "termination"){
			end=v.second.get<int>("time");
		}

		if (!ex.empty())
		{
			std::vector<string>:: iterator found;
			std::vector<string> map=cyberdns->GetCyberPCList();
			found=map.begin();

			for(unsigned int i=0;i<ex.size();i++)
			{
				bool stop=true;
				bool stop2=true;
				if(ex[i]->rest_time_counter == 0 && ex[i]->get_cyber_expert_rest_time_() != 0){

					cout<<ex[i]->get_cyber_expert_name_()<< " is back to work"<<endl;
					ex[i]->rest_time_counter=ex[i]->get_cyber_expert_rest_time_();
					ex[i]->work_time_counter=ex[i]->get_cyber_expert_work_time_()+1;
					stop=true;
					stop2=false;
				}
				if(ex[i]->work_time_counter == 0 && ex[i]->rest_time_counter!=0 ){
					ex[i]->rest_time_counter--;
				}
				for(int j=0;j<ex[i]->get_cyber_expert_efficiency_() && stop2;j++)
				{
					cout<<ex[i]->get_cyber_expert_name_()<<" examining "<< *found<<endl;
					if(cyberdns->GetCyberPC(*found).getWorm() != NULL){
						CyberWorm *helper= cyberdns->GetCyberPC(*found).getWorm();
						ex[i]->Clean(cyberdns->GetCyberPC(*found));
						cout<<"       " <<helper->get_cyber_worm_name_()<<" succesfully removed from "<<*found<<endl;
					}
					found++;
				}
				if( ex[i]->work_time_counter != 0)
					ex[i]->work_time_counter--;
				if(ex[i]->work_time_counter == 0 && stop){
					cout<<ex[i]->get_cyber_expert_name_()<< " is taking a break"<<endl;
					stop=false;
					ex[i]->rest_time_counter--;
				}
				stop2=true;
			}
		}
		std::vector<string> pclist=cyberdns->GetCyberPCList();
		std::vector<string>:: iterator iter= pclist.begin();
		for(; iter<pclist.end(); ++iter)
		{
			cyberdns->GetCyberPC(*iter).Run(*cyberdns);
		}
		day++;
	}
	for(;day<=end;day++)
	{
		cout<<"Day : "<<day<<endl;

		if (!ex.empty())
		{
			std::vector<string>:: iterator found;
			std::vector<string> map=cyberdns->GetCyberPCList();
			found=map.begin();
			for(unsigned int i=0;i<ex.size();i++)
			{
				bool stop=true;
				bool stop2=true;
				if(ex[i]->rest_time_counter == 0 && ex[i]->get_cyber_expert_rest_time_() != 0){
					cout<<ex[i]->get_cyber_expert_name_()<< " is back to work"<<endl;
					ex[i]->rest_time_counter=ex[i]->get_cyber_expert_rest_time_();
					ex[i]->work_time_counter=ex[i]->get_cyber_expert_work_time_()+1;
					stop=true;
					stop2=false;
				}
				if(ex[i]->work_time_counter == 0 && ex[i]->rest_time_counter!=0 ){
					ex[i]->rest_time_counter--;
				}
				for(int j=0;j<ex[i]->get_cyber_expert_efficiency_() && stop2;j++)
				{
					cout<<ex[i]->get_cyber_expert_name_()<<" examining "<< *found<<endl;
					if(cyberdns->GetCyberPC(*found).getWorm() != NULL){

						CyberWorm *helper= cyberdns->GetCyberPC(*found).getWorm();
						ex[i]->Clean(cyberdns->GetCyberPC(*found));
						cout<<"       " <<helper->get_cyber_worm_name_()<<" succesfully removed from "<<*found<<endl;
					}
					found++;
				}
				if( ex[i]->work_time_counter != 0)
					ex[i]->work_time_counter--;
				if(ex[i]->work_time_counter == 0 && stop){
					cout<<ex[i]->get_cyber_expert_name_()<< " is taking a break"<<endl;
					stop=false;
					ex[i]->rest_time_counter--;
				}
				stop2=true;
			}
		}
		std::vector<std::string> pclist= cyberdns->GetCyberPCList();
		std::vector<string>:: iterator foundy=pclist.begin();
		for(; foundy != pclist.end() ; ++foundy ){
			cyberdns->GetCyberPC(*foundy).Run(*cyberdns);
		}
	}
	delete cyberdns;
	while(!deleteWorms.empty()){
		CyberWorm* toDel = deleteWorms.back();
		deleteWorms.pop_back();
		delete toDel;
	}
	delete expi;
}
























