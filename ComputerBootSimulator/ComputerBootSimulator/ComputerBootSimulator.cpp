//GitHub этого проекта:https://github.com/KDGOfficial/ComputerBootSimulator
#include <iostream> // для вывода в консоль
#include <string> // для работы со строками
#include <random> // для генерации случайных чисел
#include <ctime> // для работы со временем
#include <clocale> // для установки русскокого языка
using namespace std;

// Класс блока питания
class PowerSupply {
public:
    void supplyPower(const string& device) {
        cout << "Блок питания: Подача питания на " << device << endl;
    }

    void stopPower(const string& device) {
        cout << "Блок питания: Отключение питания от " << device << endl;
    }

    void shutdown() {
        cout << "Блок питания: Выключение" << endl;
    }
};

// Класс датчиков
class Sensors {
private:
    bool checkRandomSuccess() {
        return rand() % 2 == 0; // 50% шанс успешной проверки
    }

public:
    void checkVoltage() {
        cout << "Датчики: Проверка напряжения - "
            << (checkRandomSuccess() ? "ОК" : "Предупреждение") << endl;
    }

    void checkTemperature(const string& component) {
        cout << "Датчики: Проверка температуры в " << component << " - "
            << (checkRandomSuccess() ? "ОК" : "Предупреждение") << endl;
    }
};

// Класс видеокарты
class VideoCard {
public:
    void start() {
        cout << "Видеокарта: Запуск" << endl;
    }

    void checkMonitorConnection() {
        cout << "Видеокарта: Проверка связи с монитором" << endl;
    }

    void displayMemoryData() {
        cout << "Видеокарта: Вывод данных об оперативной памяти" << endl;
    }

    void displayDriveData() {
        cout << "Видеокарта: Вывод данных об оптическом приводе" << endl;
    }

    void displayHDDData() {
        cout << "Видеокарта: Вывод данных о жестком диске" << endl;
    }

    void displayGoodbye() {
        cout << "Видеокарта: Вывод прощального сообщения" << endl;
    }
};

// Класс оперативной памяти
class RAM {
public:
    void start() {
        cout << "Оперативная память: Запуск" << endl;
    }

    void analyze() {
        cout << "Оперативная память: Анализ памяти" << endl;
    }

    void clear() {
        cout << "Оперативная память: Очистка памяти" << endl;
    }
};

// Класс оптического привода
class OpticalDrive {
public:
    void start() {
        cout << "Оптический привод: Запуск" << endl;
    }

    void checkDisk() {
        cout << "Оптический привод: Проверка наличия диска" << endl;
    }

    void resetPosition() {
        cout << "Оптический привод: Возврат в исходное положение" << endl;
    }
};

// Класс жесткого диска
class HDD {
public:
    void start() {
        cout << "Жесткий диск: Запуск" << endl;
    }

    void checkBootSector() {
        cout << "Жесткий диск: Проверка загрузочного сектора" << endl;
    }

    void stop() {
        cout << "Жесткий диск: Остановка" << endl;
    }
};

// Класс-фасад для управления компьютером
class ComputerFacade {
private:
    PowerSupply power;
    Sensors sensors;
    VideoCard video;
    RAM ram;
    OpticalDrive optical;
    HDD hdd;

public:
    ComputerFacade() {
        srand(time(0)); // Инициализация генератора случайных чисел
    }

    // Метод запуска компьютера
    void beginWork() {
        power.supplyPower("систему");
        sensors.checkVoltage();
        sensors.checkTemperature("блоке питания");
        sensors.checkTemperature("видеокарте");
        power.supplyPower("видеокарту");
        video.start();
        video.checkMonitorConnection();
        sensors.checkTemperature("оперативной памяти");
        power.supplyPower("оперативную память");
        ram.start();
        ram.analyze();
        video.displayMemoryData();
        power.supplyPower("оптический привод");
        optical.start();
        optical.checkDisk();
        video.displayDriveData();
        power.supplyPower("жесткий диск");
        hdd.start();
        hdd.checkBootSector();
        video.displayHDDData();
        sensors.checkTemperature("всех системах");
    }

    // Метод выключения компьютера
    void shutdown() {
        hdd.stop();
        ram.clear();
        ram.analyze();
        video.displayGoodbye();
        optical.resetPosition();
        power.stopPower("видеокарту");
        power.stopPower("оперативную память");
        power.stopPower("оптический привод");
        power.stopPower("жесткий диск");
        sensors.checkVoltage();
        power.shutdown();
    }
};

// Главная функция
int main() {
	setlocale(LC_ALL, "Russian"); // Установка русского языка

    ComputerFacade computer;

    cout << "Запуск компьютера..." << endl;
    computer.beginWork();

    cout << "\nВыключение компьютера..." << endl;
    computer.shutdown();

    return 0;
}