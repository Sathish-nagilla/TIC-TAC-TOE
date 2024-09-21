#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string n1,n2;
char tkn='X';
bool tie=false;
int r;
int c;
void defx(){
	char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
}
void s1(){
	
	cout<<"     |     |     \n";
	cout<<"  "<<space[0][0]<<"  |  "<<space[0][1]<<"  |  "<<space[0][2]<<"  \n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<space[1][0]<<"  |  "<<space[1][1]<<"  |  "<<space[1][2]<<"  \n";
	cout<<"_____|_____|_____\n";
	cout<<"     |     |     \n";
	cout<<"  "<<space[2][0]<<"  |  "<<space[2][1]<<"  |  "<<space[2][2]<<"  \n";
	cout<<"     |     |     \n";
	
}

void s2(){
	
	int digit;
	if(tkn=='X'){
		cout<<n1<<" please enter ";
		cin>>digit;
	}
	else if(tkn=='O'){
		cout<<n2<<" please enter ";
		cin>>digit;
	}
	
	
	
	switch(digit){
		case 1:
			r=0;
			c=0;
			break;
		case 2:
			r=0;
			c=1;
			break;
		case 3:
			r=0;
			c=2;
			break;
		case 4:
			r=1;
			c=0;
			break;
		case 5:
			r=1;
			c=1;
			break;
		case 6:
			r=1;
			c=2;
			break;
		case 7:
			r=2;
			c=0;
			break;
		case 8:
			r=2;
			c=1;
			break;
		case 9:
			r=2;
			c=2;
			break;
		default:
			cout<<"invalid digit"<<endl;
			
			
	
	}
	if(tkn=='X'&& space[r][c]!='X'&& space[r][c]!='O')
	{
		space[r][c]='X';
		tkn='O';
	}
	else if(tkn=='O'&& space[r][c]!='X'&& space[r][c]!='O')
	{
		space[r][c]='O';
		tkn='X';
	
	}
	else{
		cout<<"There is no empty space"<<endl;
		s2();	
	}
	
}
bool s3(){
	for(int i=0;i<3;i++){
		if((space[i][0]==space[i][1] && space[i][0]==space[i][2]  )||(space[0][i]==space[1][i] && space[0][i]==space[2][i])){
			return true;
		}
	}
	
	if((space[0][0]==space[1][1] && space[0][0]==space[2][2]  )||(space[0][2]==space[1][1] && space[0][2]==space[2][0])){
		return true;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(space[i][j]!='X'&&space[i][j]!='O'){
				return false;
			}
		}
	}
	tie=true;
	return true;
	
}
void s4()
{
	space[0][0]='1';
	space[0][1]='2';
	space[0][2]='3';
	space[1][0]='4';
	space[1][1]='5';
	space[1][2]='6';
	space[2][0]='7';
	space[2][1]='8';
	space[2][2]='9';	
}

int main()
{
	//cout<<"to start game press p";
	char pl='p';
	cout<<"enter player1 name-";
	getline(cin,n1);
	cout<<"enter player2 name-";
	getline(cin,n2);
	
	cout<<"player1: "<<n1<<endl; 
	cout<<"player2: "<<n2<<endl;
	while(pl='p'){
	cout<<"to start game press \"p\"\n";
	cout<<"to end game press \"e\"\n"<<"enter:";
	cin>>pl;
	while(!s3()){
		s1();
		s2();
		s3();
	}
	if(tkn=='X' && tie==false){
		cout<<n2<<" wins!!"<<endl;
	}
	else if(tkn=='O' && tie==false){
		cout<<n1<<" wins!!"<<endl;
	}
	else{
		cout<<"Its a draw"<<endl;
	}
	s4();
	}
	return 0;
	}
	
// create continous playing game

