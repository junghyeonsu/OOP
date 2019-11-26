#include "String.h"
#include "Object.h"

//String class의 생성자 _val 을 str 으로 설정해준다.
String::String(const std::string& str)
{
   _val = str;
}


//String class 의 _val 변수를 리턴해주는 val() 함수 
std::string String::val()
{
   return _val;
}

//String class의 _val 을 설정하는 set_val 함수 
void String::set_val(const std::string& str)
{
   this->_val = str;
}

//string class의 type을 반환해주는 type() 함수 
json_object::_type String::type()
{
   return STRING;
}

//String class의 to_string 함수
std::string String::to_string()
{
   return '\'' + this->_val + '\'';
}


//String class의 parse 함수
json_object* String::parse(const char* str, int length, char base)
{
   //index json_object class 에서 불러온다.	
   int& a = json_object::_index;
   //임시저장 문자열을 생성해준다.
   std::string temp = "";
   //index끝까지
   while (a < length)
   {
	  //두 경우로 나뉘는데
      switch (str[a])
      {
	  // 문자열 시작을 알리는 부분과
      case '\'':
         return new String(temp);
	  // 문자열들	 
      default:
         temp += str[a];
         break;
      }
	  // 인덱스를 늘려준다.
      ++a;
   }

   return NULL;
}

