#include<iostream>
using namespace std;
class Car{
public:
    //^attributes
    string Brand;
    int model;
    int year;
    int num;
    //^constructor-->default
    Car(){
        cout<<"Hello iam consctructor:"<<endl;
    }

    //^parametised constructor
    Car(string brand_name,int model_name,int year_name){
        this->Brand=brand_name;
        this->model=model_name;
        this->year=year_name;
        cout<<"Brand name is:"<<brand_name<<"model name is:"<<model_name<<"year is:"<<year_name;
    }

    //^Function(methods) void return type
    void feature(){
        cout<<"Hii iam a method with void return type"<<endl;
    }

    //^function with return type 
     int print(int a){
        this->num=a;
        cout<<"number of car:"<<a<<endl;
     }











    ~Car(){
        cout<<"hello iam desc"<<endl;
    }


};

int main(){
    //!statically creating object
    Car obj;  //*jaise hi yeh object bnaye h waise hi default constructor call ho jayega
    Car obj1("Deisre",2018,2000);  //^iss  object ko parametised cons  denote kr rha h
    cout<<endl;
    //!dynamically creating object
     Car *obj3=new Car();  //^jaise yeh bnega wiase hi const call hoga

     Car *obj4=new Car("Honda",1998,2205); //iske liye pararmetisw cont aayega
     cout<<endl;

     //^callying method

     obj.feature();
     obj1.feature();
     obj3->feature();
     //!theye all will give same result its independent of with which object we are calling method

    obj.print(23);
     obj1.print(24);
     obj3->print(25);



    
}
