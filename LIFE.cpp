#include <bits/stdc++.h>
using namespace std;
char world[22][82];
char World[22][82];
const int t=1;
const int b=20;
const int l=1;
const int r=80;
int g=0;
int around(int i,int j){
	int cnt=0;
	if(i>=t && j>=l) cnt+=world[i-1][j-1]=='*';
	if(i>=t) cnt+=world[i-1][j]=='*';
	if(i>=t && j<=r) cnt+=world[i-1][j+1]=='*';
	if(j>=l) cnt+=world[i][j-1]=='*';
	if(j<=r) cnt+=world[i][j+1]=='*';
	if(i<=b && j>=l) cnt+=world[i+1][j-1]=='*';
	if(i<=b) cnt+=world[i+1][j]=='*';
	if(i<=b && j<=r) cnt+=world[i+1][j+1]=='*';
	return cnt;
}
void full(int i,int j){
	int n=around(i,j);
	if (n<=1 || n>3) world[i][j]=' ';
}
void empty(int i,int j){
	int n=around(i,j);
	if (n==3) world[i][j]='*';
}
void generation(){
	for(int i=1;i<=20;i++){
		for(int j=1;j<=80;j++) {
            World[i][j]=world[i][j];
        }
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=80;j++){
			if(World[i][i]==' '){
				empty(i,j);
			}
			else if(World[i][i]=='*'){
				full(i,j);
			}
		}
	}
	g++;
}
void display(){
    
	for(int i=1;i<=20;i++){
		for(int j=0;j<=81;j++){
			cout<<world[i][j];
		}
		cout<<endl;	
	}
	cout<<"generation: "<<g<<endl;
}
void init(){

    for(int i=1;i<=20;i++){
        for(int j=1;j<=80;j++){
            srand(time(0));
            bool temp=rand()%2;
            if(temp) world[i][j]='*';
        }
    }
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
	cout<<"       *************  *************  ******        *************                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"                                                                                "<<endl;
	cout<<"********************************************************************************"<<endl;
	system("Pause");
	system("cls");
    init();
	while(1){
        system("cls");
		generation();
		display();
        system("Pause");
	}
	return 0;
}

