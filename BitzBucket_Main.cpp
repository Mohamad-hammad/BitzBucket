#include <iostream>
#include<fstream>
#include<string>
#include<windows.h>

using namespace std;

struct student//struct to store student data
{
    string name;
    float cgpa;
    float gpa;
    float* quizes;
    string *courses;
    int rankinclass;
    string remarks;//remarks are generated automatically by evaluating by app by using the goal the student set and current progress of student in class
};
void getstudentdata(student &obj)//this function will get data from api
{
    //as we can implement api integration at this stage so we have just manually entered the logged in student data
    obj.name="Ahmed";
    obj.cgpa=3.5;
    obj.gpa=3.7;
    obj.quizes=new float[5];
    obj.quizes[0]=55;
    obj.quizes[1]=62;
    obj.quizes[2]=45;
    obj.quizes[3]=32;
    obj.quizes[4]=75;
    obj.courses=new string[5];
    obj.courses[0]="Digital Logic Design";
    obj.courses[1]="Assembly Language";
    obj.courses[2]="Data Structures";
    obj.courses[3]="Algorithms";
    obj.courses[4]="Linear ALgebra";
    obj.rankinclass=12;
    obj.remarks="Need to improve marks in quizes to get a SGPA of 3.8 and CGPA of 3.6";

}
void API(){}//API intigerated with certain paymentgateway
void academicprogress(student obj)//To show all the academic progress of student
{
    system("cls");
   float currentcgpa=3.5;//in app it will be taken from the integrated api of university data base
    int cgpapercent=(currentcgpa/4)*25;
    cout<<endl;
    cout<<"[ ";
    for(int i=0;i<25;i++)//loop to print the bar of cpga
    {
        if(i<=cgpapercent)
        {
            char ch=219;
            cout<<ch;
        }
        else
            cout<<"  ";
    }
    cout<<" ]"<<endl;
    cout<<"CGPA: "<<3.5<<endl;
    getstudentdata(obj);
    cout<<"_____________________________________________________________________\n\n"<<endl;
    cout<<"Quizes Marks:\n\n"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"Quiz#"<<i+1<<": "<<obj.quizes[i]<<endl;
    }
    cout<<"\n\n_____________________________________________________________________"<<endl;
    cout<<"Press Enter to go back"<<endl;
    system("pause");
    system("cls");
}

void DisplayLoanForm() {
    cout << "this function will display an online form to be filled with personal & financial details so accounts office can evaluate this request\n";
}
void Loans() {
    system("CLS");
    int semesters = 4; //this will be taken from APP to find out how many semesters a student has completed
    int warning_count_history = 0; // this data will be taken from API and shows how many times a student was on academic warning
    if ((semesters < 8) && (warning_count_history == 0)) {
        cout<<"\nWould you like to apply for a loan?\n";
        bool c1;
        cout << "1--> Yes\n0--> No\n";
        cin >> c1;
        if (c1) {
            DisplayLoanForm();//this function will display an online form to be filled with personal & financial details so accounts office can evaluate this request
        }
    }
    int Remaining_Loan = 0, N_installments=0, installment=0 ;
    //this data will be take from API regarding their remaining loan
    if (Remaining_Loan >= 1000000) {
        N_installments = 80;
        installment = Remaining_Loan / 80;
    }
    else if (Remaining_Loan >= 500000) {
        N_installments = 48;
        installment = Remaining_Loan / 48;
    }
    else if (Remaining_Loan >= 300000) {
        N_installments = 36;
        installment = Remaining_Loan / 36;
    }
    else if (Remaining_Loan < 300000) {
        N_installments = 24;
        installment = Remaining_Loan / 24;
    }
    cout << "\n\n--------Your Current Loan Status-------\n";
    if (Remaining_Loan == 0) {
        cout << "You currently do not have any amount due\n";
    }
    else
        cout << "Remaining Amount: " << Remaining_Loan << "\n Number of Installments: " << N_installments << "\n Amount per Installment: " << installment<<endl;
    system("pause");
    system("cls");
}
void Pay()
{
    // pay bills
    int opt;
    bool flag=true;
    while(flag ==true)
    {
        system("cls");
        cout<<"For What do you want to pay for: "<<endl;
        cout<<"1.Cafeteria"<<endl;
        cout<<"2.Parking Tickets"<<endl;
        cout<<"3.Pay Fees"<<endl;
        cout<<"4.Other Payments"<<endl;
        cout<<"5.Back"<<endl;
        cout<<"Enter option: i.e 1-5: ";
        cin>>opt;
        if(opt==1)
        {
            float amount;
            int id;
            cout<<"Enter paymentID:"<<endl;
            cin>>id;
            cout<<"enter Amount:";
            cin>>amount;
            cout<<"Amount Payed successfuly"<<endl;
        }
        else if(opt==2)
        {
            float amount;
            int id;
            cout<<"Enter paymentID for Parking Ticket:"<<endl;
            cin>>id;
            cout<<"enter Amount:";
            cin>>amount;
            cout<<"Amount Payed successfuly"<<endl;
        }
        else if(opt==3)
        {
            float amount;
            int id;
            cout<<"Enter paymentID for fee challan:"<<endl;
            cin>>id;
            cout<<"enter Amount:";
            cin>>amount;
            cout<<"Amount Payed successfuly"<<endl;
        }
        else if(opt==4)
        {
            //check from api if any payment is due for the student or not
            //if payment is due show the payment id and amount
            //else show no payment due to pay
            cout<<"No payment Due to Pay"<<endl;
        }
        else if(opt==5)
        {
            flag=false;
        }
       system("pause");
        system("cls");
    }
}

