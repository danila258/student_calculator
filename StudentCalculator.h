#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include "Database.h"
#include "Student.h"
#include "StudentExpenses.h"
#include "FileEditWidget.h"

#include <QtWidgets>
#include <QApplication>
#include <string>
#include <QString>
using std::string;

#define countCheckedFields 10
#define ageByDefault 18


class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    explicit StudentCalculator(QWidget* parent = nullptr);
    ~StudentCalculator() override;

private slots:

    void ageEdited(int age);
    void regulateAgeSpinBox(int mode);

    void monthEdited(int month);
    void nameEdited(const QString& name);
    void cityEdited(const QString& city);
    void addressEdited(const QString& address);
    void instituteEdited(const QString& institute);
    void cinemaEdited(const QString& cinema);
    void caffeEdited(const QString& caffe);

    void costsFileDialog();
    void instituteFileDialog();
    void transportFileDialog();
    void otherCostsFileDialog();

    void editCostsFile();
    void editInstituteFile();
    void editTransportFile();
    void editCaffeCinemaFile();

    void startCalculate();
    
private:
    Database _database;

    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QTabWidget* tabWidget();
    QPushButton* calculateButton();

    void updateCalculateButton();

    void errorDataLoadShow(const QVector<QString>& dataLoudErrors);
    void studentMoneyShow(int sum);
    bool fileEditWidgetShow (const QStringList& headerLabels, std::vector< std::vector<string> >& _file);

    QSpinBox* _ageSpinBox;

    QPushButton* _buttonEditCostsFile;
    QPushButton* _buttonEditInstituteFile;
    QPushButton* _buttonEditTransportFile;
    QPushButton* _buttonEditOtherCostsFile;

    QPushButton* _calculateButton;

    int _age;
    int _month;

    string _name;
    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _cafe;

    std::vector<bool> _completeFieldsArr;

    bool _calculateAgeFlag = true;
};


#endif //STUDENTCALCULATOR_H