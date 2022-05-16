#include <iostream>
#include <windows.h>
#include <fstream>
#include "sortedtype.cpp"



using namespace std;

struct extra
{
    string pass;
    string name;
    float Balance;
    string address;
    long number;
};
struct AccountInfo
{
    extra aditional;
    int ID;
};
void admin(SortedType<extra>&);
AccountInfo login(SortedType<extra>&);
void activities(SortedType<extra>& ,AccountInfo&);
void Edit(AccountInfo&);
bool Checkpass(string);
long phonemun();

int main()
{
    int choice1,tempId,done;
    bool Ok=false,ok1=false,ok2=false;
    string adminID, adminpass;
    AccountInfo loginperson,tempAccinfo;

    SortedType<extra> list1;
    ofstream readfile2("listofAccount.txt");
    ifstream readfile1("listofAccount.txt");
    while(readfile1>>tempAccinfo.ID>>tempAccinfo.aditional.pass>>tempAccinfo.aditional.name>>tempAccinfo.aditional.Balance>>tempAccinfo.aditional.address>>tempAccinfo.aditional.number)
    {
        list1.InsertItem(tempAccinfo.aditional,tempAccinfo.ID);
    }



    do{
        Ok=true;
        cout<<"\tChoose from below :\n\t1.User\n\t2.Admin\n\t3.Create Account\n\tEnter you option : ";
        cin>>choice1;

        switch(choice1)
        {
        case 1:
            loginperson=login(list1);
            activities(list1,loginperson);
            list1.InsertItem(loginperson.aditional,loginperson.ID);

            break;
        case 2:

            do{
                ok1=false;
                cout<<"Enter ID : ";
                cin>>adminID;
                if(adminID=="CSE225L")
                {
                    do{
                        ok2=false;
                        cout<<"Enter Password : ";
                        cin>>adminpass;
                        if(adminpass=="lab")
                        {
                            admin(list1);

                        }
                        else
                        {
                            cout<<"Wrong ID!!!\n try again..."<<endl;
                            ok2=true;
                        }
                    }while(ok2);


                }
                else
                {
                    cout<<"Wrong ID!!!\n try again..."<<endl;
                    ok1=true;
                }
            }while(ok1);
            break;
        case 3:
            do{
                cout<<"Enter a ID you want : ";
                cin>>tempId;
                list1.RetrieveItem(tempAccinfo.aditional,ok1,tempId);
                if(ok1)
                {
                    cout<<"This id is already been taken. Choose another one!!!"<<endl;
                }
                else
                {
                    tempAccinfo.ID=tempId;
                    cout<<"Enter your Name : ";
                    cin>>tempAccinfo.aditional.name;
                    cout<<"Enter your Phone Number : ";
                    tempAccinfo.aditional.number=phonemun();
                    cout<<"Enter your Address : ";
                    cin>>tempAccinfo.aditional.address;
                    cout<<"Enter Password : ";
                    cin>>tempAccinfo.aditional.pass;
                    tempAccinfo.aditional.Balance=100.00;
                    cout<<"You got 100.00TK welcome gift!!!"<<endl;
                    list1.InsertItem(tempAccinfo.aditional,tempAccinfo.ID);

                }

            }while(ok1);
            cout<<"Account is opened successfully!!!  "<<endl;
            break;

        default:
            Ok=true;
            cout<<"Wrong Option selected\nPlease try again!!!";
        }

        cout<<"Press 1 to exit.."<<endl;
        cin>>done;
        if(done==1)
        {
            Ok==false;
        }
    }while(Ok);

    system("cls");

    int length=list1.LengthIs();
    for(int i=0;i<length;i++)
    {
        readfile2<<tempAccinfo.ID<<tempAccinfo.aditional.pass<<tempAccinfo.aditional.name<<tempAccinfo.aditional.Balance<<tempAccinfo.aditional.address<<tempAccinfo.aditional.number<<endl;
    }
    readfile2.close();
    list1.~SortedType();
    cout<<"\t\t\tThank You"<<endl;

    return 0;
}

