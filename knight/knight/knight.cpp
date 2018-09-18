#include <iostream>
#include "knight.h"
using namespace std;
knight::knight()
{
	mv[1].x=1;mv[1].y=-2;
	mv[2].x=2;mv[2].y=-1;
	mv[3].x=2;mv[3].y=1;
	mv[4].x=1;mv[4].y=2;
	mv[5].x=-1;mv[5].y=2;
	mv[6].x=-2;mv[6].y=1;
	mv[7].x=-2;mv[7].y=-1;
	mv[8].x=-1;mv[8].y=-2;
	a[0][0]='A';a[1][0]='B';a[2][0]='C';a[3][0]='D';a[4][0]='E';
	a[0][1]='F';a[1][1]='G';a[2][1]='H';a[3][1]='I';a[4][1]='J';
	a[0][2]='K';a[1][2]='L';a[2][2]='M';a[3][2]='N';a[4][2]='O';
	a[0][3]=0;a[1][3]='1';a[2][3]='2';a[3][3]='3';a[4][3]=0;
	fill_n(p,10,0);
	fill_n(r,10,0);
	state=true;
}
knight::~knight()
{
}
void knight::resetp()
{
	fill_n(p,10,0);
}
void knight::resetr()
{
	fill_n(r,10,0);
}
void knight::printa()
{
	char c;
	bool start_el;
	do{
		cout<<a[0][0]<<" "<<a[1][0]<<" "<<a[2][0]<<" "<<a[3][0]<<" "<<a[4][0]<<endl;
		cout<<a[0][1]<<" "<<a[1][1]<<" "<<a[2][1]<<" "<<a[3][1]<<" "<<a[4][1]<<endl;
		cout<<a[0][2]<<" "<<a[1][2]<<" "<<a[2][2]<<" "<<a[3][2]<<" "<<a[4][2]<<endl;
		cout<<a[0][3]<<" "<<a[1][3]<<" "<<a[2][3]<<" "<<a[3][3]<<" "<<a[4][3]<<endl;
		cout<<"Enter start element or Q to quit:";cin>>c;
		if(c=='Q'){state=false;return;}
		start_el=findel(c);
		if (start_el==false)cout<<"Wrong element!"<<endl;
	}while (!start_el);
	r[0]=a[x][y];
}
bool knight::getstate()
{
	return state;
}
bool knight::findel(char cc)
{
	y=0;
	while(y<4)
	{
		x=0;
		while(x<5)
		{
			if (a[x][y]==cc)break;
			x++;
		}
		if (a[x][y]==cc)break;
		y++;
	}
	if(y==4)return false;else return true;
}
bool knight::isvowel2()
{
	int l=0;
	for(int i=0;i<=9;i++)
	{
		if((r[i]=='A')||(r[i]=='E')||(r[i]=='I')||(r[i]=='O'))l++;
	}
	if(l==2)return true;else return false;

}
bool knight::ispresent(char c)
{
	for(int i=0;i<=9;i++)
	{
		if(r[i]==c)return true;
	}
	return false;
}
void knight::knightcalc(int n)
{
	int xx,yy;
	int i=p[n]+1;
	while(i<=8)
	{
		xx=x+mv[i].x;yy=y+mv[i].y;
		if((xx<0)||(yy<0)||(xx>4)||(yy>3)){i++;continue;}
		if(a[xx][yy]==0){i++;continue;}
		if(ispresent(a[xx][yy])){i++;continue;}
		if(((a[xx][yy]=='A')||(a[xx][yy]=='E')||(a[xx][yy]=='I')||(a[xx][yy]=='O'))&&(isvowel2())){i++;continue;}
		break;
	}
	if (i>8){p[n]=0;r[n]=0;}else {p[n]=i;r[n]=a[xx][yy];}
}
void knight::knightstart()
{
	int i=1;int res=0;
	do{
		while (i<=9)
		{
			findel(r[i-1]);
			knightcalc(i);
			if (p[i]==0)i--;else i++;
			if (i==0)break;
		}
		if(i==0)break;
		res++;
		cout<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<" "<<r[4]<<" "<<r[5]<<" "<<r[6]<<" "<<r[7]<<" "<<r[8]<<" "<<r[9]<<endl;
		if(i==10)i=9;
	}while(1);
	cout<<"Countity of results="<<res<<endl;
}
