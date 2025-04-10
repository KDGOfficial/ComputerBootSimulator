# ComputerBootSimulator

## Описание
Этот проект представляет собой симуляцию процесса загрузки и выключения компьютера, реализованную на языке C++ с использованием паттерна проектирования Façade. Программа моделирует работу основных компонентов компьютера (видеокарта, оперативная память, жесткий диск, оптический привод, блок питания и датчики) и их взаимодействие в строгой последовательности.

Проект был разработан студентом второго курса KDG  в рамках изучения объектно-ориентированного программирования и паттернов проектирования.

## Функциональность
- Симуляция процесса включения компьютера с последовательным запуском всех компонентов.
- Симуляция процесса выключения компьютера с корректным завершением работы устройств.
- Случайная генерация результатов проверок датчиков (50% шанс успеха/неуспеха) для реалистичности.
- Вывод сообщений о каждом действии в консоль на русском языке.
- Поддержка русской локализации через `setlocale`.

## Структура проекта
- **PowerSupply**: Управление питанием компонентов.
- **Sensors**: Проверка температуры и напряжения.
- **VideoCard**: Управление видеокартой и выводом информации.
- **RAM**: Работа с оперативной памятью.
- **OpticalDrive**: Управление оптическим приводом.
- **HDD**: Работа с жестким диском.
- **ComputerFacade**: Главный фасад, объединяющий работу всех компонентов.

## Установка и запуск
1. Склонируйте репозиторий:
   ```bash
   git clone https://github.com/username/ComputerBootSimulator.git
   ```
2. Скомпилируйте код с помощью компилятора C++ (например, g++):
   ```bash
   g++ main.cpp -o ComputerBootSimulator
   ```
3. Запустите программу:
   ```bash
   ./ComputerBootSimulator
   ```

## Требования
- Компилятор C++ (например, g++).
- Поддержка русской локали в системе для корректного отображения текста.

## Автор
Разработано студентом второго курса KDG в рамках учебного задания по ООП.

## Лицензия
Этот проект распространяется под лицензией MIT. Вы можете свободно использовать, изменять и распространять код при условии указания авторства.

```
MIT License

Copyright (c) 2025 KDG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

### Блок-схема


#### Блок-схема метода `beginWork` (Запуск компьютера):
```
[Начало]
    |
[Подача питания на систему]
    |
[Проверка напряжения]
    |
[Проверка температуры блока питания]
    |
[Проверка температуры видеокарты]
    |
[Подача питания на видеокарту]
    |
[Запуск видеокарты]
    |
[Проверка связи с монитором]
    |
[Проверка температуры RAM]
    |
[Подача питания на RAM]
    |
[Запуск RAM]
    |
[Анализ памяти]
    |
[Вывод данных о RAM]
    |
[Подача питания на оптический привод]
    |
[Запуск оптического привода]
    |
[Проверка наличия диска]
    |
[Вывод данных об оптическом приводе]
    |
[Подача питания на HDD]
    |
[Запуск HDD]
    |
[Проверка загрузочного сектора]
    |
[Вывод данных о HDD]
    |
[Проверка температуры всех систем]
    |
[Конец]
```

#### Блок-схема метода `shutdown` (Выключение компьютера):
```
[Начало]
    |
[Остановка HDD]
    |
[Очистка RAM]
    |
[Анализ памяти]
    |
[Вывод прощального сообщения]
    |
[Возврат оптического привода в исходное положение]
    |
[Отключение питания видеокарты]
    |
[Отключение питания RAM]
    |
[Отключение питания оптического привода]
    |
[Отключение питания HDD]
    |
[Проверка напряжения]
    |
[Выключение блока питания]
    |
[Конец]
```
