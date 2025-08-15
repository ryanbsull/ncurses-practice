#include <ncurses.h>

int main() {
	initscr();			/* Start curses mode 		  */
	raw();				/* Line buffering disabled	  */
	printw("Enter some character\n");
	int ch = getch();		/* Get user input character (if
					 * raw() hadn't been called we
					 * would have needed to press
					 * enter			  */

	printw("\nThe pressed key is ");
	attron(A_BOLD);
	printw("%c", ch);
	attroff(A_BOLD);
	refresh();

	getch();
	endwin();			/* End curses mode		  */
	return 0;
}
