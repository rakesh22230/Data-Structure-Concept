
#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;
int globalId = 100;
class person{
    string name;
    int id;
    float salary;
 public:
 // create constructor 
     person(){
        name = " ";
        id = -1;
        salary = -1.0;
     }
     // set name
     void setname(string name){
        this->name = name;
     }
     // set salary
     void setsalary(float salary){
        this->salary = salary;
     }
     
     person(string name,float salary){
        setname(name);
        setsalary(salary);
        id = globalId;
        globalId++;
     }
     // get name and salary , Id
     int getId(){
        return id;
     }
     string getname(){
        return name;
     }
     float getsalary(){
        return salary;
     }
     void print(){
        cout<<name<<" | "<<id<<" | "<<salary<<endl;
     }

};
int main() {
    Stack <person> st;
    person a ("Rakesh Barman",1000);
    person b ("Saron",900);
    person c ("Majedul",950);
    st.push(a);
    st.push(b);
    st.push(c);
    cout<<"Top value: ";
    person printobj;
    printobj = st.Top();
    printobj.print();
    while(!st.empty()){
        person printobj;
        printobj = st.pop();
        printobj.print();
    }

    return 0;
}
