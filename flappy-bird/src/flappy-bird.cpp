#include <iostream>
#include <core/engine.h>
#include <core/scene.h>
#include <custom_monobehaviour.h>
#include <../temp/MyExportedClass.h>

int main()
{
    //Gameobject go ;
    size_t i = 1;
    CustomMonobehaviour m{i};

    /*MyExportedClass aaa{};
    aaa.Test<MyExportedClass>();
    aaa.Pa();
    MyExportedClass::Test<MyExportedClass>();

    Vector2 v{0,0};
    Scene s;*/
    Engine a;

    std::cout << "Hello World!" << std::endl;
    system("pause");
}