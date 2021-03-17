# coding=UTF-8
def celsiusToFahrenheit(Celsius):
    Fahrenheit = 9/5*Celsius+32
    return Fahrenheit


def fahrenheitToCelsius(Fahrenheit):
    celsius = 5/9*(Fahrenheit-32)
    return celsius


print("Celsius", "Fahrenheit", "|", "Fahrenheit", "Celsius", sep="\t")
for i in range(0, 10):
    print("%.2f" % (40-i), "%.2f" % (celsiusToFahrenheit(40-i)), "|",
          120-10*i, "%.2f" % fahrenheitToCelsius(120-10*i), sep="\t")
