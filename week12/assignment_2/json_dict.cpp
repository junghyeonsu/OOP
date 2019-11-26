#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

//dictionary class 의 put 함수
void json_dict::put(json_object* key, json_object* val)
{  
   // key 값과 value 값을 push 해준다.	
   v.push_back({ key, val });
}


//dictionary class 의 find 함수
int json_dict::find(json_object* key)
{
   //key 값을 찾기 위해서 key 를 to_string 함수를 통해서 string type 으로 변환해준다	
   std::string findkey = key->to_string();

   //벡터의 원소를 검사해서 만약 key 값이 같은게 있으면 key 를 리턴해줌.
   for (int i = 0; i < v.size(); i++)
   {
      if (v[i].first->to_string() == findkey)
         return i;
   }
   //그게아니면 -1 을 리턴한다.
   return -1;
}


//생성자
json_dict::json_dict(){}


//dictionary class 의 parse 함수 
json_object* json_dict::parse(const char* str, int length)
{  

   // 변수들을 설정해준다.	
   int number = 0;
   int& index = json_object::_index;
   json_dict *tmp_dict = new json_dict();
   json_object *key = NULL,*val = NULL;
   bool _isKey = true;

   //문자열을 다 돌때까지 반복
   while (index < length) 
   {
	  //문자열의 인덱스를 검사한다 
      switch (str[index])
      {
	  //역슬레쉬가 오면	  
      case '\'':
		 //다음 문자열을 보고 
         index++;
		 //key값이 있으면 key값을 parse해주고 아니면 value를 parse 해준다.
         if (_isKey)
            key = String::parse(str, length, '\''); 
         else
            val = String::parse(str, length, '\''); 
         break;

	  // : 문자일 경우	 
      case ':':
		 // key값이 없다는 소리니까 _isKey 변수에 false 를 넣어준다
         _isKey = false;
         break;

	  // , 가 왔다는건 dictionary 라는 뜻	 
      case ',':
		 //객체를 생성하고 key 을 찾은뒤 넣어준다
         number = tmp_dict->find(key);
		 // number 가 -1 이 아니라는것은 key 을 찾았다는 얘기니까 value를 찾아서 넣어준다.
		 // -1 이라면 put해준다 
         if (number != -1)
            tmp_dict->v[number].second = val;
         else
            tmp_dict->put(key, val);
         _isKey = true;
         break;

	  // [ 문자가 오면	 
      case '[':
		 //다음 문자를 본다.
         index++;
		 // [ 문자는 리스트시작을 알리는 문자이기때문에
		 // list class 의 parse 함수를 불러준다.
         val = json_list::parse(str, length);
         break;

	  // { 문자일 경우	 
      case '{':
		 //다음 문자를 본다.
         index++;
		 // { 문자는 dictionary 의 시작을 알리는 문자이기 때문에
		 // dictionary class 의 parse 함수를 호출 해준다.
         val = json_dict::parse(str, length);
         break;

	  // } 문자일 경우	 
      case '}':
		 // dictionary 가 끝났다는걸 알리는 문자이기 때문에 키 값을 find 하여서 number에 넣어준다
         number = tmp_dict->find(key);
		 // number 가 -1 이 아니라는것은 key 값이 존재한다는 것이기 때문에
		 // value를 찾아서 넣어주고
		 // 그가 아니면 벡터마지막에 put 을 해준다.
         if (number != -1)//키값이 존재한다면
            tmp_dict->v[number].second = val;
         else
            tmp_dict->put(key, val);
         return tmp_dict;

	  // 공백이면 그냥 break 해준다. 	 
      case ' ':
         break;


      default:
         if (_isKey)
            key = Integer::parse(str, length);
         else
            val = Integer::parse(str, length);
         --index;
         break;
      }
	  // 다음문자를 보기위한 인덱스 증가
      index++;
   }

   return tmp_dict;
}


// [] 연산자 오버로딩 함수
json_object* json_dict::operator[](json_object* key) const
{
   // key의 type 가 integer(정수) 형태 일 경우	
   if (key->type() == json_object::INT)
   {
	  //정수형에 오버로딩 함수를 리턴한다.  
      return operator[](atoi(key->to_string().c_str()));
   }
   // key의 type 가 string(문자열) 형태 일 경우
   else if (key->type() == json_object::STRING)
   {
	  // 문자열에  오버로딩 함수를 리턴한다. 
      return operator[](key->to_string());//문자열에 오버로딩되는 함수를 리턴한다.
   }

   return NULL;
}


// 문자열에 오버로딩되는 연산자 오버로딩 함수
json_object* json_dict::operator[](const std::string& key) const
{
   std::string _key = '\'' + key + '\'';
   for (std::pair<json_object*, json_object*> _tmp : v)
   {
      if (_tmp.first->to_string() == _key)
         return _tmp.second;
   }
   return NULL;
}

// 정수형에 오버로딩되는 연산자 오버로딩 함수
json_object* json_dict::operator[](int key) const
{
   for (std::pair<json_object*, json_object*> _tmp : v)
   {
      int _key = atoi(_tmp.first->to_string().c_str());
      if (_key == key)
         return _tmp.second;
   }
   return NULL;
}

//dictionary 의 type 를 return 하는 함수 
json_object::_type json_dict::type()
{
   return DICT;
}

//dictionary class 의 to_string 함수
std::string json_dict::to_string()
{
   //vector 의 사이즈가 0 이면 그냥 {} 를 리턴한다.	
   if (v.size() == 0)
      return "{}";

   // dictionary의 { << 시작을 알리는 문자
   std::string string = "{";
   // 반복문으로 벡터의 key와 value 를 넣어준다
   for (int i = 0; i < v.size() - 1; i++)
   {
	  // dictionary 형태로 만들어주기위한 작업 
      string += v[i].first->to_string() + ": " + v[i].second->to_string();
      string += ", ";
   }
   // 마지막으로 넣어주는 작업
   string += v[v.size() - 1].first->to_string() + ": " + v[v.size() - 1].second->to_string() + '}';
   return string;
}