void admin(SortedType<extra>& z1)
{
    bool ok,ok1;
    int switchnum,flag,tempbalance;
    AccountInfo temp;
    do
    {
        ok=true;
        cout<<"Choose from below \n1.view own profile \n2.deposed \n3.See profiles \n4.delete Profile\nEnter your choice : ";
        cin>>switchnum;
        switch(switchnum)
        {
        case 1:
            cout<<"Name : MKN1\nAddress : NSU\nPhone Number : 01234567890"<<endl;
            break;
        case 2:
            cout<<"Enter Id : ";
            cin>>flag;
            z1.RetrieveItem(temp.aditional,ok1,flag);
            if(ok1)
            {
                temp.ID=flag;
                z1.DeleteItem(temp.aditional,temp.ID);
                cout<<"Enter Amount : ";
                cin>>tempbalance;
                temp.aditional.Balance=temp.aditional.Balance+tempbalance;
                z1.InsertItem(temp.aditional,temp.ID);
                cout<<"Successful deposited"<<endl;
            }
            else
            {
                cout<<"Wrong Id!!! Try again..."<<endl;
            }
            break;
        case 3:
            flag=z1.LengthIs();
            for(int i=0;i<flag;i++)
            {
                z1.GetNextItem(temp.aditional,temp.ID);
                cout<<"ID : "<<temp.ID<<" Name : "<<temp.aditional.name<<" Phone Number : "<<temp.aditional.number<<" Balance : "<<temp.aditional.Balance<<" Address : "<<temp.aditional.address<<endl;
            }
            z1.ResetList();
        case 4:
            cout<<"Enter Id : ";
            cin>>flag;
            z1.RetrieveItem(temp.aditional,ok1,flag);
            if(ok1)
            {
                z1.DeleteItem(temp.aditional,temp.ID);

                cout<<"Successfully deleted !!! "<<endl;
            }
            else
            {
                cout<<"Wrong Id!!! Try again..."<<endl;
            }
            break;
        default :
            ok=true;
            cout<<"Wrong Option!!! try again..."<<endl;

        }


    }while(ok);
}
AccountInfo login(SortedType<extra>& z1)
{
    bool check,ok1=false,ok2=false;
    int id;
    string pass;
    AccountInfo info;
    do{
        ok1=false;
        cout<<"Enter Id : ";
        cin>>id;
        z1.RetrieveItem(info.aditional,check,id);
        if(check)
        {
            do
            {
                ok2=false;
                cout<<"Enter password : ";
                cin>>pass;
                if(pass==info.aditional.pass)
                {
                    info.ID=id;
                    z1.DeleteItem(info.aditional,info.ID);
                    return info;
                }
                else
                {
                    ok2=true;
                    cout<<"You enter wrong password!!! Try again..."<<endl;
                }
            }while(ok2);

        }
        else
        {
            ok1=true;
            cout<<"You enter Wrong Id!!!\nTry again..."<<endl;
        }

    }while(ok1);
}

