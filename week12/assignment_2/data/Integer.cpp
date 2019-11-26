#include "Integer.h"

//Integer class 의 생성자로 value는 private 변수 _val 로 설정해준다.
Integer::Integer(int value)
{
   _val = value;
}

//Integer class 의 _val 을 보여주는 val() 함수
int Integer::val()
{
   return _val;
}

//Integer class 의 _val 을 설정해주는 set_val() 함수
void Integer::set_val(const int& value)
{
   _val = value;
}

//Integer 의 type 를 반환해주는 type() 함수
json_object::_type Integer::type()
{
   return INT;
}

//Integer를 string으로 바꿔주는 to_string() 함수
std::string Integer::to_string()
{
   return std::to_string(_val);
}

//Integer class 의 parse 함수
json_object* Integer::parse(const char * string, int length)
{
   int startIndex = _index;
   while (string[_index] >= '0' && string[_index] <= '9') {
      _index++;
   }
   std::string str = std::string(string);
   return new Integer(std::stoi(str.substr(startIndex, _index - startIndex)));
}
