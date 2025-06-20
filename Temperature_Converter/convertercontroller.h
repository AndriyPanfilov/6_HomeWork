#ifndef CONVERTERCONTROLLER_H
#define CONVERTERCONTROLLER_H

#include <QObject>
#include"convertermodel.h"

class ConverterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool celsiusValid READ celsiusValid NOTIFY celsiusValidationChanged)
    Q_PROPERTY(bool kelvinValid READ kelvinValid NOTIFY kelvinValidationChanged)
    Q_PROPERTY(bool fahrenheitValid READ fahrenheitValid NOTIFY fahrenheitValidationChanged)

    Q_PROPERTY(double d_celsius READ get_celsius NOTIFY celsiusChanged)
    Q_PROPERTY(double d_fahrenheit READ get_fahrenheit NOTIFY fahrenheitChanged)
    Q_PROPERTY(double d_kelvin READ get_kelvin NOTIFY kelvinChanged)


public:
    explicit ConverterController(ConverterModel*model, QObject *parent = nullptr);

    Q_INVOKABLE void updateCelsius(const QString &Strvalue);
    Q_INVOKABLE void updateFahrenheit(const QString&Strvalue);
    Q_INVOKABLE void updateKelvin(const QString &Strvalue);

    double get_celsius() const;
    double get_fahrenheit() const;
    double get_kelvin() const;


    bool celsiusValid() const {return celsiusOK;}
    bool fahrenheitValid() const {return fahrenheitOK;}
    bool kelvinValid() const { return kelvinOK;}


signals:

    void celsiusChanged();
    void fahrenheitChanged();
    void kelvinChanged();

    void celsiusValidationChanged(bool isValid);
    void fahrenheitValidationChanged(bool isValid);
    void kelvinValidationChanged (bool isValid);


private:
    ConverterModel* model;
    bool celsiusOK=true;
    bool kelvinOK=true;
    bool fahrenheitOK=true;


};

#endif // CONVERTERCONTROLLER_H
