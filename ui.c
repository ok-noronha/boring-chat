#include "ui.h"

#include <stdlib.h>
#include <ncurses/ncurses.h>

WINDOW *main_win, *msg_win_box, *msg_win, *ip_win_box, *ip_win;

void init_ui()
{
	init_root_ui();
	if (LINES < 24 || COLS < 76) {
		warn_small_size();
	} else {
		init_msg_win();
		init_ip_win();
	}
}

void init_root_ui()
{
	main_win = initscr();
	noecho();
	cbreak();
	keypad(main_win, TRUE);
}

void init_msg_win()
{
	msg_win_box = subwin(main_win, LINES * 0.8, COLS, 0, 0);
	box(msg_win_box, 0, 0);
	mvwaddch(msg_win_box, 0, COLS * 0.5 - 6, ACS_RTEE);
	mvwaddstr(msg_win_box, 0, COLS * 0.5 - 5, "Boring Chat");
	mvwaddch(msg_win_box, 0, COLS * 0.5 + 4, ACS_LTEE);
	wrefresh(msg_win_box);
	
	msg_win = subwin(main_win, LINES * 0.8 - 2, COLS - 2, 1, 1);
	scrollok(msg_win, TRUE);
}

void init_ip_win()
{
	ip_win_box = subwin(main_win, LINES * 0.2, COLS, LINES * 0.8 + 1, 0);
	box(ip_win_box, 0, 0);
	ip_win = subwin(ip_win_box, LINES * 0.2 - 3, COLS - 2, LINES * 0.8 + 2, 1);
}
