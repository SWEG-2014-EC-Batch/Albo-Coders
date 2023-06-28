#include<iostream>
using namespace std;
//Structure with student attribute to calculate sum of mark.

struct student{
    int id;
    char name[15];
    float testmark,finalmark;
    };

    int main(){
        int n;
        float total=0;
        cout<<"Enter the number of students:";
        cin>>n;
        student stud[n];
        for(int i=0;i,n;i++){
            cout<<" Enter student"<<i+1<<"data:"<<endl;
            cout<<"id:";
            cin>>stud[i].id;
            cout<<"Name:";
            cin>>stud[i].name;
            cout<<"Test Mark:";
            cin>>stud[i].testmark;
            cout<<"Final Mark:";
            cin>>stud[i].finalmark;
            total+=stud[i].testmark+stud[i].finalmark;

        }
        cout<<" Student Records:"<<endl;
        for (int i = 0; i < n; i++) {
        cout << "ID: " << stud[i].id << endl;
        cout << "Name: " << stud[i].name << endl;
        cout << "Test Mark: " << stud[i].testmark << endl;
        cout << "Final Mark: " << stud[i].finalmark << endl;
    }

    cout << "Total Marks: " << total << endl;

    return 0;


    }
