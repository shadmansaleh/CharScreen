#include "CharScreen.h"
#include <iostream>
#include <unistd.h>
int main()
{
//  std::cout.sync_with_stdio(false);
  //CharScreen sc(40,20);
  CharScreen sc;
  for(int i=0; i <= sc.getHeight() ; ++i)
    for(int j=0 ; j <= sc.getWidth() ; ++j){
      if(j == 0 || j== sc.getWidth() || i == 0 || i == sc.getHeight())
        sc.update(j,i,'*');
    }
  for(int i=0;i <= sc.getHeight();++i)
    sc.update(0,i,'*');
  sc.shiftScreenLocX(10);
  char Test1[]{"Testing..."};
  sc.update(sc.getWidth()/3,sc.getHeight()/2,Test1);

  sc.refreash();
//  sleep(2);
  std::cout << "Works !!!" << std::endl;
}

