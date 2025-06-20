#ifndef CONVERTERMODEL_H
#define CONVERTERMODEL_H

#include <QObject>

class ConverterModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double d_celsius READ get_celsius WRITE set_celsius NOTIFY celsiusChanged FINAL)
    Q_PROPERTY(double d_fahrenheit READ get_fahrenheit WRITE set_fahrenheit NOTIFY fahrenheitChanged FINAL)
    Q_PROPERTY(double d_kelvin READ get_kelvin  WRITE set_kelvin NOTIFY kelvinChanged FINAL)


public:
    explicit ConverterModel(QObject *parent = nullptr);
    double get_celsius() const;
    double get_fahrenheit() const;
    double get_kelvin() const;

    void set_celsius (double d_celsiusVal);
    void set_fahrenheit(double d_fahrenheitVal);
    void set_kelvin(double d_kelvinVal);

signals:

    void celsiusChanged();
    void fahrenheitChanged ();
    void kelvinChanged ();

private:
    double d_celsius;
    double d_fahrenheit;
    double d_kelvin;

};

#endif // CONVERTERMODEL_H
