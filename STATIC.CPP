#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>

void print(char *ch)
{
 clrscr();
 cout<<"    TIC-TAC-TOE   "<<endl;
 cout<<" _____ _____ _____"<<endl;
 for(int i=0;i<7;i+=3)
 {
  cout<<"|     |     |     |"<<endl;
  cout<<"|  "<<ch[i]<<"  |  "<<ch[i+1]<<"  |  "<<ch[i+2]<<"  |"<<endl;
  cout<<"|_____|_____|_____|"<<endl;
 }
}

int check(char *ch, int count)
{
 for(int j=0;j<7;j+=3)
 {
  if(ch[j]==ch[j+1]&&ch[j]==ch[j+2])
  {
   print(ch);
   cout<<endl<<"Player \'"<<ch[j]<<"\' Wins";
   return 1;
  }
 }

 for(j=0;j<=2;j++)
 {
  if(ch[j]==ch[j+3]&&ch[j]==ch[j+6])
  {
   print(ch);
   cout<<endl<<"Player \'"<<ch[j]<<"\' Wins";
   return 1;
  }
 }

 if((ch[0]==ch[4]&&ch[4]==ch[8])||(ch[2]==ch[4]&&ch[4]==ch[6]))
 {
  print(ch);
  cout<<endl<<"Player \'"<<ch[4]<<"\' Wins";
  return 1;
 }

 else if(count==9)
 {
  print(ch);
  cout<<endl<<"Match Draw";
  return 1;
 }

 else
 return 0;
}

void main()
{
 int i,player,count=0;
 char in,c,ch[9]={'1','2','3','4','5','6','7','8','9'};
 zero:
 clrscr();
 cout<<"Enter the Choice of First Player (X/O): ";
 cin>>c;
 if(c=='0'||c=='o'||c=='O')
 player=1;
 else if(c=='x'||c=='X')
 player=2;
 else
 {
  cout<<"Invalid Choice";
  delay(1000);
  goto zero;
 }
 first:
 print(ch);
 cout<<"\nEnter your choice: ";
 cin>>in;
 if(ch[in-49]=='X'|| ch[in-49]=='O'||(in!='1' && in!='2' && in!='3' && in!='4' && in!='5' && in!='6' && in!='7' && in!='8' && in!='9'))
 {
  cout<<"Invalid Choice";
  delay(1000);
  if(count<9)
  goto first;
 }

 if(player%2==0)
 ch[in-49]='X';

 else
 ch[in-49]='O';

 player++;
 count++;
 if(check(ch,count)==1)
 goto second;
 goto first;
 second:
 getch();
}