#include "StudentExpenses.h"

StudentExpenses::StudentExpenses(Student& student, fileData& costs, fileData& institute,
                fileData& transport, fileData& cafeCinema) {
    findCosts(student, costs);
    findInstitute(student, institute);
    findTransport(student, transport);
    findCafeCinema(student, cafeCinema);
}

bool StudentExpenses::checkColumnsNum(fileData& data, int n) const {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].size() != n) {
            return false;
        }
    }
    return true;
}

bool StudentExpenses::costsFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Age,Average food cost per month,Other costs") {
        return checkColumnsNum(data, 4);
    }
    return false;
}

bool StudentExpenses::instituteFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Institute,Dinner cost") {
        return checkColumnsNum(data, 3);
    }
    return false;
}

bool StudentExpenses::transportFileCheck(fileData& data) {
    if (data[0].join(",") == "City,District,Institute,Transport cost") {
        return checkColumnsNum(data, 4);
    }
    return false;
}

bool StudentExpenses::cafeCinemaFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Address,Caffe,Average caffe cost,Cinema,Cinema cost") {
        return checkColumnsNum(data, 6);
    }
    return false;
}

void StudentExpenses::findCosts(Student& student, fileData& data) {
    bool find = false;
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), QString::number(student._age)) != data[i].end()) {
            find = true;
            _avgFoodCost = data[i][2].toInt();
            _otherCost = data[i][3].toInt();
        }
    }
    if (!find) {
        errors.push_back("Costs file error.");
    }
}

void StudentExpenses::findInstitute(Student &student, fileData& data) {
    bool find = false;
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            find = true;
            _instituteFoodCost = data[i][2].toInt();
        }
    }
    if (!find) {
        errors.push_back("Institute file error.");
    }
}

void StudentExpenses::findTransport(Student& student, fileData& data) {
    bool find = false;
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            find = true;
            _transportCost = data[i][3].toInt();
        }
    }
    if (!find) {
        errors.push_back("Transport file error.");
    }
}

void StudentExpenses::findCafeCinema(Student &student, fileData& data) {
    bool find = false;
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._cafe) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._cinema) != data[i].end()) {
            find = true;
            _cafeCost = data[i][3].toInt();
            _cinemaCost = data[i][5].toInt();
        }
    }
    if (!find) {
        errors.push_back("Cinema file error.");
    }
}