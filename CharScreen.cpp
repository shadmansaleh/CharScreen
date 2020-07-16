#include "CharScreen.h"
#include <cstdlib>

void CharScreen::init(int W,int H)
{
  if( H > 0 && W > 0 )
  {
    height = H;
    width = W;
    scr = (char*)std::malloc(H * W * sizeof(char));
    if(scr){
     std::memset(scr,' ',height*width);
     oldScr = (char*)std::malloc(H * W * sizeof(char));
     if (oldScr){
      std::memset(oldScr,0,height*width);
      clearTerminal();
      refreash();
     }else setDefault();
    }else setDefault();
  }else setDefault();
}

char CharScreen::getVal(char *sc,int x,int y)
{
  if( sc && x <= width && y <= height && x >= 0 && y >= 0 )
  {
    return *( sc + ( width * y + x ));
  }
  else
    return 0;
}  

inline int CharScreen::setVal(char *sc,int x,int y,char ch)
{
  if( sc && x <= width && y <= height && x >= 0 && y >= 0 )
  {
    *( sc + ( width * y + x )) = ch;
    return 1;
  }
  else
    return -1;
}

void CharScreen::setDefault()
{
  if(scr)
    free(scr);
  if(oldScr)
    free(oldScr);
  scr=NULL;
  oldScr=NULL;
  height=0;
  width=0;
}


void CharScreen::draw(int x,int y)
{
  if( x <= width && y <= height && x >= 0 && y >= 0 )
  {
    std::cout << "\x1b[" << y+ofsetY << ";" << x+ofsetX << "H" << getVal(scr,x,y) << std::flush;
  }
}

void CharScreen::clearBottom()
{
  if( height > 0 && width > 0 )
  {
    std::cout << "\x1b[" << height+1 << "B" << "\x1b[J"
      << "\x1b[" << height+1 << ";0H"<<std::flush ;
  }
}

CharScreen::CharScreen(int W,int H)
{
  init(W,H);
}

CharScreen::CharScreen()
{
  setDefault();
}

CharScreen::~CharScreen()
{
  setDefault();
}

void CharScreen::getNewScreen(int W,int H)
{
  setDefault();
  init(W,H);
}

int CharScreen::clear()
{
  return coverScreen(' ');
}

int CharScreen::coverScreen(char ch)
{
  if(scr){
    memset(scr,ch, height * width );
    refreash();
    return 1;
  }
  else
    return -1;
}


void CharScreen::clearTerminal()
{
  std::cout << "\x1b[H\x1b[J" << std::flush;
}

int CharScreen::update( int x , int y , char ch)
{
 return setVal(scr,x,y,ch);
}

int CharScreen::update(int x,int y,char *ch)
{
  int len = std::strlen(ch);
  if(width >= (x + len))
  {
    for(int i=0; i <= len ; ++i,ch++)
      setVal(scr, x+i , y,*ch);
    return 1;
  }else return -1;
}

int CharScreen::updateLine(int y,char *ch)
{
  return update(0,y,ch);
}

void CharScreen::refreash()
{
  for (int i = 0 ; i <= height ; ++i )
    for( int j = 0 ; j <= width ; ++j )
    {
      if( getVal(scr,j,i) != getVal(oldScr,j,i))
      {
        draw(j,i);
        setVal(oldScr,j,i,getVal(scr,j,i));
      }
    }
  clearBottom();
}
