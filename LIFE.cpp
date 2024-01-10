#include <bits/stdc++.h>
using namespace std;
char world[22][82];
char _world[22][82];
const int top=1;
const int bottom=20;
const int left=1;
const int right=80;
int g=0;
int around(int i,int j){
	int cnt=0;
	if(i>=top && j>=left) cnt+=_world[i-1][j-1]=='*';
	if(i>=top) cnt+=_world[i-1][j]=='*';
	if(i>=top && j<=right) cnt+=_world[i-1][j+1]=='*';
	if(j>=left) cnt+=_world[i][j-1]=='*';
	if(j<=right) cnt+=_world[i][j+1]=='*';
	if(i<=bottom && j>=left) cnt+=_world[i+1][j-1]=='*';
	if(i<=bottom) cnt+=_world[i+1][j]=='*';
	if(i<=bottom && j<=right) cnt+=_world[i+1][j+1]=='*';
	return cnt;
}
void full(int i,int j){
	int n=around(i,j);
	if (n<=1 || n>3) world[i][j]=' ';
}
void empty(int i,int j){
	int n=around(i,j);
	if (n=3) world[i][j]='*';
}
void generation(){
	for(int i=0;i<20;i++){
		strcpy(_world[i],world[i]);
	}
	for(int i=0;i<20;i++){
		for(int j=0;i<80;j++){
			if(_world[i][i]==' '){
				empty(i,j);
			}
			else if(_world[i][i]=='*'){
				full(i,j);
			}
		}
	}
	for(int i=0;i<20;i++){
		strcpy(world[i],_world[i]);
	}
	g++;
}
void display(){
	for(int i=1;i<=20;i++){
		for(int j=0;j<=80;j++){
			cout<<world[i][j];
		}
		cout<<endl;	
	}
	cout<<"generation: "<<g<<endl;
}
void init(){
	istream mapIn;
	mapIn.open()
}
int main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	cout<<"********************************************************************************"<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"       *****          *************  ************* *************                "<<endl;
	cout<<"       *   *          *           *  *           * *           *                "<<endl;
	cout<<"       *   *          ****     ****  *    ******** *    ********                "<<endl;
	cout<<"       *   *             *     *     *    *        *    *                       "<<endl;
	cout<<"       *   *             *     *     *    ******** *    ********                "<<endl;
	cout<<"       *   *             *     *     *           * *           *                "<<endl;
	cout<<"       *   *             *     *     *    ******** *    ********                "<<endl;
	cout<<"       *   *             *     *     *    *        *    *                       "<<endl;
	cout<<"       *   *********  ****     ****  *    *        *    ********                "<<endl;
	cout<<"       *           *  *           *  *    *        *           *                "<<endl;
	cout<<"		  *************  *************  ******        *************                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"********************************************************************************"<<endl;
	system("Pause");
	system("cls");
	while(1){
		generation();
		display();
		
	}
	
	return 0;
}

