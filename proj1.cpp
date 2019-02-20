#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct PERSON{
  char Name[20];
  float Balance;
};

void Display(PERSON a[],int N);
void FindRichest(PERSON a[],int N);
void Deposit(char CustName[], PERSON a[], int N);
void NewCopy(PERSON a[], int N);

int main()
{
PERSON P[6];
char CustName[20];
string fname;
string lname;
string sName;
int i=0,n;
ifstream inData ("data.txt");
ofstream outData ("data.txt");
if(inData.is_open())
{
while (inData)
{
inData >> fname;
inData >> lname;
inData>>P[i].Balance;
sName = fname+" "+lname;
strcpy(P[i].Name, sName.c_str());
i++;
}
inData.close();
}else {cout<<"Error reading...";}
Display(P, 5);
FindRichest(P, 4);
Deposit(CustName, P, 5);
NewCopy(P, 5);

return 0;
}

void Display(PERSON a[], int N)
{
  int i=0;
  cout<<"Name"<<"\t\t"<<"Balance"<<endl;
  cout<<"-----------------------"<<endl;
  while(i<=N)
  {
  cout<<a[i].Name<<" "<<a[i].Balance<<endl;
  i++;
  }
}

void FindRichest(PERSON a[],int N)
{
  int i=0;
  string rName;
  while(i<=N)
  {
    if(a[i].Balance > a[i+1].Balance)
    {
      rName = a[i].Name;
    }else
    {
      rName = a[i+1].Name;
    }
    i++;
  }
  cout<<"The richest person is " + rName<<endl;
}

void Deposit(char CustName[], PERSON a[], int N)
{
  int i = 0, j=0;
  float nBalance;
  string name1, name2, sName2;
  char cName[20];
  cout<<"Enter name"<<endl;
  cin>>name1>>name2;
  sName2 = name1+" "+name2;
  strcpy(cName, sName2.c_str());
  while (i<=N)
  {
    if(strcmp(a[i].Name,cName)==0)
    {
      j=i;
    }
    i++;
  }
    cout<<"Name: "<<a[j].Name<<endl;
    cout<<a[j].Name<<", how much would you lile to deposit?"<<endl;
    cin>>nBalance;
    cout<<endl;
    a[j].Balance+=nBalance;
    cout<<"Now your new balance is "<<a[j].Balance<<endl;

  }

  void NewCopy(PERSON a[],int N)
  {
    ofstream outData;
    outData.open("data.txt");

    for(int i=0;i<=N;i++)
    {
    outData<<a[i].Name<<" "<<a[i].Balance<<endl;
    }
    outData.close();

  }
