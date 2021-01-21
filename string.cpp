#include "string.h"
#include <stddef.h>
#include <iostream>

class String {
    char *data;
    size_t length;

public:

    /**
     * @brief Initiates an empty string
     */
    String(){
        printf("string default constructor\n");
        length=0;
        data=NULL;
    }

    /**
     * @brief Initiates string from other string
     */
    String(const String &str){
        printf("string copy constructor\n");
        length=str.length;
        if (!length){
            data=NULL;
        }
        else {
            data=new char[length+1];
            strncpy(data, str.data, length+1);
        }
    return;
    }

    /**
     * @brief Initiates a string from char array
     */
    String(const char *str){
         printf("string from char array constructor\n");
        if(!str){
            date=NULL;
            length=0;
            return
        }
        length=strlen(str);
        data=new char[length+1];
        if (!length){
            data=NULL;
        }
        else {
            data=new char[length+1];
            strncpy(data, str, length+1);
        }
        return;
    }


    ~String(){
         printf("string default d'tor\n");
        if(data){
            delete[] data;
        }
    }

    /**






     * @brief Changes this from String
     */
    String& operator=(const String &rhs){
         printf("string operator= from string\n");
        delete[] data;
        length=rhs.length;
        if(!length){
            data=NULL;
        }
        else{
        data=new char[length];
        strncpy(data,rhs.data,length);
        }
        return *this;
    }

    /**
     * @brief Changes this from char array
     */
    String& operator=(const char *str){
          printf("string operator= from char array\n");
        delete[] data;
        length=strlen(str);
        if(!length){
            data=NULL;
        }
        else {
            data=new char[length+1];
            strncpy(data,str,length+1);
        }
        return *this;
    }



    /**
     * @brief Returns true iff the contents of this equals to the
     * contents of rhs
     */
    bool equals(const String &rhs) const {
          printf("string equals from string\n");
        if (rhs.length!=this.length){
            return false;
        }
        if(!strncmp(rhs,this.data,this.length)){
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * @brief Returns true iff the contents of this equals to rhs
     */
    bool equals(const char *rhs) const{
         printf("string equals from char array\n");
        if(strlen(rhs)=!this.length) {
            return false;
        }
        if(strncmp(rhs,this.data,this.length)) {
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * @brief Splits this to several sub-strings according to delimiters.
     * Allocates memory for output that the user must delete (using delete[]).
     * @note Does not affect this.
     * @note If "output" is set to NULL, do not allocated memory, only
     * compute "size".
     */
    void split(const char *delimiters, String **output, size_t *size) const{
         printf("string split function with delimiters %s \n",&delimiters);
        string orig_str(this.data);
        unsigned int length_str=orig_str.length , length_delimiters=strlen(delimiters);
        unsigned int num_of_strings=1;
        unsigned int begin_index=0, sub_string_index=0;
        //fist we only count the number of sub strings to create
       for (int i=0;i<length_str;i++)_{
            for(int j=0;j<length_delimiters;j++){
                if (orig_str[i]==delimiters[j]){
                    num_of_strings++;
                 }
            }
        }
         printf("num of strings = %u string is %s \n",&num_of_strings,&orig_str.data);
        *size=num_of_strings;
        if(!output){
            return;
        }
        *output=new string[num_of_strings]; 
        for (int i=0;i<length_str;i++)_{
            for(int j=0;j<length_delimiters;j++){
                if (orig_str[i]==delimiters[j]){
                    orig_str[i]='\0';
                    (*output)[sub_string_index]=string(orig_str+begin_index);
                    sub_string_index++;
                    begin_index=i+1;
                 }
            
            }
        }
        (*output)[sub_string_index]=string(orig_str+begin_index);
        return;
    }

    /**
     * @brief Try to convert this to an integer. Returns 0 on error.
     */
    int to_integer() const;

    /**
     * @brief Remove any leading or trailing white-spaces.
     * Does not change this.
     */
    String trim() const{
        printf("string trim func\n", &string_to_copy);
        if(this.data){
            return NULL;
        }
        string orig_str(this.data);
        int i=0, j=this.length-1;
        while(orig_str[i]==' '){
            i++;
        }
        while((j>i)&&(orig_str[j]==' ')){
            j--;
        }
        if (i>j){
            return NULL;
        }
        else{
            char* string_to _copy[j-i+1];
            for(int k=0;k<(j-i+1);k++){
                string_to_copy[k]=orig_str[i+k];
            }
            string_to _copy[j-i]='\0';
            printf("string to copy in trim func is %s", &string_to_copy);
            string str(string_to_copy);
            return str;
        }


    }
}


