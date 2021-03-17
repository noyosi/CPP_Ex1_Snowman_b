
#include "snowman.hpp"

#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

using namespace std;

const int valid_input_length = 8;
const int MAX_VALUE = 44444444;
const int MIN_VALUE = 11111111;
const int TEN = 10;

void check_input (int num) {

    //check if it's a positive number
    if (num<=0) 
    {
        throw out_of_range ("You should enter a positive number, with 8 digits in range of 1-4");
    }

    //check the input length
    if (to_string(num).size() != valid_input_length) 
    {
        throw out_of_range("Error: you can only enter 8 digits number");
    }

    if(num<MIN_VALUE || num>MAX_VALUE)
    {
        throw out_of_range ("You should enter a positive number, with 8 digits in range of 1-4");
    }

    //check if each digit is in range 1-4
    for (size_t i = 0; i < valid_input_length; i++)
    {
        int digit=num%TEN;
        if (digit<1 || digit>4)
        {
            throw out_of_range("You should enter a positive number, with 8 digits in range of 1-4");
        }
            num/=TEN;
    }
}

namespace ariel {

string snowman(int num) {

    check_input(num);

    const int n = num;
    const int h = n/10000000;
    const int lau = (n/1000)%TEN;
    const int le = (n/100000)%TEN;
    const int nos = (n/1000000)%TEN;
    const int re = (n/10000)%TEN;
    const int rau = (n/100)%TEN;
    const int lad = (n/1000)%TEN;
    const int t = (n/10)%TEN;
    const int rad = (n/100)%TEN;
    const int b = n%TEN;
    const int len = 5;
    
    //save the snowman body parts into arrays
    const array<string,len> hat = {"","       \n _===_ \n","  ___  \n ..... \n","   _   \n  /_\\  \n","  ___  \n (_*_) \n"};
    const array<string,len> left_arm_up = {""," ","\\"," "," "};
    const array<string,len> left_eye = {"","(.","(o","(O","(-"};
    const array<string,len> nose = {"",",",".","_"," "};
    const array<string,len> right_eye = {"",".)","o)","O)","-)"};
    const array<string,len> right_arm_up = {""," \n","/\n"," \n"," \n"};
    const array<string,len> left_arm_down = {"","<"," ","/"," "};
    const array<string,len> torso = {"","( : )","(] [)","(> <)","(   )"};
    const array<string,len> right_arm_down = {"",">\n"," \n","\\\n"," \n"};
    const array<string,len> base = {""," ( : ) "," (\" \") "," (___) "," (   ) "};
    
    return hat.at(h)+left_arm_up.at(lau)+left_eye.at(le)+nose.at(nos)+right_eye.at(re)+right_arm_up.at(rau)+left_arm_down.at(lad)+torso.at(t)+right_arm_down.at(rad)+base.at(b);
    }
}