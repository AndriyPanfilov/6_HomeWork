#include "convertermodel.h"
#include <cmath>

ConverterModel::ConverterModel(QObject *parent)
    : QObject(parent),
    d_celsius(0.0),
    d_fahrenheit(32.0),
    d_kelvin(273.15)
{}

double ConverterModel::get_celsius()const{
    return this->d_celsius;
}

double ConverterModel::get_fahrenheit() const{
    return this->d_fahrenheit;
}
double ConverterModel:: get_kelvin() const{
    return this->d_kelvin;
}

void ConverterModel::set_celsius (double d_celsiusVal){
    if (qFuzzyCompare(d_celsiusVal + 1, d_celsius + 1)) return;
    d_celsius = d_celsiusVal;
    emit celsiusChanged();

    double newF = d_celsius * 9.0 / 5.0 + 32.0;
    double newK = d_celsius + 273.15;

    if (!qFuzzyCompare(newF + 1, d_fahrenheit + 1)) {
        d_fahrenheit = newF;
        emit fahrenheitChanged();
    }

    if (!qFuzzyCompare(newK + 1, d_kelvin + 1)) {
        d_kelvin = newK;
        emit kelvinChanged();
    }

}
void ConverterModel::set_fahrenheit(double d_fahrenheitVal){
    if (qFuzzyCompare(d_fahrenheitVal + 1, d_fahrenheit + 1)) return;
    d_fahrenheit = d_fahrenheitVal;
    emit fahrenheitChanged();

    double newC = (d_fahrenheit - 32.0) * 5.0 / 9.0;
    double newK = newC + 273.15;

    if (!qFuzzyCompare(newC + 1, d_celsius + 1)) {
        d_celsius = newC;
        emit celsiusChanged();
    }

    if (!qFuzzyCompare(newK + 1, d_kelvin + 1)) {
        d_kelvin = newK;
        emit kelvinChanged();
    }
}


void ConverterModel::set_kelvin(double d_kelvinVal){
    if (qFuzzyCompare(d_kelvinVal + 1, d_kelvin + 1)) return;
    d_kelvin = d_kelvinVal;
    emit kelvinChanged();

    double newC = d_kelvin - 273.15;
    double newF = newC * 9.0 / 5.0 + 32.0;

    if (!qFuzzyCompare(newC + 1, d_celsius + 1)) {
        d_celsius = newC;
        emit celsiusChanged();
    }

    if (!qFuzzyCompare(newF + 1, d_fahrenheit + 1)) {
        d_fahrenheit = newF;
        emit fahrenheitChanged();
    }
}
