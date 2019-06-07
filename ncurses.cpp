#include <deque>
#include <string>
#include <ncurses.h>

WINDOW* win;
uint cursorRow, cursorCol,screenRows,screenCols;
bool refreshed;
std::deque<std::string> text;

void initilizeNcurses(){
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	nodelay(stdscr,TRUE);
	getmaxyx(stdscr,screenRows,screenCols);
	win=newwin(screenRows,screenCols,0,0);
}

bool refreshScreen(){
	if(!refreshed){
		wrefresh(win);
		return refreshed=true;
	}
	return false;
}

void drawToScreen(std::deque<std::string> lines,uint rs,uint cs){
	for(uint r=0;r<rs&&r<lines.size();r++){
		for(uint c=0;c<cs&&c<lines[r].size();c++){
			wmove(win,r,c);
			waddch(win,lines[r][c]);
		}
	}
}

void updateScreen(std::deque<std::string> lines){
	drawToScreen(lines,screenRows,screenCols);
	wmove(win,0,0);
	refreshed=false;
	refreshScreen();
}

void distructScreen(){
	endwin();
}

//stuffs
bool handelKey(){
	char ch[2];
	ch[1]='\0';
	if((ch[0]=getch())!=ERR){
		text.push_front(ch);
		return true;
	}
	return false;
}

int main(){
	initilizeNcurses();
	text.push_front(" ");
	do{
		if(handelKey()){
			updateScreen(text);
		}
	}while(text[0][0]!='q');
	return 0;
}

