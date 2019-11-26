#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

//생성자
json_list::json_list()
{
   v = std::vector<json_object*>();
}


//list class 의 parse 함수 
json_object* json_list::parse(const char* str, int length)
{
   //index값을 불러온다.	
   int& index = json_object::_index;


   //value값 생성
   json_object* val = NULL;
   //list 객체 생성
   json_list* list = new json_list();


   //들어온 index의 길이만큼 반복한다. (문자열의 끝까지)
   while (index < length)
   {
	  //index마다 어떤 값이 들어오냐에 따라 나뉘기 때문에 switch 문을 써줬다.
      switch (str[index]) 
      {
	  //문자열인 경우에는		  
      case '\'':
         ++index;
		 // value 를 string 클래스의 parse 함수로 parsing 해준다.
         val = String::parse(str, length, '\'');
         break;
	  // ,	이 들어온 경우에는 
      case ',':
		 // value 가 null 이 아니어야 한다.
         if (val != NULL) 
         {
			// null 이 아니니까 list 에 push 해준다. 
            list->v.push_back(val);
            val = NULL;
         }
         break;
	  //리스트 시작 부분인 경우	 
      case '[':
		 //인덱스를 늘리고 
         index++;
		 //들어오는 value를 list 클래스의 parse 함수로 parse해준다. 
         val = json_list::parse(str, length);
         break;
	  //리스트의 마지막 부분인 경우
      case ']':
		 // ] 전에있던 값을 push 해준다.
         if (val != NULL)
            list->v.push_back(val);
         return list;
	  // { 인 경우
      case '{':
         //dictionary 클래스의 parse 함수를 호출한다.
         val = json_dict::parse(str, length);
         break;
	  //공백인 경우	  
      case ' ':
		 //아무것도하지않고 그냥 break
         break;
	  //integer 인 경우  		 
      default://integer클래스의 parse함수 호출
         val = Integer::parse(str, length);
         --index;
         break;
      }
      ++index;
   }
   return NULL;
}


//v[key] = value
json_object* json_list::operator[](int key) const
{
   return v[key];
}

//타입을 반환하는 함수 
json_object::_type json_list::type()
{
   return json_object::LIST;
}

//string으로 반환하는 함수
std::string json_list::to_string()
{
   std::string string = "[";
   if (v.size() == 0)
      return "[]";

   for (int i = 0; i < v.size() - 1; i++)
   {
      string += v[i]->to_string() + ", ";
   }

   string += v[v.size() - 1]->to_string() + "]";
   return string;
}
