#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


bool readSettings(string& city, string& color) {
    ifstream fin("City.txt");
    if (fin.is_open()) {
        fin >> city >> color;
        fin.close();
        if (color == "red") system("color 4F");
        else if (color == "blue") system("color 1F");
        else if (color == "green") system("color 2F");
        else if (color == "yellow") system("color 6F");
        else if (color == "white") system("color 7F");
        else system("color 0F");
        return true;
    }
    return false;
}

void saveSettings(const string& city, const string& color) {
    ofstream fout("City.txt");
    fout << city << " " << color;
    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    string city;
    string color;
    char choice;

    bool settingsExist = readSettings(city, color);

    if (settingsExist) {
        readSettings(city, color);
        cout << "Текущий город: " << city << endl;
        cout << "Текущий цвет: " << color << endl;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый любимый город: ";
            cin >> city;
            cout << "Введите новый любимый цвет (red, blue, green, yellow, white): ";
            cin >> color;

            readSettings(city, color);
            cout << "Настройки обновлены!" << endl;
        }
    }
    else {
        cout << "Введите любимый город: ";
        cin >> city;
        cout << "Введите любимый цвет (red, blue, green, yellow, white): ";
        cin >> color;

        readSettings(city, color);
        cout << "Настройки сохранены!" << endl;
    }

    cout << "\nПрограмма завершена." << endl;
    return 0;
}
