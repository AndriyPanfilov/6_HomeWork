#include "convertercontroller.h"

ConverterController::ConverterController(ConverterModel *model, QObject *parent)
    : QObject(parent), model(model)
{
    // Підключаємо сигнали моделі до сигналів контролера, щоб QML отримував оновлення
    connect(model, &ConverterModel::celsiusChanged, this, &ConverterController::celsiusChanged);
    connect(model, &ConverterModel::fahrenheitChanged, this, &ConverterController::fahrenheitChanged);
    connect(model, &ConverterModel::kelvinChanged, this, &ConverterController::kelvinChanged);
}

void ConverterController::updateCelsius(const QString &QStrCelsius){

    if (QStrCelsius.trimmed().isEmpty()) {
        // Порожнє поле вважається валідним
        celsiusOK = true;
        emit celsiusValidationChanged(celsiusOK);
        return;
    }
    bool ok;
    double d_celsius = QStrCelsius.toDouble(&ok);
    if(ok && d_celsius >= -273.15){
        model->set_celsius(d_celsius);
        if(!celsiusOK ){
            celsiusOK=true;
            emit celsiusValidationChanged(celsiusOK);
        }
    }
    else{
        if(celsiusOK){
            celsiusOK=false;
            emit celsiusValidationChanged(celsiusOK);
        }
    }
}

void ConverterController::updateFahrenheit(const QString &QStrFarh){

    if (QStrFarh.trimmed().isEmpty()) {

        fahrenheitOK = true;
        emit fahrenheitValidationChanged(fahrenheitOK);
        return;
    }
    bool ok;
    double d_fahrenheit=QStrFarh.toDouble(&ok);

    if(ok && d_fahrenheit >= -459.67){
        model->set_fahrenheit(d_fahrenheit);
        if(!fahrenheitOK){
            fahrenheitOK=true;
            emit fahrenheitValidationChanged(fahrenheitOK);
        }
    }
    else{
        if(fahrenheitOK){
            fahrenheitOK=false;
            emit fahrenheitValidationChanged(fahrenheitOK);
        }

    }
}

void ConverterController::updateKelvin(const QString &QStrKelvin) {

    if (QStrKelvin.trimmed().isEmpty()) {

        kelvinOK = true;
        emit kelvinValidationChanged(kelvinOK);
        return;
    }

    bool ok;
    double d_kelvinVal = QStrKelvin.toDouble(&ok);

    if (ok && d_kelvinVal >=0) {
         model->set_kelvin(d_kelvinVal);
        if (!kelvinOK) {
            kelvinOK = true;
            emit kelvinValidationChanged(kelvinOK);
        }

    } else {
        if (kelvinOK) {
            kelvinOK = false;
            emit kelvinValidationChanged(kelvinOK);
        }
    }
}

double ConverterController::get_celsius() const {
    return model->get_celsius();
}

double ConverterController::get_fahrenheit() const {
    return model->get_fahrenheit();
}

double ConverterController::get_kelvin() const {
    return model->get_kelvin();
}
