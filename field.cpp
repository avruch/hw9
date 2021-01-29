#include "ip.h"
#include "port.h"
#include "field.h"
#define PACKET_SIZE 4
#define EXPECTED_SIZE_FIELD 2
#define EXPECTED_SIZE_NAME 2
#define SRC_IP "src-ip"
#define DST_IP "dst-ip"
#define SRC_PORT "src-port"
#define DST_PORT "dst-port"

    Field::Field(String pattern, field_type type){
printf("Field default c'tor'\n");
    	this->pattern=pattern;
    	this->type=type;
    }

    Field::Field(String pattern){
printf("Field GENERIC c'tor'\n");
    	this->pattern=pattern;
    	this->type=GENERIC;
    }

    Field::~Field(){//default d'tor
printf("Field default d'tor'\n");
    }

    field_type Field::get_type() const{
    	return this->type;
    }

    bool Field::set_value(String val){
printf("Field set_value'\n");
    	if(this->type==PORT){
    		return ((Port*)this)->set_value(val);
    	}
    	if(this->type==IP){
    		return ((Ip*)this->set_value(val));
    	return false;
        }
    }

    bool Field::match_value(String val) const{
printf("Field match_value'\n");
    	if(this->type==PORT){
    		return ((Port*)this->match_value(val));
    	}
    	if(this->type==IP){
    		return ((Ip*)this->match_value(val));
    	}
    	return false;
    }

    bool Field::match(String packet){
printf("Field match'\n");
    	String* sub_strings;
        size_t size=0;
        bool tmp;
        packet.trim().split(",",&sub_strings,&size);
        if (size!=PACKET_SIZE){
        	return false;//illegal because we have the wrong number of fields in single packet
        }
        for(int i=0;i<PACKET_SIZE;i++){
        	String* sub_sub_strings;
        	size_t sub_size=0;
        	sub_strings[i].trim().split("=",&sub_sub_strings,&sub_size);
            if(this->pattern.trim().equals(sub_sub_strings[0].trim())){
                    tmp= match_value(sub_sub_strings[1].trim());
                    delete[] sub_sub_strings;
                    if(!tmp){
                        delete[] sub_strings;
                        return false;
                    }
                }
            }
            delete[] sub_strings;
            return true;
        }
/*
        	if(sub_size=!EXPECTED_SIZE_FIELD){
        		return false;
        	}
        	for(int j=0;j<PACKET_SIZE;j++){
        		if(strcmp(available_types[j],sub_sub_strings[0])){
        			if(j<2){//ip
        				if(!Ip::match_value(sub_sub_strings[1])){
        					delete[] sub_sub_strings;
        					delete[] sub_strings;
        					return false;
        				}
        			}
        			else{//port
        				if(!port::match_value(sub_sub_strings[1])){
        					delete[] sub_sub_strings;
        					delete[] sub_strings;
        					return false;
        				}
        			}
        		}
        	}
        	delete[] sub_sub_strings;
        }
        delete[] sub_strings;
        return true;
    }
*/




