#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

//인덱스 참조 변수 선언
int json_object::_index = 0; 


json_object* json_object::parse(const char* str, int length)//파싱하는 함수
{
   json_object* T = NULL;//임시 문자열을 선언한다.
   while (_index < length)//문자열의 길이만큼 반복.
   {
      switch (str[_index])//스위치문을 이용해서 문자가 뭔지 판단한다. 
      {
      case '{':// 문자가 { 인 경우
         _index++;
         T = json_dict::parse(str, length);//사전 cpp의 파싱 호출
         break;
      case '[':// 문자가 [ 인경우
         _index++;
         T = json_list::parse(str, length);//리스트 파싱호출
         break;
      case '\''://string인 경우
         _index++;
         T = String::parse(str, length, '\'');//string 파싱 호출
         break;
      default://integer인 경우
         if (str[_index] > '0' && str[_index] < '9')
            T = Integer::parse(str, length);//integer인지 검사 후에 파싱호출
         break;
      }
      _index++;
   }

   _index = 0;
   return T;
}

//문자열 parse 함수
json_object* json_object::parse(const std::string& str)
  {
	  //클래스 내에서 호출하도록 되어있음
     return parse(str.c_str(), str.length());
  }

