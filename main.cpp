#include "ip.h"
#include "port.h"
#include "input.h"


int main(int argc, char **argv){

	if(check_args(argc,argv)){
	 	return 1;
	}
	String rule(argv[1]);
	String* sub_strings;
	size_t size;
	rule.trim().split("=",&sub_strings,&size);
	bool one = (sub_strings[0].trim().equals("src-ip"));
	bool two = (sub_strings[0].trim().equals("dst-ip"));
	bool three = (sub_strings[0].trim().equals("src-port"));
	bool four = (sub_strings[0].trim().equals("dst-port"));
	if(one||two){
		Ip ip_rule(sub_strings[0].trim());
		ip_rule.set_value(sub_strings[1].trim());
		parse_input(ip_rule);
	}
	if(three||four){
		Port port_rule(sub_strings[0].trim());
		port_rule.set_value(sub_strings[1].trim());
		parse_input(port_rule);
	}
	delete[] sub_strings;
	return 0;
}