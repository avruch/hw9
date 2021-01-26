#ifndef IP_H
#define IP_H

#include "field.h"

#define MASK_SEGMENT 2
#define SEGMENTS 4

class Ip : public Field {
private:
    unsigned int low;
    unsigned int high;

public:

    Ip(String pattern);
    bool set_value(String val){
    	string* sub_strings;
        size_t size=0;
    	split("/",&sub_strings,&size);
    	if(size!=2){
			return false
    	}
    	int num_bits_rule=sub_strings[1].trim.to_integer();
    	int IP_mask=sub_strings[0].trim.to_integer();
    	if(num_bits_rule==0){
    		low=0;
    		high=0xFFFFFFFF;
    		return true;
    		}
    	int mask=1<<num_bits_rule;
    	mask--;
    	low=(IP_mask)&(~mask);
    	printf("low value IP returned %u \n",&low);
    	high=(ip_mask)|mask;
    	printf("high value IP returned %u \n",&high);
    	return true;
    	}
    }
    bool match_value(String val) const{
    	int value=val.to_integer();
    	if ((val<low)||(val>high)){
    		return false;
    	}
    	return true;
    }
};



#endif
