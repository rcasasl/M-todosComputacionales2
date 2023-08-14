#include <iostream>

class Student
{
    private:
        int age;


    public:
        Student()
        {
            age = 24;
        }
        int get_age()
        {
            return age;
        }
        void set_age(int age_param)
        {
            age = age_param;
        }
};

int main() {
    Student mario;
    std::cout << mario.get_age();
    return 0;
}
