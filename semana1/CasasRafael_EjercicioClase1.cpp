#include <iostream>

class Triangle
{
    private:
        float a;
        float b;
        float c;

    public:
        Triangle()
        {
            a = 3;
            b = 4;
            c = 5;
        }
        float get_a()
        {
            return a;
        }
        void set_a( float a_param)
        {
            a = a_param;
        }
        float get_b()
        {
            return b;
        }
        void set_b( float b_param)
        {
            b = b_param;
        } 
        float get_c()
        {
            return c;
        }
        void set_c( float c_param)
        {
            c = c_param;
        }
        float perimeter()
        {
            return a+b+c;
        }
};

int main() {
    Triangle mario;
    float a_param2;
    std::cin >> a_param2;
    mario.set_a(a_param2);
    float b_param2;
    std::cin >> b_param2;
    mario.set_b(b_param2);
    float c_param2;
    std::cin >> c_param2;
    mario.set_c(c_param2);
    std::cout << mario.get_a() << std::endl << mario.get_b() << std::endl << mario.get_c() << std::endl;
    std::cout << "El perimetro es " <<  mario.perimeter();
    return 0;

};
