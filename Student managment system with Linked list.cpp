#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

class Node
{
public:
    int roll_no;
    string name ;
    float mark,percentage;
    Node *next;
};

class Linked_list
{
public:
    Node *head = NULL;
    void insert_n()
    {
        int r;
        string n;
        float m ;
        cout<<"\n\n\t\tEnter Roll Number :";
        cin>>r;
        cout<<"\t\tEnter Name:";
        cin>>n;
        cout<<"\t\tEnter Mark :";
        cin>>m ;
        Node *new_node=new Node;
        new_node->roll_no=r;
        new_node->name=n;
        new_node->mark=m;
        new_node->percentage=(m*100)/100;
        new_node->next=NULL;
        if(head==NULL)
        {
            head=new_node;

        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;

        }
    }
    void show()
    {
        if(head==NULL)
        {
            cout<<"No Data to Show"<<endl;
        }
        else
        {
            Node *ptr=head;
            cout<<"\n";
            while(ptr!=NULL)
            {
                cout<<"\tRoll Number :"<<ptr->roll_no<<endl;
                cout<<"\tName :"<<ptr->name<<endl;
                cout<<"\tMark :"<<ptr->mark<<endl;
                cout<<"\tPercentage :"<<ptr->percentage<<endl<<endl;
                ptr=ptr->next;
            }
        }
    }
    void search_data()
    {
        if(head==NULL)
        {
            cout<<"\n\t\tNo Data to Search";
        }
        else
        {
            int r,found=0;
            cout<<"\nEnter Roll number which you want to search :";
            cin>>r;
            Node * pt=head;
            while(pt!=NULL)
            {
                if(pt->roll_no==r)
                {
                    found++;
                    cout<<"\n\n\t\t\tData Found!!"<<endl;
                    cout<<"\tRoll Number :"<<pt->roll_no<<endl;
                    cout<<"\tName :"<<pt->name<<endl;
                    cout<<"\tMark :"<<pt->mark<<endl;
                    cout<<"\tPercentage :"<<pt->percentage<<endl<<endl;
                    break;
                }
                pt=pt->next;
            }
            if(found==0)
            {
                cout<<"\n\t\tRoll number Not Exist";
            }
        }
    }
    void count()
    {
        int co=0;
        Node * pt=head;
        while(pt!=NULL)
        {
            co++;
            pt=pt->next;
        }
        cout<<"\n\t\tNumber of Data :"<<co;
    }
    void update()
    {
        if(head==NULL)
        {
            cout<<"\n\t\tNo Data to update";
        }
        else
        {
            int r,found=0;
            cout<<"\nEnter Roll number which you want to Update :";
            cin>>r;
            Node * pt=head;

            while(pt!=NULL)
            {

                if(pt->roll_no==r)
                {
                    found++;
                    cout<<"\n\n\t\t\tOld Data!!\n"<<endl;
                    cout<<"\tRoll Number :"<<pt->roll_no<<endl;
                    cout<<"\tName :"<<pt->name<<endl;
                    cout<<"\tMark :"<<pt->mark<<endl;
                    cout<<"\tPercentage :"<<pt->percentage<<endl<<endl;

                    cout<<"\n\n\t\t\tEnter New Data"<<endl;
                    int r;
                    string n;
                    float m ;
                    cout<<"\n\tEnter Roll Number :";
                    cin>>r;
                    cout<<"\tEnter Name:";
                    cin>>n;
                    cout<<"\tEnter Mark :";
                    cin>>m ;
                    pt->roll_no=r;
                    pt->name=n;
                    pt->mark=m;
                    pt->percentage=(m*100)/100;
                    cout<<"\n\n\t\t\t\t\tData has been Updated Successfully"<<endl;

                }
                pt=pt->next;

            }
            if(found==0)
            {
                cout<<"\n\t\tRoll number Not Exist";

            }


        }
    }
    void delete_data()
    {
        if(head==NULL)
        {
            cout<<"\n\t\tNo Data to delete";
        }
        else
        {
            int r,found=0;
            cout<<"\nEnter Roll number which you want to Delete :";
            cin>>r;
            Node * pt=head;
            if(pt->roll_no==r)
            {

                Node *temp=pt;
                head=pt->next;
                delete temp;
                cout<<"\n\n\t\t\t\t\tData has been Deleted Successfully"<<endl;
            }

            else
            {


                while(pt!=NULL && pt->next!=NULL)
                {
                    if(pt->next->roll_no==r)
                    {
                        found++;
                        Node *temp=pt->next;
                        pt->next=pt->next->next;
                        delete temp;
                        cout<<"\n\n\t\t\t\t\tData has been Deleted Successfully"<<endl;
                        break;

                    }
                    pt=pt->next;

                }
                if(found==0)
                {
                    cout<<"\n\t\tRoll number Not Exist";

                }

            }
        }
    }

};
int main()
{
    cout<<"\n\n\t\tStudent Management System"<<endl;
    cout<<"\n\t\tSign Up"<<endl;

    string username,password;
    cout<<"\n\t\t\tEnter Username :";
    cin>>username;
    cout<<"\t\t\tEnter password :";
    cin>>password;
    cout<<"\n\n\t\tYour Id is creating please wait";
    for(int i=0; i<5; i++)
    {
        cout<<".";
        Sleep(500);
    }
    system("cls");
    cout<<"\n\n\t\tYour Id is created sucessfully";
    Sleep(1000);
    system("cls");
start:
    system("cls");
    cout<<"\n\n\t\tEmployee Management System"<<endl;
    cout<<"\n\t\tlogin"<<endl;

    string username_check,password_check;
    cout<<"\n\t\t\tEnter Username :";
    cin>>username_check;
    cout<<"\t\t\tEnter password :";
    cin>>password_check;
    if(username!=username_check)
    {
        cout<<"Your username is incorrect"<<endl;
        Sleep(1000);
        system("cls");
        goto start;
    }
    else if(password!=password_check)
    {
        cout<<"Your password is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
    else
    {
        system("cls");
        Linked_list rec;
pin:
        int num;
        cout<<"\n\n";
        cout<<"\t\t\tStudent Management System";
        cout<<"\n\n\t\t1. Insert Record";
        cout<<"\n\n\t\t2. Search Record";
        cout<<"\n\n\t\t3. Count Record";
        cout<<"\n\n\t\t4. Update Record";
        cout<<"\n\n\t\t5. Delete Record";
        cout<<"\n\n\t\t6. Show All Record";
        cout<<"\n\n\t\t7. Logout";
        cout<<"\n\n\t\t8. Exit";
        cout<<"\n\n\t\tYour choice :";
        cin>>num;
        switch(num)
        {
        case 1:
            system("cls");
            rec.insert_n();
            break;
        case 2:
            system("cls");
            rec.search_data();
            getch();
            break;
        case 3:
            system("cls");
            rec.count();
            getch();
            break;
        case 4:
            system("cls");
            rec.update();
            getch();
            break;
        case 5:
            system("cls");
            rec.delete_data();
            getch();
            break;
        case 6:
            system("cls");
            rec.show();
            getch();
            break;
        case 7:
            system("cls");
            goto start;
            getch();
            break;
        case 8:
            system("cls");
            exit(0);
            break;

        default:
            system("cls");
            cout<<"\n\n\n\t\t\t\t!!! You Have Entered Invalid Choice Please Retry!!! ";
            getch();
            system("cls");
            goto pin;

        }
        system("cls");
        goto pin;
    }
    return 0;
}
