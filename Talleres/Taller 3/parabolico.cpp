
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#define g 10.0
#define m 1
#define b 0.2

using namespace std;

double fvx(double vx){
    return (-b) * vx/m;
    }

double fvy(double vy){
    return -g - (b / m) * vy;
    }

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
    
    double x = x_init;
    double y = y_init;
    double vx = vx_init;
    double vy = vx_init;    
    
    
    double pos_x1[N];
    double pos_y1[N];
    
    double k1x;
    double k1y;
    double l1x;
    double l1y;
    

    double k2x;
    double k2y;
    double l2x;
    double l2y;
    
    double k3x;
    double k3y;
    double l3x;
    double l3y;
    
    double k4x;
    double k4y;
    double l4x;
    double l4y;
    
    for (int i = 0; i < N; i++){
        
        // Método de Runge-Kutta de cuarto orden para actualizar las variables
        k1x = dt * vx;
        k1y = dt * vy;
        l1x = dt * (-b*vx/m);
        l1y = dt * (-g -(b/m)*vy);
        
        k2x = dt * (vx+(1/2)*l1x);
        k2y = dt * (vy+(1/2)*l1y);
        l2x = dt * (-b * k2x/(dt*m));
        l2y = dt * ((-b * k2y/(dt*m)) -g);
        
        k3x = dt * (vx+(1/2)*dt*l2x);
        k3y = dt * (vy+(1/2)*dt*l2y);
        l3x = dt * (-b * k3x/(dt*m));
        l3y = dt * ((-b * k3y/(dt*m)) -g);
        
        k4x = dt * (vx+dt*l3x);
        k4y = dt * (vy+dt*l3y);
        l4x = dt * (-b * k4x/(dt*m));
        l4y = dt * ((-b * k4y/(dt*m)) -g);

        vx += (1.0 / 6.0) * (l1x + 2 * l2x + 2 * l3x + l4x);
        vy += (1.0 / 6.0) * (l1y + 2 * l2y + 2 * l3y + l4y);
        x +=  (1.0 / 6.0) * (k1x + 2 * k2x + 2 * k3x + k4x);
        y +=  (1.0 / 6.0) * (k1y + 2 * k2y + 2 * k3y + k4y);
        
        pos_x1[i] = x;
        pos_y1[i] = y;
    }


    std::ofstream myfile2;
    myfile2.open ("x_values_with_friccion.csv");
    myfile2 << "x,y\n";
    for(int i = 0; i <N; i++){
        myfile2 << pos_x1[i] << ",";
        myfile2 << pos_y1[i] << "\n";
    }
    myfile2.close();
    
    return 0;
    
}


