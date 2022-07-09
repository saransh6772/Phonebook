
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct node{
    string name , number;
    node *next;
};

node *head=NULL, *newnode , *temp;
int totalcontacts=0 , check=0;

void add()
{
    newnode = new node ;
    cout<<"Enter Name :";
    cin>>newnode->name;
    cout<<"Enter Number: ";
    cin>>newnode->number;
    newnode->next=NULL;

    if(head==NULL)
    {
        head = newnode;
        temp = newnode;

    }


    else {
        temp->next=newnode;
        temp=newnode;
    }
}

void displayAll()
{
    if (head==NULL)
    {
        cout<<"NO Contacts \n";    
    }

    else
    {
        node *temp2=head;
        while(temp2!=NULL)
        {
            cout<<"Name : "<<temp2->name<<"   Number : "<<temp2->number<<endl;
            
            temp2=temp2->next;
            totalcontacts++;
        }
    }
}

void search()
{    
    node *search_node=head;
    string srch;
    cout<<"Enter contact you want to search :";
    cin>>srch;
    bool found = false;

    if (head == NULL)
    cout<<"\nList is Empty\n";

    else
    {
        while (search_node !=NULL)
        {
            if(srch==search_node->name || srch == search_node->number)
            {     cout<<"Name :"<< search_node->name<<endl;
                  cout<<"Number :"<<search_node->number<<endl;
                 found = true;
            }

            search_node=search_node->next;

        }

        if (found != true)
        {
            cout<<"Contact Not found\n";
        }

     
    }

}

void update()
{    
    node *search_node=head;
    string srch,naam,no;
    cout<<"Enter contact you want to update :";
    cin>>srch;
    bool found = false;

    if (head == NULL)
    cout<<"\nList is Empty\n";

    else
    {
        while (search_node !=NULL)
        {
            if(srch==search_node->name || srch == search_node->number)
            {     cout<<"Name :"<< search_node->name<<endl;
                  cout<<"Number :"<<search_node->number<<endl;
                  cout<<"New Name :";
                  cin>>naam;
                  cout<<"New Number :";
                  cin>>no;
                  search_node->name = naam;
                  search_node->number =no;
                 found = true;
            }

            search_node=search_node->next;

        }

        if (found != true)
        {
            cout<<"Contact Not found\n";
        }

     
    }

}

void deletecontact()
{
     string del;
     node *search_node=head;
     node *next_node , *prev_node;
     int count =1;
     bool found = false;
     cout<<"Enter the contact you want to delete :";
     cin>>del;
     int c=0;
     if(head==NULL)
     {
         cout<<"List is Empty"<<endl;
     }
  
     else
     {    
           while(search_node!=NULL)
           {
               if(del== search_node->name || del == search_node->number)
               {
                    found = true;
                    c=count;
                    next_node=search_node; // next_node point karega jo humhe delete karna 
                    break;
               }
               search_node=search_node->next;
               count++;
           }

           if(c==1) head=head->next;
           else if(count>totalcontacts) cout<<"Not found in contacts\n";
           else
           {
                prev_node=head;//prev_node jo delete karna usse ek pehle waale ko point karega
               for (int i=1 ; i<c-1 ;i++)
              {
                  prev_node = prev_node->next;
              }

                prev_node->next = next_node->next;
                delete next_node;
           }

     }

}

void deleteALL()
{
    if (head==NULL)
     cout<<"List is Empty\n";

     else
     {
         temp =head;
         while(head!=NULL)
         {
             head=head->next;
              temp =head;
             delete temp;
         }

         cout<<"ALL contacts Deleted\n";
     }
}

int menu ()
{   cout<<"PHONE BOOK APPLICATION\n";
    cout<<"---------------------\n";
    cout<<"1. Add Contacts\n";
    cout<<"2. Display all Contacts\n";
    cout<<"3. Search \n";
    cout<<"4. Update\n";
    cout<<"5. Delete Contact\n";
    cout<<"6. Delete All\n";
    cout<<"7. Exit\n";

      int a; // number you choose
    cin>>a;
  
    return a;

}

int main()
{
check=menu();
    do{
         if(check==1)      add();
         else if(check==2) displayAll();
         else if(check==3) search();
         else if(check==4) update();
         else if(check==5) deletecontact();
         else if(check==6) deleteALL();
         
         check=menu();

         
    }while(check!=7);
}