void activities(SortedType<extra>& z1,AccountInfo& info)
{
    bool logout=true,ok;
    AccountInfo tempinfo;
    int id,code;
    int switchnum;
    long number;
    float amount;
    do{
        logout=true;
        cout<<"Choose from below....\n1.View profile\n2.Edit profile\n3.Recharge mobile\n4.Send money\n5.Deposit\n6.Log Out\nEnter Your Option : ";
        cin>>switchnum;
        switch(switchnum){
        case 1:
            cout<<"Your profile : \nId : "<<info.ID<<"\nName : "<<info.aditional.name<<"\n Balance : "<<info.aditional.Balance
            <<"\nPhone Number : "<<info.aditional.number<<"\nAddress : "<<info.aditional.address<<endl;

            break;
        case 2:
            Edit(info);
            break;
        case 3:
            cout<<"Enter Phone number : ";
            number=phonemun();
            cout<<"Enter amount : ";
            cin>>amount;
            if(amount<=info.aditional.Balance)
            {
                info.aditional.Balance=info.aditional.Balance-amount;
                cout<<"successful recharged"<<endl;
            }
            else
            {
                cout<<"you do not have sufficient balance in the account please deposit!!!"<<endl;
            }
            break;
        case 4:
            cout<<"Enter Id of the account : ";
            cin>>id;
            z1.RetrieveItem(tempinfo.aditional,ok,id);
            if(ok)
            {
                tempinfo.ID=id;
                z1.DeleteItem(tempinfo.aditional,tempinfo.ID);
                cout<<"Enter amount : ";
                cin>>amount;
                if(amount<=tempinfo.aditional.Balance)
                {
                    tempinfo.aditional.Balance=tempinfo.aditional.Balance-amount;
                    cout<<"successful transferred"<<endl;
                    z1.InsertItem(tempinfo.aditional,tempinfo.ID);
                }
                else
                {
                    cout<<"you do not have sufficient balance in the account please deposit!!!"<<endl;
                }
            }
            else
            {
                cout<<"There is no account with id : "<<id<<". Try again"<<endl;
            }
            break;

        case 5:
            cout<<"enter credit card number : ";
            number=phonemun();
            cout<<"Enter 6 digit code : ";
            cin>>code;
            if(code==123456)
            {
                cout<<"enter amount : ";
                cin>>amount;
                if(amount>=5000.00)
                {
                    info.aditional.Balance=info.aditional.Balance+amount;
                    cout<<"Successful deposited"<<endl;
                }
                else
                {
                    cout<<"you do not have sufficient balance in your credit card!!!"<<endl;
                }
            }
            break;
        case 6:
            logout=false;
            break;

        default:
            cout<<"Wrong option !!! try again..."<<endl;


        }

    }while(logout);

}
void Edit(AccountInfo& info)
{
    int switchnum;
    string tempstring;
    bool ok,ok1;
    long phone;
    do
    {
        ok1=false;
        cout<<"\n\nChoose from below : \n1.Edit Name \n2.Edit Phone number \n3.Edit Address \n4.Edit Password\nEnter Your Option : ";
        cin>>switchnum;
        switch(switchnum)
        {
        case 1:
            ok=Checkpass(info.aditional.pass);
            if(ok){
                cout<<"Enter new name : ";
                cin>>tempstring;
                info.aditional.name=tempstring;
            }
            break;
        case 2:
            ok=Checkpass(info.aditional.pass);
            if(ok){
                cout<<"Enter new Phone Number : ";
                phone=phonemun();
                info.aditional.number=phone;
            }
            break;
        case 3:
            ok=Checkpass(info.aditional.pass);
            if(ok){
                cout<<"Enter new Address : ";
                cin>>tempstring;
                info.aditional.address=tempstring;
            }
            break;
        case 4:
            ok=Checkpass(info.aditional.pass);
            if(ok){
                cout<<"Enter new password : ";
                cin>>tempstring;
                info.aditional.pass=tempstring;
            }
            break;
        default:
            cout<<"Wrong option!!! try again..."<<endl;
            ok1=true;
        }

    }while(ok1);

}
bool Checkpass(string pass)
{
    string passnew;
    bool ok;
    do
    {
        ok=false;
        cout<<"Enter your password : ";
        cin>>passnew;
        if(passnew==pass)
        {
            return true;
        }
        else
        {
            cout<<"Wrong password!!! try again..."<<endl;
            ok=true;
        }

    }while(ok);


}
long phonemun()
{
    bool ok;
    long num,last;
    int frist;
    do
    {
        ok=false;
        cin>>num;
        frist=(int)(num/100000000);
        last=num%100000000;

        if((frist>=13&&frist<=19)&&(last>=10000000&&last<=99999999))
        {
            return num;
        }
        else
        {
            ok=true;
            cout<<"Your number is not valid!!! Enter a valid one....";
        }

    }while(ok);
}
