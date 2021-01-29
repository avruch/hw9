#include "ip.h"
#include "port.h"
#include "input.h"


int main(int argc, char **argv){

	if(check_args(argc,argv)){
		printf("check args init\n");
	 	return 1;
	}
	printf("argv[1]= %s\n",argv[1]);
	String rule(argv[1]);
	String* sub_strings;
	size_t size;
	rule.trim().split("=",&sub_strings,&size);
	printf("sub_strings[0]=%s,sub_strings[1]=%s\n",sub_strings[0],sub_strings[1]);
	bool one=(sub_strings[0].trim().equals(String("src-ip")));
	bool two = (sub_strings[0].trim().equals(String("dst-ip")));
	bool three = (sub_strings[0].trim().equals(String("src-port")));
	bool four = (sub_strings[0].trim().equals(String("dst-port")));
	if((one)||(two)){

			printf("ip chosen\n");
		Ip ip_rule(sub_strings[0].trim());
		ip_rule.set_value(sub_strings[1].trim());
			printf("after set value\n");
		parse_input(ip_rule);
			printf("after parse-input\n");
	}
	if(three||four){
			printf("port chosen\n");
		Port port_rule(sub_strings[0].trim());
		port_rule.set_value(sub_strings[1].trim());
		parse_input(port_rule);
	}
	return 0;
}