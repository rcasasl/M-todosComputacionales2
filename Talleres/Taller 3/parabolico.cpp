
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#define g 10.0
#define m 1
#define b 0.2

using namespace std;

double fvx(double vx[]);
double fvy(double vy[]);

int main() {
    float x_init = 0;
    float y_init = 10;
    float vx_init = 10;
    float vy_init = 10;

    float dt = 0.01;
    float t_total = 2.733;
    cout << "total_time:" <<  t_total << endl;
    int N = t_total/dt;
    cout << N;

    double pos_x[N];
    double pos_y[N];

    for(int i = 0; i <N; i++){
        pos_x[i] = vx_init*i*dt;
        pos_y[i] = y_init + vy_init*i*dt - 0.5*g*pow(i*dt, 2);
    }

    for(int i = 0; i <N; i++){
        cout << pos_x[i] << " ";
        cout << pos_y[i] << " ";
    }

    std::ofstream myfile;
    myfile.open ("x_values.csv");
    myfile << "x,y\n";
    for(int i = 0; i <N; i++){
        myfile << pos_x[i] << ",";
        myfile << pos_y[i] << "\n";
    }
    myfile.close();

    // su codigo aqui
    
    double vx[N];
    double vy[N];    
    double x[N];
    double y[N];
    double pos_x1[N];
    double pos_y1[N];

    for (int i = 0; i < N; i++){
        
        // Método de Runge-Kutta de cuarto orden para actualizar las variables
        double k1x = dt * vx_init;
        double k1y = dt * vy_init;
        double l1x = dt * fvx(vx);
        double l1y = dt * fvy(vy);
        
        double k2x = dt * (vx_init+(1/2)*l1x);
        double k2y = dt * (vy_init+(1/2)*l1y);
        double l2x = dt * fvx(vx+(1/2)*k1x);
        double l2y = dt * fvy(vy+(1/2)*k1y);
        
        double k3x = dt * (vx_init+(1/2)*l2x);
        double k3y = dt * (vy_init+(1/2)*l2y);
        double l3x = dt * fvx(vx+(1/2)*k2x);
        double l3y = dt * fvy(vy+(1/2)*k2y);
        
        double k4x = dt * (vx_init+l3x);
        double k4y = dt * (vy_init+l3y);
        double l4x = dt * fvx(vx+k3x);
        double l4y = dt * fvy(vy+k3y);

        pos_x1[i] = x_init + (1.0 / 6.0) * (k1x + 2 * k2x + 2 * k3x + k4x)*i;
        pos_y1[i] = y_init + (1.0 / 6.0) * (k1y + 2 * k2y + 2 * k3y + k4y)*i;
        vx[i] = vx_init + (1.0 / 6.0) * (l1x + 2 * l2x + 2 * l3x + l4x)*i;
        vy[i] = vy_init + (1.0 / 6.0) * (l1y + 2 * l2y + 2 * l3y + l4y)*i;
    }

     for(int i = 0; i <N; i++){
        cout << x[i] << " ";
        cout << y[i] << " ";
        cout << vx[i] << " ";
        cout << vy[i] << " ";
    }
    std::ofstream myfile2;
    myfile2.open ("x_values_with_friccion.csv");
    myfile2 << "x,vx,vy,y\n";
    for(int i = 0; i <N; i++){
        myfile2 << x[i] << ",";
        myfile2 << vx[i] << ",";
        myfile2 << vy[i] << ",";
        myfile2 << y[i] << "\n";
    }
    myfile2.close();
    
    return 0;
    
}

double fvx(double vx[]){
    return (-b) * vx;
    }

double fvy(double vy[]){
    return -g - (b / m) * vy;
    }
