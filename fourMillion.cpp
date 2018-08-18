//example
/*
16.写一个函数找出一个整数数组中，第二大的数 （microsoft）
答案：
const int MINNUMBER = -32767 ;
int find_sec_max( int data[] , int count) //类似于1 4 4 4这样的序列将认为1是第二大数
{
    int maxnumber = data[0] ;
    int sec_max = MINNUMBER ;
    for ( int i = 1 ; i < count ; i++)
    {
         if ( data[i] > maxnumber )
        { 
            sec_max = maxnumber ;
            maxnumber = data[i] ;
        }
         else
        {
             if ( data[i] > sec_max )
               sec_max = data[i] ;
         }
      }
      return sec_max ;
}
char * strcpy( char *strDest, const char *strSrc )
　　{
　　assert( (strDest != NULL) &&(strSrc != NULL) ); 
　　char *address = strDest;
　　while( (*strDest++ = * strSrc++) != ‘\0’ );
　　return address;
　　}
它没有包括字符串末尾的'\0'。
int strlen( const char *str ) //输入参数const　以下是引用片段：
　{
　　assert( strt != NULL ); //断言字符串地址非0
　　int len=0; //注，一定要初始化。
　　while( (*str++) != '\0' )
　　{
　　len++;
　　}
　　return len;
　　}
class String
{
public:
String(const char *str = NULL); // 通用构造函数
String(const String &another); // 拷贝构造函数
~ String(); // 析构函数
String & operater =(const String &rhs); // 赋值函数
private:
char *m_data; // 用于保存字符串
};

尝试写出类的成员函数实现。

答案：
String::String(const char *str)
{
if ( str == NULL ) //strlen在参数为NULL时会抛异常才会有这步判断
{
m_data = new char[1] ;
m_data[0] = '\0' ;
}
else
{
m_data = new char[strlen(str) + 1];
strcpy(m_data,str);
}

} 

String::String(const String &another)
{
m_data = new char[strlen(another.m_data) + 1];
strcpy(m_data,other.m_data);
}

String& String::operator =(const String &rhs)
{
if ( this == &rhs)
return *this ;
delete []m_data; //删除原来的数据，新开一块内存
m_data = new char[strlen(rhs.m_data) + 1];
strcpy(m_data,rhs.m_data);
return *this ;
}


String::~String()
{
delete []m_data ;
}
*/
#include<iostream>  
#include<string.h>  
#include<fstream>  
using namespace std;  
void setBit(char *arr,unsigned int num);  
int isSet(char *arr,unsigned int num);  
unsigned char tag[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  
int main()  
{  
    char * arr=new char[5242880];//512M  
    memset(arr,0,5242880);  
    unsigned int num;  
    fstream in("1.txt",ios::in);  
    while(in>>num)  
    {  
        setBit(arr,num);  
    }  
    in.close();  
    cout<<"初始化完毕..."<<endl;  
    cout<<"请输入需要判断的数：";  
    while(cin>>num)  
    {  
        if(isSet(arr,num)!=0x00)  
        {  
            cout<<num<<"在数组中"<<endl;  
        }else  
            cout<<num<<"不在数组中"<<endl;  
    }  
    delete[] arr;  
    return 0;  
}  
/* 
*功能:将num对应位置为1 
*/  
void setBit(char *arr,unsigned int num)  s
{  
    int loc=num/8;  
    int remainder=num%8;  
    arr[loc]=arr[loc] | tag[remainder];  
}  
/* 
*功能:判断num对应位是否置为1? 
*/  
int isSet(char *arr,unsigned int num)  
{  
    int loc=num/8;  
    int remainder=num%8;  
    return arr[loc] & tag[remainder];  
}  
