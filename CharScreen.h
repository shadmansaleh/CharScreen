//Header Guard
#ifndef CHAR_SCREEN_H_DEFINED
#define CHAR_SCREEN_H_DEFINED

//required headers
#include <cstdlib>
#include <iostream>
#include <cstring>

class CharScreen{
  private:
    char *scr=NULL;
    char *oldScr=NULL;
    int height{0};
    int width{0};
    int ofsetX{0};
    int ofsetY{0};
    void draw(int x,int y);
    void init(int W,int H);
    void setDefault();
    char getVal(char *sc,int x,int y);
    inline int setVal(char *sc,int x,int y,char ch);
    void clearBottom();
  public:
    int getHeight() { return height; }
    int getWidth() { return width; }
    int clear();
    int update( int x,int y,char ch );
    int update( int x,int y,char *ch);
    int updateLine(int y,char *ch);
    void refreash();
    void getNewScreen(int W,int H);
    int coverScreen(char ch);
    void clearTerminal();
    CharScreen(int W,int H);
    void shiftScreenLocX(int x=1) { ofsetX += x; }
    void shiftScreenLocY(int y=1) { ofsetY += y; }
    CharScreen();
    ~CharScreen();
};

#endif /* ifndef CHAR_SCREEN_H_DEFINED */

