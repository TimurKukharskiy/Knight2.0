#include "knight.h"
int main()
{
	knight kn;
	do{
		kn.resetp();
		kn.resetr();
		kn.printa();
		if(kn.getstate()==false)break;
		kn.knightstart();
	}while(true);
	return 0;
}