#include "../headers/design.h"
#include "../headers/functions.h"
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
	init_pair(2, COLOR_WHITE, COLOR_CYAN);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
	refresh();
}

void intro() {
	clear();
	attron(COLOR_PAIR(2));
	border(0, 0, 0, 0, 0, 0, 0, 0);
	attron(COLOR_PAIR(1));
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
	attron(COLOR_PAIR(2));
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
	refresh();
	getch();
}

void mainMenu() {
	clear();
	attron(COLOR_PAIR(2));
	border(0, 0, 0, 0, 0, 0, 0, 0);
	attron(COLOR_PAIR(1));
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
	attron(COLOR_PAIR(2));
	move(11, 10);
	addstr("Правила:");
	move(13, 10);
	addstr("Вам предложено пройти тест на знание программирования");
	move(14, 10);
	addstr("В конца теста на экране высветится ваш уровень навыков");
	move(15, 10);
	addstr("программирования, составленный на основе ваших ответов.");
	move(17, 10);
	addstr("Управление:");
	move(19, 10);
	addstr("Нажимай '1', '2', '3', '4' или 'A', 'B', 'C', 'D'");
	move(20, 10);
	addstr("для выбора варианта ответа");
	move(21, 10);
	addstr("Нажми ESCAPE в любой момент для выхода");
	refresh();
	getch();
}

void showQuestion(short questionNumber) {
	clear();
	attron(COLOR_PAIR(2));
	move(5, 1);
	for (unsigned short i = 0; i < dataBase[questionNumber].ques.size(); ++i) {
		char c = dataBase[questionNumber].ques[i];
		if (c == '$')
			printw("\n ");
		else
		printw("%c", c);
	}
	move(10, 1);
	addstr("1) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans1.size(); ++i) {
		char c = dataBase[questionNumber].ans1[i];
		if (c == '$')
			printw("\n    ");
		else
		printw("%c", c);
	}
	move(13, 1);
	addstr("2) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans2.size(); ++i) {
		char c = dataBase[questionNumber].ans2[i];
		if (c == '$')
			printw("\n    ");
		else
		printw("%c", c);
	}
	move(16, 1);
	addstr("3) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans3.size(); ++i) {
		char c = dataBase[questionNumber].ans3[i];
		if (c == '$')
			printw("\n    ");
		else
		printw("%c", c);
	}
	move(19, 1);
	addstr("4) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans4.size(); ++i) {
		char c = dataBase[questionNumber].ans4[i];
		if (c == '$')
			printw("\n    ");
		else
		printw("%c", c);
	}
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}

void returnToNormalMode() {
	echo();
	endwin();
}

void showResult(short result) {
	clear();
	move(1, 1);
	if (result <= 7) {
		addstr("Junior");
	} else
	if (result <= 14) {
		addstr("Middle");
	} else
	if (result <= 18) {
		addstr("Senior");
	} else
	if (result <= 20) {
		addstr("Team Lead");
	}
	getch();
}