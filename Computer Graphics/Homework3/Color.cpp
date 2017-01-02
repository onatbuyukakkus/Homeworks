#include "Color.h"
#include <algorithm>


Color::Color()
{
    _channels[0] = _channels[1] = _channels[2] = 0;
}

Color::Color(float r, float g, float b) {
    _channels[0] = std::max(0.0f, std::min(255.0f, r));
    _channels[1] = std::max(0.0f, std::min(255.0f, g));
    _channels[2] = std::max(0.0f, std::min(255.0f, b));
}

std::istream &operator>>(std::istream &stream, Color &color) {
    return stream >> color._channels[0] >> color._channels[1] >> color._channels[2];
}

void Color::Clamp()
{
    for (int i = 0; i < 3; ++i) {
        _channels[i] = std::max(0.0f, std::min(255.0f, _channels[i]));
    }
}