void JobsAndInternships() {
    system("cls");
    int semesters = 4; //this will be taken from APP to find out how many semesters a student has completed

    int warning_count = 0; // this data will be taken from API and shows current academic warnings of a student
    if (semesters > 6) {
        if (warning_count == 0) {
            cout << "1. Data scientist.\n2.Software tester\n2.Web developer\n3.Systems analyst\n4.Business analyst\n5.Product manager\n6.Network architect\n7.Software engineer.\n";
        }//Student can choose to apply to any of the following jobs
        else {
            cout << "Dear Student, Kindly focus on removing your Academic Warning before applying for jobs\n";
        }
    }
    else {
        cout << "Dear Student, Jobs are not available for you yet. Happy Studying!!\n";
    }
    cout<<"Press Enter to continue"<<endl;
    cin.ignore();
    cin.ignore();
    system("cls");
}

void EditProfile(student &obj)
{
    system("cls");
    cout<<"Edit Profile:"<<endl;
    cin.ignore();
    cout<<"Enter Name:";
    getline(cin,obj.name);
    cout<<"Profile Update Successfully"<<endl;
    system("pause");
    system("cls");
}
void OnlineClassBehaviourMonitor()
{
    system("cls");
    float quizes=45;//overall percentage of quizes
    float classpaticipation=25;//overall percentage of class participation
    float attendence=50;//overall percentage of attendance

    /*
    Note: As there are some student who might have internet connectivity issue so for that reason system will be continously
    calculating the internet speed of student and if average internet speed is less than 300kb/sec then the class participation
    would be marked 70% for that class.
    FORMULA USED TO CALCULATE THE PERFORMANCE OF STUDENT IN CLASS
    100% of class participation= 40% quizes + 20% attendance + 40% class participation
    */
    float classperformance;
    classperformance=(0.4*quizes)+(0.2*attendence)+(0.4*classpaticipation);
    cout<<"Class Performance: "<<classperformance<<"%"<<endl;

    cout<<"Remarks: ";
    if(classperformance>=70)
        cout<<"Excellent behaviour in class"<<endl;
    else if(classperformance>40 && classperformance<70)
        cout<<"Satisfactory performance in online class"<<endl;
    else if(classperformance<=40)
    {
        cout<<"Need to Focus more in class and participate in class activity"<<endl;
    }
    cout<<"Press enter to continue"<<endl;
    cin.ignore();
    cin.ignore();
    system("cls");
}
void Logout()
{
    cout<<"Logging Out"<<endl;
    cout<<"Logged Out"<<endl;
}
void mainmenu()//print mainmenu
{
    cout<<">>>>>>>>>>>>>>>>>>MAIN MENU<<<<<<<<<<<<<<<<"<<endl;
    cout<<"1.Online Class Behaviour Monitor"<<endl;
    cout<<"2.Academic Progress"<<endl;
    cout<<"3.Loans"<<endl;
    cout<<"4.Pay"<<endl;
    cout<<"5.Jobs and Internships"<<endl;
    cout<<"6.Edit Profile"<<endl;
    cout<<"7.Logout"<<endl;
}
int main()
{
    student obj;//object of student struct.
    int opt;
    bool flag=true;
    while(flag==true)
    {

        mainmenu();
        cout<<"\nEnter option: ";
        cin>>opt;
        if(opt==1)
        {
            OnlineClassBehaviourMonitor();
        }
        if(opt==2)
        {
            academicprogress(obj);
        }
        else if(opt==3)
        {
            Loans();
        }
        else if(opt==4)
        {
            Pay();
        }
        else if(opt==5)
        {
           JobsAndInternships();
        }
        else if(opt==6)
        {
            EditProfile(obj);
        }
        else if(opt==7)
        {
            Logout();
            flag=false;
        }
    }

    return 0;
}
