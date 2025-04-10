//GitHub ����� �������:https://github.com/KDGOfficial/ComputerBootSimulator
#include <iostream> // ��� ������ � �������
#include <string> // ��� ������ �� ��������
#include <random> // ��� ��������� ��������� �����
#include <ctime> // ��� ������ �� ��������
#include <clocale> // ��� ��������� ���������� �����
using namespace std;

// ����� ����� �������
class PowerSupply {
public:
    void supplyPower(const string& device) {
        cout << "���� �������: ������ ������� �� " << device << endl;
    }

    void stopPower(const string& device) {
        cout << "���� �������: ���������� ������� �� " << device << endl;
    }

    void shutdown() {
        cout << "���� �������: ����������" << endl;
    }
};

// ����� ��������
class Sensors {
private:
    bool checkRandomSuccess() {
        return rand() % 2 == 0; // 50% ���� �������� ��������
    }

public:
    void checkVoltage() {
        cout << "�������: �������� ���������� - "
            << (checkRandomSuccess() ? "��" : "��������������") << endl;
    }

    void checkTemperature(const string& component) {
        cout << "�������: �������� ����������� � " << component << " - "
            << (checkRandomSuccess() ? "��" : "��������������") << endl;
    }
};

// ����� ����������
class VideoCard {
public:
    void start() {
        cout << "����������: ������" << endl;
    }

    void checkMonitorConnection() {
        cout << "����������: �������� ����� � ���������" << endl;
    }

    void displayMemoryData() {
        cout << "����������: ����� ������ �� ����������� ������" << endl;
    }

    void displayDriveData() {
        cout << "����������: ����� ������ �� ���������� �������" << endl;
    }

    void displayHDDData() {
        cout << "����������: ����� ������ � ������� �����" << endl;
    }

    void displayGoodbye() {
        cout << "����������: ����� ����������� ���������" << endl;
    }
};

// ����� ����������� ������
class RAM {
public:
    void start() {
        cout << "����������� ������: ������" << endl;
    }

    void analyze() {
        cout << "����������� ������: ������ ������" << endl;
    }

    void clear() {
        cout << "����������� ������: ������� ������" << endl;
    }
};

// ����� ����������� �������
class OpticalDrive {
public:
    void start() {
        cout << "���������� ������: ������" << endl;
    }

    void checkDisk() {
        cout << "���������� ������: �������� ������� �����" << endl;
    }

    void resetPosition() {
        cout << "���������� ������: ������� � �������� ���������" << endl;
    }
};

// ����� �������� �����
class HDD {
public:
    void start() {
        cout << "������� ����: ������" << endl;
    }

    void checkBootSector() {
        cout << "������� ����: �������� ������������ �������" << endl;
    }

    void stop() {
        cout << "������� ����: ���������" << endl;
    }
};

// �����-����� ��� ���������� �����������
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
        srand(time(0)); // ������������� ���������� ��������� �����
    }

    // ����� ������� ����������
    void beginWork() {
        power.supplyPower("�������");
        sensors.checkVoltage();
        sensors.checkTemperature("����� �������");
        sensors.checkTemperature("����������");
        power.supplyPower("����������");
        video.start();
        video.checkMonitorConnection();
        sensors.checkTemperature("����������� ������");
        power.supplyPower("����������� ������");
        ram.start();
        ram.analyze();
        video.displayMemoryData();
        power.supplyPower("���������� ������");
        optical.start();
        optical.checkDisk();
        video.displayDriveData();
        power.supplyPower("������� ����");
        hdd.start();
        hdd.checkBootSector();
        video.displayHDDData();
        sensors.checkTemperature("���� ��������");
    }

    // ����� ���������� ����������
    void shutdown() {
        hdd.stop();
        ram.clear();
        ram.analyze();
        video.displayGoodbye();
        optical.resetPosition();
        power.stopPower("����������");
        power.stopPower("����������� ������");
        power.stopPower("���������� ������");
        power.stopPower("������� ����");
        sensors.checkVoltage();
        power.shutdown();
    }
};

// ������� �������
int main() {
	setlocale(LC_ALL, "Russian"); // ��������� �������� �����

    ComputerFacade computer;

    cout << "������ ����������..." << endl;
    computer.beginWork();

    cout << "\n���������� ����������..." << endl;
    computer.shutdown();

    return 0;
}