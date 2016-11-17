#include "rgb.h"

#include <stdio.h>

double hue2rgb(double p, double q, double t) {
    if(t < 0) t += 1;
    if(t > 1) t -= 1;
    if(t < 1/6.0) return p + (q - p) * 6 * t;
    if(t < 1/2.0) return q;
    if(t < 2/3.0) return p + (q - p) * (2/3.0 - t) * 6;
    return p;
}

void hslToRgb(double h, double s, double l, unsigned char* rgbColor) {
    double r, g, b;

    if (s == 0) {
        r = g = b = l; // achromatic
    } else {
        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;
        r = hue2rgb(p, q, h + 1/3.0);
        g = hue2rgb(p, q, h);
        b = hue2rgb(p, q, h - 1/3.0);
    }

    rgbColor[0] = (unsigned char)(r * 255);
    rgbColor[1] = (unsigned char)(g * 255);
    rgbColor[2] = (unsigned char)(b * 255);
}