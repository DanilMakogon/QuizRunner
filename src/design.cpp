#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncursesw/ncurses.h>
#include <locale.h>

void init() {
	setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_CYAN);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
	refresh();
}

void intro() {
	move(1, 3);
	addstr(" _______  _______  _______  _______    _______          _________ _______ ");
	move(2, 3);
	addstr("(  ____ )(  ____ )(  ___  )(  ____ \\  (  ___  )|\\     /|\\__   __// ___   )");
	move(3, 3);
	addstr("| (    )|| (    )|| (   ) || (    \\/  | (   ) || )   ( |   ) (   \\/   )  |");
	move(4, 3);
	addstr("| (____)|| (____)|| |   | || |        | |   | || |   | |   | |       /   )");
	move(5, 3);
	addstr("|  _____)|     __)| |   | || | ____   | |   | || |   | |   | |      /   / ");
	move(6, 3);
	addstr("| (      | (\\ (   | |   | || | \\_  )  | | /\\| || |   | |   | |     /   /  ");
	move(7, 3);
	addstr("| )      | ) \\ \\__| (___) || (___) |  | (_\\ \\ || (___) |___) (___ /   (_/\\");
	move(8, 3);
	addstr("|/       |/   \\__/(_______)(_______)  (____\\/_)(_______)\\_______/(_______/");
	move(11, 20);
	addstr("Авторы:");
	move(13, 20);
	addstr("Макогон Данил");
	move(14, 20);
	addstr("Певнев Александр");
	move(15, 20);
	addstr("Федосов Кирилл");
	move(18, 20 );
	addstr("Для продолжения нажми любую клавишу");
	getch();
}

void mainMenu();

void returnToNormalMode() {
	echo();
	endwin();
}