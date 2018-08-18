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
    cout<<"��ʼ�����..."<<endl;  
    cout<<"��������Ҫ�жϵ�����";  
    while(cin>>num)  
    {  
        if(isSet(arr,num)!=0x00)  
        {  
            cout<<num<<"��������"<<endl;  
        }else  
            cout<<num<<"����������"<<endl;  
    }  
    delete[] arr;  
    return 0;  
}  
/* 
*����:��num��Ӧλ��Ϊ1 
*/  
void setBit(char *arr,unsigned int num)  s
{  
    int loc=num/8;  
    int remainder=num%8;  
    arr[loc]=arr[loc] | tag[remainder];  
}  
/* 
*����:�ж�num��Ӧλ�Ƿ���Ϊ1? 
*/  
int isSet(char *arr,unsigned int num)  
{  
    int loc=num/8;  
    int remainder=num%8;  
    return arr[loc] & tag[remainder];  
}  