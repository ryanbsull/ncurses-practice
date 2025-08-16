#include <ncurses.h>
#include <string.h>

int main() {
	char* msg = "Example msg";
	int row, col;
	initscr();			/* Start curses mode 		  */
	getmaxyx(stdscr, row, col);	/* Get the screen dimensions	  */

	mvprintw(row / 2,
	  (col - strlen(msg)) / 2,
	  "%s", msg);			/* Print msg in the center of the
					* window			  */

	mvprintw(row - 2,
	  col - 20,
	  "ROWS: %d COL: %d",
	  row, col);
	refresh();
	getch();
	endwin();			/* End curses mode		  */
	return 0;
}
