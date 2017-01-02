#include <iostream>
#include <fstream>
#include "Scene.h"

int main(int argc, char** argv)
{
    Scene test;

    if (argc < 2)
    {
        std::cout << "Please provide scene and camera files" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    std::ifstream cams(argv[2]);

    file >> test;
    test.AddCameras(cams);

    for (const auto& camera : test.Cameras())
    {
        auto img = camera.Render();

        std::ofstream out(camera.OutputFile());
        out << img;
    }

    return 0;
}
