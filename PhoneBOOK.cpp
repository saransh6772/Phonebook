#include<iostream>

using namespace std;
void start();
int menu();
string name[1000];
string no[1000];
int check=0;
int k=0;
int totalContacts=0;

void add(){
             cout<<"Name : ";
             cin>>name[k];
             cout<<"Phone No.";
             cin>>no[k];
             k++;
             totalContacts++;
}

void displayAll()
{
    for(int i=0;i<k;i++)
    {
        if(name[i]!="\0")
        {
            cout<<"Name :"<<name[i]<<"    Phone:"<<no[i]<<endl; 
        }
    }
}

void searchNumber(){
    string temp;
    cout<<"Number:";
    cin>>temp;
   
    for(int i=0; i<1000;i++){
        if(temp==no[i])
        {
            cout<<"Number is found\n";
            cout<<"Name :"<<name[i]<<" Phone : "<<no[i]<<endl;
        }
    }

}

void searchName(){
    
  string temp;
    cout<<"Name:";
    cin>>temp;
    int check2=0;
    for(int i=0; i<1000;i++){
        if(temp==name[i])
        {
            cout<<"Name is found\n";
           cout<<"Name :"<<name[i]<<" Phone : "<<no[i]<<endl;
           check2++;
        }
    }
    if(check2==0) cout<<"Not found in contacts\n";
}

void update(){
    string temp,temp2,temp3;
    cout<<"Name:";
    cin>>temp;
    int check2=0;
    for(int i=0; i<1000;i++){
        if(temp==name[i])
        {
            cout<<"New Name :";
            cin>>temp2;
            
            cout<<"New Number :";
            cin>>temp3;
            
            name[i]=temp2;
            no[i]=temp3;
           check2++;
           cout<<"Updated Sucessfully";
        }
    }
    if(check2==0) cout<<"Not found in contacts\n";

}

void deleteNo(){
     string temp;
    cout<<" Delete Name:";
    cin>>temp;
    int check2=0;
    for(int i=0; i<1000;i++){
        if(temp==name[i])
        {
            cout<<"Deleted Sucessfully\n";
            name[i]="\0";
            no[i]="\0";
            check2++;
            totalContacts--;
        }
        
    }
    if(check2==0) cout<<"Not found in contacts\n";

}

void deleteALL(){
         cout<<"Deleted Sucessfully\n";
            for(int i=0;i<k;i++){

            
            name[i]="\0";
            no[i]="\0";
            }
            k=0;
            totalContacts=0;
    
       
    

}


int main(){

   
    check=menu();
    do{
         if(check==1) add();
         else if(check==2) displayAll();
         else if(check==3) searchNumber();
         else if(check==4) searchName();
         else if(check==5) update();
         else if(check==6) deleteNo();
         else if(check==7) deleteALL();
         check=menu();

         
    }while(check!=8);
}

int menu(){
    cout<<"PHONE BOOK APPLICATION\n";
    cout<<"---------------------\n";
    cout<<" 1. Add Contacts\n";
    cout<<" 2. Display all Contacts\n";
    cout<<" 3. Search By Number \n";
    cout<<" 4. Search by Name\n";
    cout<<" 5. Update\n";
    cout<<" 6. Delete\n";
    cout<<" 7. Delete ALl\n";
    cout<<" 8. Exit\n";

    int a; // number you choose
    cin>>a;
    return a;

    }
