#include <iostream>
#include <fstream>
#include "Scene.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Please provide scene and camera files" << std::endl;
        return 1;
    }

    ReadScene(argc, argv);

    for (const auto& camera : CurrentScene->Cameras())
    {
        Image img = camera.Render();

        ///////////////////////
        // BEWARE !
        // RUN YOUR TESTS HERE!
        ///////////////////////

        std::ofstream out(camera.OutputFile());
        out << img;
    }


    return 0;
}