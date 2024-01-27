#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "fftw3.h"
#include "raylib.h"

#define DOT_SIZE 3.0
#define THICK_SIZE 1

int pinCount = 100;

Vector2 vecPosition(float _x, float _y) {
    float w = GetRenderWidth();
    float h = GetRenderHeight();
    return (Vector2){ .x = ((w / 20.0) * _x), .y = ((h / 20.0) * -_y) + h / 2 };
}

void drawPin(Vector2 _pin, Color _color) {
    Vector2 startPos = { _pin.x, GetRenderHeight() };
    Vector2 topPos = { _pin.x, 0 };
    // DrawLineEx(_pin, topPos, THICK_SIZE, GRAY);
    DrawLineEx(startPos, _pin, THICK_SIZE, _color);
    DrawCircleV(_pin, DOT_SIZE, _color);
}

int main(void) {
    InitWindow(1000, 200, "ray");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    // SetWindowState(FLAG_VSYNC_HINT);

    int n = pinCount;
    double* in = (double*)malloc(n * sizeof(double));
    // creo una funcion exponencial
    for(int i = 0; i < n; i++) { in[i] = 10; }

    fftw_complex* out = (fftw_complex*)fftw_malloc(20 * sizeof(fftw_complex));
    fftw_plan plan = fftw_plan_dft_r2c_1d(20, in, out, FFTW_ESTIMATE);
    fftw_execute(plan);

    for(int i = 0; i < n; i++) { printf("%f %f\n", out[i][0], out[i][1]); }

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        for(int i = 0; i < pinCount; i++) {
            float armonic = out[i][0];
            drawPin(vecPosition(((float)i + 20.0 / pinCount) * (20.0 / pinCount), 0), RED);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
